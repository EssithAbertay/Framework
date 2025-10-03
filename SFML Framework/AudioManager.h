#pragma once
#include "SFML/Audio.hpp"
#include "SoundObject.h"
#include <map>
#include <string>

class AudioManager
{
public:
	// Create a music object with a key string. Returns whether or not object was successfully created
	bool addMusic(std::string filename, std::string key);
	// Create a sound object with a key string, and sets how many of this sound can play concurrently (up to 8). Returns whether or not object was successfully added
	bool addSound(std::string filename, std::string key, int maxPlaying = 1);

	// Get pointer to music stream
	sf::Music* getMusicStream();
	// Get pointer to music object
	MusicObject* getMusicObject(std::string key);
	// Get pointer to sound object from key string if it exists, or nullptr if it does not
	SoundObject* getSoundObject(std::string key);

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
	std::map<std::string, MusicObject> music_objects;
	// map of sound keynames to sound objects
	std::map<std::string, SoundObject> sound_objects;

	// the music stream
	sf::Music music;

	// default constructor private so that it may only be called by getInstance()
	AudioManager(){};
	~AudioManager(){};
};

