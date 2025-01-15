#include "AudioManager.h"
#include <iostream>
#include <SFML/System/Sleep.hpp> // For sf::sleep

AudioManager::AudioManager()
    : globalVolume(100.0f), isMuted(false), currentTrackIndex(0) {}

AudioManager::~AudioManager() {
    stopBackgroundMusic();
    stopAllSoundEffects();
}

void AudioManager::playBackgroundMusic(const std::string& filepath, bool loop) {
    if (!backgroundMusic.openFromFile(filepath)) {
        std::cerr << "Error: Unable to load background music from " << filepath << "\n";
        return;
    }
    backgroundMusic.setLoop(loop);
    backgroundMusic.setVolume(globalVolume);
    backgroundMusic.play();
}

void AudioManager::playBackgroundMusicPlaylist(const std::vector<std::string>& filepaths) {
    playlist = filepaths;
    currentTrackIndex = 0;
    playNextTrackInPlaylist();
}

void AudioManager::playNextTrackInPlaylist() {
    if (currentTrackIndex >= playlist.size()) {
        return; // End of playlist
    }
    if (!backgroundMusic.openFromFile(playlist[currentTrackIndex])) {
        std::cerr << "Error: Unable to load track " << playlist[currentTrackIndex] << "\n";
        return;
    }
    backgroundMusic.setLoop(false);
    backgroundMusic.setVolume(globalVolume);
    backgroundMusic.play();

    while (backgroundMusic.getStatus() != sf::Music::Stopped) {
        sf::sleep(sf::milliseconds(100));
    }

    currentTrackIndex++;
    playNextTrackInPlaylist();
}

void AudioManager::stopBackgroundMusic() {
    backgroundMusic.stop();
}

void AudioManager::pauseBackgroundMusic() {
    backgroundMusic.pause();
}

void AudioManager::resumeBackgroundMusic() {
    if (backgroundMusic.getStatus() == sf::Music::Paused) {
        backgroundMusic.play();
    }
}

void AudioManager::setBackgroundMusicVolume(float volume) {
    backgroundMusic.setVolume(volume);
}

sf::Music::Status AudioManager::getBackgroundMusicStatus() const {
    return backgroundMusic.getStatus();
}

void AudioManager::fadeInBackgroundMusic(float targetVolume, float duration) {
    float currentVolume = 0.0f;
    backgroundMusic.setVolume(currentVolume);
    backgroundMusic.play();
    float increment = targetVolume / (duration * 10);
    while (currentVolume < targetVolume) {
        currentVolume += increment;
        backgroundMusic.setVolume(currentVolume);
        sf::sleep(sf::milliseconds(100));
    }
}

void AudioManager::fadeOutBackgroundMusic(float duration) {
    float currentVolume = backgroundMusic.getVolume();
    float decrement = currentVolume / (duration * 10);
    while (currentVolume > 0.0f) {
        currentVolume -= decrement;
        backgroundMusic.setVolume(currentVolume);
        sf::sleep(sf::milliseconds(100));
    }
    backgroundMusic.stop();
}

void AudioManager::loadSoundEffect(const std::string& id, const std::string& filepath) {
    if (soundBuffers.find(id) != soundBuffers.end()) {
        std::cerr << "Warning: Sound effect with ID " << id << " already loaded.\n";
        return;
    }

    sf::SoundBuffer buffer;
    loadFileToBuffer(filepath, buffer);

    soundBuffers[id] = buffer;
    sf::Sound sound;
    sound.setBuffer(soundBuffers[id]);
    soundEffects[id] = sound;
}

void AudioManager::playSoundEffect(const std::string& id, float pitch, float relativeVolume) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPitch(pitch);
        it->second.setVolume(relativeVolume);
        it->second.play();
    } else {
        std::cerr << "Error: Sound effect with ID " << id << " not found.\n";
    }
}

void AudioManager::stopAllSoundEffects() {
    for (auto& [id, sound] : soundEffects) {
        sound.stop();
    }
}

void AudioManager::setSoundEffectVolume(float volume) {
    for (auto& [id, sound] : soundEffects) {
        sound.setVolume(volume);
    }
}

void AudioManager::setSoundEffectPosition(const std::string& id, float x, float y, float z) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPosition(x, y, z);
    } else {
        std::cerr << "Error: Sound effect with ID " << id << " not found.\n";
    }
}

bool AudioManager::isSoundEffectPlaying(const std::string& id) const {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        return it->second.getStatus() == sf::Sound::Playing;
    }
    return false;
}

void AudioManager::setGlobalVolume(float volume) {
    globalVolume = volume;
    backgroundMusic.setVolume(volume);
    setSoundEffectVolume(volume);
}

float AudioManager::getGlobalVolume() const {
    return globalVolume;
}

void AudioManager::resetVolume() {
    setGlobalVolume(100.0f);
}

void AudioManager::mute() {
    if (!isMuted) {
        globalVolume = backgroundMusic.getVolume();
        backgroundMusic.setVolume(0.0f);
        setSoundEffectVolume(0.0f);
        isMuted = true;
    }
}

void AudioManager::unmute() {
    if (isMuted) {
        backgroundMusic.setVolume(globalVolume);
        setSoundEffectVolume(globalVolume);
        isMuted = false;
    }
}

void AudioManager::loadFileToBuffer(const std::string& filepath, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filepath)) {
        std::cerr << "Error: Unable to load sound buffer from " << filepath << "\n";
    }
}