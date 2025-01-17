#include "AudioManager.h"
#include <iostream>
#include <SFML/System/Sleep.hpp>

AudioManager::AudioManager()
    : globalVolume(100.0f), isMutedFlag(false), currentTrackIndex(0), loopPlaylist(false) {}

AudioManager::~AudioManager() {
    stopBackgroundMusic();
    stopAllSoundEffects();
}

void AudioManager::playBackgroundMusic(const std::string& filepath, bool loop) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!backgroundMusic.openFromFile(filepath)) {
        std::cerr << "Error: Unable to load background music from " << filepath << "\n";
        return;
    }
    backgroundMusic.setLoop(loop);
    backgroundMusic.setVolume(isMutedFlag ? 0.0f : globalVolume);
    backgroundMusic.play();
}

void AudioManager::playBackgroundMusicPlaylist(const std::vector<std::string>& filepaths, bool loopPlaylist) {
    std::lock_guard<std::mutex> lock(mutex);
    if (filepaths.empty()) {
        std::cerr << "Error: Playlist is empty.\n";
        return;
    }
    playlist = filepaths;
    currentTrackIndex = 0;
    this->loopPlaylist = loopPlaylist;
    handlePlaylistPlayback();
}

void AudioManager::playNextTrackInPlaylist() {
    std::lock_guard<std::mutex> lock(mutex);
    if (playlist.empty()) return;

    currentTrackIndex = (currentTrackIndex + 1) % playlist.size();
    if (!loopPlaylist && currentTrackIndex == 0) return;
    playBackgroundMusic(playlist[currentTrackIndex], false);
    handlePlaylistPlayback();
}

void AudioManager::playPreviousTrackInPlaylist() {
    std::lock_guard<std::mutex> lock(mutex);
    if (playlist.empty()) return;

    currentTrackIndex = (currentTrackIndex == 0) ? playlist.size() - 1 : currentTrackIndex - 1;
    playBackgroundMusic(playlist[currentTrackIndex], false);
}

void AudioManager::handlePlaylistPlayback() {
    std::thread([this] {
        while (backgroundMusic.getStatus() == sf::Music::Playing) {
            sf::sleep(sf::milliseconds(100));
        }
        playNextTrackInPlaylist();
    }).detach();
}

void AudioManager::stopBackgroundMusic() {
    std::lock_guard<std::mutex> lock(mutex);
    backgroundMusic.stop();
}

void AudioManager::setBackgroundMusicVolume(float volume) {
    std::lock_guard<std::mutex> lock(mutex);
    if (volume < 0.0f || volume > 100.0f) {
        std::cerr << "Error: Volume out of range (0.0 - 100.0)\n";
        return;
    }
    globalVolume = volume;
    applyGlobalVolume();
}

bool AudioManager::isBackgroundMusicPlaying() const {
    std::lock_guard<std::mutex> lock(mutex);
    return backgroundMusic.getStatus() == sf::Music::Playing;
}

void AudioManager::loadSoundEffect(const std::string& id, const std::string& filepath) {
    std::lock_guard<std::mutex> lock(mutex);
    if (soundBuffers.count(id)) {
        std::cerr << "Warning: Sound effect with ID " << id << " already loaded.\n";
        return;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filepath)) {
        std::cerr << "Error: Unable to load sound buffer from " << filepath << "\n";
        return;
    }
    soundBuffers[id] = std::move(buffer);
    soundEffects[id].setBuffer(soundBuffers[id]);
}

void AudioManager::playSoundEffect(const std::string& id, float pitch, float relativeVolume) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPitch(pitch);
        it->second.setVolume((isMutedFlag ? 0.0f : globalVolume) * (relativeVolume / 100.0f));
        it->second.play();
    } else {
        std::cerr << "Error: Sound effect with ID " << id << " not found.\n";
    }
}

void AudioManager::stopAllSoundEffects() {
    std::lock_guard<std::mutex> lock(mutex);
    for (auto& [id, sound] : soundEffects) {
        sound.stop();
    }
}

bool AudioManager::isSoundEffectPlaying(const std::string& id) const {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = soundEffects.find(id);
    return it != soundEffects.end() && it->second.getStatus() == sf::Sound::Playing;
}

void AudioManager::playSoundEffectWithDelay(const std::string& id, float delay) {
    if (delay < 0.0f) {
        std::cerr << "Error: Delay cannot be negative.\n";
        return;
    }
    std::thread([this, id, delay] {
        sf::sleep(sf::seconds(delay));
        playSoundEffect(id);
    }).detach();
}

void AudioManager::playSequentialSoundEffects(const std::vector<std::string>& ids) {
    if (ids.empty()) {
        std::cerr << "Error: Sound effect sequence is empty.\n";
        return;
    }
    std::thread([this, ids] {
        for (const auto& id : ids) {
            playSoundEffect(id);
            while (isSoundEffectPlaying(id)) {
                sf::sleep(sf::milliseconds(100));
            }
        }
    }).detach();
}

void AudioManager::mute() {
    std::lock_guard<std::mutex> lock(mutex);
    isMutedFlag = true;
    applyGlobalVolume();
}

void AudioManager::unmute() {
    std::lock_guard<std::mutex> lock(mutex);
    isMutedFlag = false;
    applyGlobalVolume();
}

bool AudioManager::isMuted() const {
    std::lock_guard<std::mutex> lock(mutex);
    return isMutedFlag;
}

void AudioManager::applyGlobalVolume() {
    backgroundMusic.setVolume(isMutedFlag ? 0.0f : globalVolume);
    for (auto& [id, sound] : soundEffects) {
        sound.setVolume(isMutedFlag ? 0.0f : globalVolume);
    }
}
