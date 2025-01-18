#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <vector>
#include <mutex>
#include <thread>

class AudioManager {
public:
    // Get the single instance of AudioManager
    static AudioManager& getInstance();

    // Background Music Control
    void playBackgroundMusic(const std::string& filepath, bool loop = true);
    void playBackgroundMusicPlaylist(const std::vector<std::string>& filepaths, bool loopPlaylist = false);
    void playNextTrackInPlaylist();
    void playPreviousTrackInPlaylist();
    void stopBackgroundMusic();
    void setBackgroundMusicVolume(float volume);
    bool isBackgroundMusicPlaying() const;

    // Sound Effects Control
    void loadSoundEffect(const std::string& id, const std::string& filepath);
    void playSoundEffect(const std::string& id, float pitch = 1.0f, float relativeVolume = 100.0f);
    void stopAllSoundEffects();
    bool isSoundEffectPlaying(const std::string& id) const;

    // Advanced Sound Management
    void playSoundEffectWithDelay(const std::string& id, float delay);
    void playSequentialSoundEffects(const std::vector<std::string>& ids);

    // Global Controls
    void mute();
    void unmute();
    bool isMuted() const;

private:
    // Private constructor to prevent instantiation
    AudioManager();
    ~AudioManager();

    // Disable copying and assignment
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    sf::Music backgroundMusic;
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Sound> soundEffects;
    float globalVolume;
    bool isMutedFlag;

    std::vector<std::string> playlist;
    std::size_t currentTrackIndex;
    bool loopPlaylist;

    mutable std::mutex mutex;

    void applyGlobalVolume();
    void handlePlaylistPlayback();
};

#endif // AUDIOMANAGER_H