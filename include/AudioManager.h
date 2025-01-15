#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <vector>

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
    void setBackgroundMusicVolume(float volume);
    sf::Music::Status getBackgroundMusicStatus() const;
    void fadeInBackgroundMusic(float targetVolume, float duration);
    void fadeOutBackgroundMusic(float duration);

    // Sound Effects Control
    void loadSoundEffect(const std::string& id, const std::string& filepath);
    void playSoundEffect(const std::string& id, float pitch = 1.0f, float relativeVolume = 100.0f);
    void stopAllSoundEffects();
    void setSoundEffectVolume(float volume);
    void setSoundEffectPosition(const std::string& id, float x, float y, float z);
    bool isSoundEffectPlaying(const std::string& id) const;

    // Global Audio Control
    void setGlobalVolume(float volume);
    float getGlobalVolume() const;
    void resetVolume();
    void mute();
    void unmute();

private:
    sf::Music backgroundMusic;
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Sound> soundEffects;
    float globalVolume;
    bool isMuted;

    std::vector<std::string> playlist;
    std::size_t currentTrackIndex;

    void loadFileToBuffer(const std::string& filepath, sf::SoundBuffer& buffer);
    void playNextTrackInPlaylist();
};

#endif // AUDIOMANAGER_H