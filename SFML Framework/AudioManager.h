#pragma once
#include "SFML/Audio.hpp"
#include <map>
#include <string>

class AudioManager
{
public:
	// Add a music file with a key string. Returns whether or not file was successfully added
	bool addMusic(std::string filename, std::string key);
	// Add a sound object with a key string. Returns whether or not file was successfully added
	bool addSound(std::string filename, std::string key);

	// Get pointer to music stream
	sf::Music* getMusic();
	// Get pointer to sound object from key string if it exists, or nullptr if it does not
	sf::Sound* getSound(std::string key);

	// Plays music from the string key if it exists
	void playMusic(std::string key);
	// Plays a sound from the string key if it exists
	void playSound(std::string key);

	// Stops playing music.
	void stopMusic();
	// Stops playing all sounds.
	void stopAllSounds();

	// Get the instance of the AudioManager
	static AudioManager& getInstance() {
		static AudioManager instance;
		return instance;
	}

	// Delete copy constructor and copy operator to prevent multiple instances of AudioManager
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator=(const AudioManager&) = delete;
private:
	// value is string because music is loaded from filename into sf::Music object
	std::map<std::string, std::string> music_files;
	// map of sound keynames to sound objects
	std::map<std::string, sf::Sound*> sound_objects;

	// the music stream
	sf::Music music;

	// default constructor private so that it may only be called by getInstance()
	AudioManager(){};
	~AudioManager(){};
};

