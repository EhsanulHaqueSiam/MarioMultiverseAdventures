#include "AudioManager.h"
#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <thread>

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
        return;
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
    if (volume < 0.0f || volume > 100.0f) {
        std::cerr << "Error: Volume out of range (0.0 - 100.0)\n";
        return;
    }
    globalVolume = volume;
    backgroundMusic.setVolume(volume);
}

sf::Music::Status AudioManager::getBackgroundMusicStatus() const {
    return backgroundMusic.getStatus();
}

void AudioManager::fadeInBackgroundMusic(float targetVolume, float duration) {
    float currentVolume = 0.0f;
    backgroundMusic.setVolume(currentVolume);
    backgroundMusic.play();
    float increment = (targetVolume - currentVolume) / (duration * 10);
    while (currentVolume < targetVolume) {
        currentVolume += increment;
        backgroundMusic.setVolume(currentVolume);
        sf::sleep(sf::milliseconds(100));
    }
}

void AudioManager::fadeOutBackgroundMusic(float targetVolume, float duration) {
    float currentVolume = backgroundMusic.getVolume();
    float decrement = (currentVolume - targetVolume) / (duration * 10);
    while (currentVolume > targetVolume) {
        currentVolume -= decrement;
        backgroundMusic.setVolume(currentVolume);
        sf::sleep(sf::milliseconds(100));
    }
    backgroundMusic.stop();
}

void AudioManager::loadSoundEffect(const std::string& id, const std::string& filepath) {
    if (soundBuffers.contains(id)) {
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
    if (volume < 0.0f || volume > 100.0f) {
        std::cerr << "Error: Volume out of range (0.0 - 100.0)\n";
        return;
    }
    for (auto& [id, sound] : soundEffects) {
        sound.setVolume(volume);
    }
}

void AudioManager::setSoundEffectPosition(const std::string& id, float x, float y, float z) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPosition(x, y, z);
    }
}

bool AudioManager::isSoundEffectPlaying(const std::string& id) const {
    auto it = soundEffects.find(id);
    return it != soundEffects.end() && it->second.getStatus() == sf::Sound::Playing;
}

void AudioManager::playSoundEffectWithDelay(const std::string& id, float delay) {
    delayedSounds.push({id, delay});
    std::thread(&AudioManager::processDelayedSounds, this).detach();
}

void AudioManager::playSequentialSoundEffects(const std::vector<std::string>& ids) {
    soundEffectSequences.push(ids);
    std::thread(&AudioManager::processSoundEffectSequences, this).detach();
}

void AudioManager::fadeInSoundEffect(const std::string& id, float targetVolume, float duration) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        float currentVolume = 0.0f;
        it->second.setVolume(currentVolume);
        it->second.play();
        float increment = (targetVolume - currentVolume) / (duration * 10);
        while (currentVolume < targetVolume) {
            currentVolume += increment;
            it->second.setVolume(currentVolume);
            sf::sleep(sf::milliseconds(100));
        }
    }
}

void AudioManager::fadeOutSoundEffect(const std::string& id, float duration) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        float currentVolume = it->second.getVolume();
        float decrement = currentVolume / (duration * 10);
        while (currentVolume > 0.0f) {
            currentVolume -= decrement;
            it->second.setVolume(currentVolume);
            sf::sleep(sf::milliseconds(100));
        }
        it->second.stop();
    }
}

void AudioManager::applyLowPassFilter(const std::string& id, float cutoffFrequency) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        applyFilter(it->second, [cutoffFrequency](float sample) {
            return sample * std::exp(-cutoffFrequency);
        });
    }
}

void AudioManager::applyHighPassFilter(const std::string& id, float cutoffFrequency) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        applyFilter(it->second, [cutoffFrequency](float sample) {
            return sample * (1.0f - std::exp(-cutoffFrequency));
        });
    }
}

void AudioManager::adjustPitch(const std::string& id, float pitchFactor) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPitch(pitchFactor);
    }
}

void AudioManager::adjustPlaybackSpeed(const std::string& id, float speedFactor) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setPitch(speedFactor);
    }
}

void AudioManager::setGlobalVolume(float volume) {
    if (volume < 0.0f || volume > 100.0f) {
        std::cerr << "Error: Volume out of range (0.0 - 100.0)\n";
        return;
    }
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

void AudioManager::setListenerPosition(float x, float y, float z) {
    sf::Listener::setPosition(x, y, z);
}

void AudioManager::setListenerDirection(float x, float y, float z) {
    sf::Listener::setDirection(x, y, z);
}

void AudioManager::setListenerUpVector(float x, float y, float z) {
    sf::Listener::setUpVector(x, y, z);
}

void AudioManager::setSoundEffectAttenuation(const std::string& id, float attenuation) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setAttenuation(attenuation);
    }
}

void AudioManager::setSoundEffectMinDistance(const std::string& id, float minDistance) {
    auto it = soundEffects.find(id);
    if (it != soundEffects.end()) {
        it->second.setMinDistance(minDistance);
    }
}

void AudioManager::saveAudioState() {
    savedState.globalVolume = globalVolume;
    savedState.isMuted = isMuted;
    for (const auto& [id, sound] : soundEffects) {
        savedState.soundEffectVolumes[id] = sound.getVolume();
    }
}

void AudioManager::loadAudioState() {
    setGlobalVolume(savedState.globalVolume);
    if (savedState.isMuted) {
        mute();
    } else {
        unmute();
    }
    for (const auto& [id, volume] : savedState.soundEffectVolumes) {
        auto it = soundEffects.find(id);
        if (it != soundEffects.end()) {
            it->second.setVolume(volume);
        }
    }
}

void AudioManager::loadFileToBuffer(const std::string& filepath, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filepath)) {
        std::cerr << "Error: Unable to load sound buffer from " << filepath << "\n";
    }
}

void AudioManager::processDelayedSounds() {
    while (!delayedSounds.empty()) {
        auto [id, delay] = delayedSounds.front();
        delayedSounds.pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay * 1000)));
        playSoundEffect(id);
    }
}

void AudioManager::processSoundEffectSequences() {
    while (!soundEffectSequences.empty()) {
        auto sequence = soundEffectSequences.front();
        soundEffectSequences.pop();
        for (const auto& id : sequence) {
            playSoundEffect(id);
            while (isSoundEffectPlaying(id)) {
                sf::sleep(sf::milliseconds(100));
            }
        }
    }
}

void AudioManager::applyFilter(sf::Sound& sound, const std::function<float(float)>& filterFunction) {
    const sf::SoundBuffer* buffer = sound.getBuffer();
    if (!buffer) {
        std::cerr << "Error: No buffer attached to the sound.\n";
        return;
    }

    const sf::Int16* samples = buffer->getSamples();
    const std::size_t sampleCount = buffer->getSampleCount();

    std::vector<sf::Int16> filteredSamples(samples, samples + sampleCount);

    for (auto& sample : filteredSamples) {
        sample = static_cast<sf::Int16>(filterFunction(static_cast<float>(sample)));
    }

    sf::SoundBuffer filteredBuffer;
    if (!filteredBuffer.loadFromSamples(filteredSamples.data(), filteredSamples.size(), buffer->getChannelCount(), buffer->getSampleRate())) {
        std::cerr << "Error: Failed to load filtered buffer.\n";
        return;
    }

    sound.setBuffer(filteredBuffer);
}