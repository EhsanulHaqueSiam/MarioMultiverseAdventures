#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    // Disable copying and assignment
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    // Background Music Control
    void playBackgroundMusic(const std::string& filepath, bool loop = true);
    void playBackgroundMusicPlaylist(const std::vector<std::string>& filepaths);
    void stopBackgroundMusic();
    void pauseBackgroundMusic();
    void resumeBackgroundMusic();
    void setBackgroundMusicVolume(float volume); // Adjusted to handle valid volume range
    sf::Music::Status getBackgroundMusicStatus() const;
    void fadeInBackgroundMusic(float targetVolume, float duration);
    void fadeOutBackgroundMusic(float targetVolume, float duration);

    // Sound Effects Control
    void loadSoundEffect(const std::string& id, const std::string& filepath);
    void playSoundEffect(const std::string& id, float pitch = 1.0f, float relativeVolume = 100.0f);
    void stopAllSoundEffects();
    void setSoundEffectVolume(float volume); // Adjusted to handle valid volume range
    void setSoundEffectPosition(const std::string& id, float x, float y, float z);
    bool isSoundEffectPlaying(const std::string& id) const;

    // Advanced Sound Management
    void playSoundEffectWithDelay(const std::string& id, float delay);
    void playSequentialSoundEffects(const std::vector<std::string>& ids);
    void fadeInSoundEffect(const std::string& id, float targetVolume, float duration);
    void fadeOutSoundEffect(const std::string& id, float duration);
    void applyLowPassFilter(const std::string& id, float cutoffFrequency);
    void applyHighPassFilter(const std::string& id, float cutoffFrequency);
    void adjustPitch(const std::string& id, float pitchFactor);
    void adjustPlaybackSpeed(const std::string& id, float speedFactor);

    // Global Audio Control
    void setGlobalVolume(float volume); // Adjusted to handle valid volume range
    float getGlobalVolume() const;
    void resetVolume();
    void mute();
    void unmute();

    // 3D Audio Control
    void setListenerPosition(float x, float y, float z);
    void setListenerDirection(float x, float y, float z);
    void setListenerUpVector(float x, float y, float z);
    void setSoundEffectAttenuation(const std::string& id, float attenuation);
    void setSoundEffectMinDistance(const std::string& id, float minDistance);

    // Audio State Management
    void saveAudioState();
    void loadAudioState();

private:
    sf::Music backgroundMusic;
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Sound> soundEffects;
    float globalVolume;
    bool isMuted;

    std::vector<std::string> playlist;
    std::size_t currentTrackIndex;

    std::queue<std::pair<std::string, float>> delayedSounds;
    std::queue<std::vector<std::string>> soundEffectSequences;

    struct AudioState {
        float globalVolume;
        bool isMuted;
        std::unordered_map<std::string, float> soundEffectVolumes;
    } savedState;

    static void loadFileToBuffer(const std::string& filepath, sf::SoundBuffer& buffer);
    void playNextTrackInPlaylist();
    void processDelayedSounds();
    void processSoundEffectSequences();
    static void applyFilter(sf::Sound& sound, const std::function<float(float)>& filterFunction);
};

#endif // AUDIOMANAGER_H