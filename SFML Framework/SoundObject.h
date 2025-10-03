#pragma once
#include "SFML/Audio.hpp"

class SoundObject
{
public:
	SoundObject(){};
	~SoundObject(){};

	// Load a new sound.
	void loadSound(std::string filename, int maxPlaying);

	// Get the sound. If multiple can play at once, use getSounds() and iterate through the vector!
	sf::Sound* getSound();
	// Get the vector of all sounds.
	std::vector<sf::Sound*>* getSounds();

	// Get the earliest sound in the vector that isn't currently playing, or nullptr if all are playing.
	sf::Sound* getFreeSound();

	// Get how many sounds can play at once.
	int getMaxConcurrent() { return max_playing; }
private:
	sf::SoundBuffer* buffer;
	std::vector<sf::Sound*> sounds;
	int max_playing;
};

class MusicObject
{
public:
	MusicObject(){};
	MusicObject(std::string filename);
	~MusicObject(){};

	// Set looping points for this song. These will be used automatically when the song is played.
	void setSongLoopPoints(sf::Music::TimeSpan span);
	// Set whether the song should loop or not when played.
	void setLooping(bool loop);

	// Whether or not the song should loop when played.
	bool getLooping() { return loop_song; }
	// The points between which the song will loop.
	sf::Music::TimeSpan getLoopPoints() { return loop_points; }
	// The filename for this song.
	std::string getFilename() { return path; };

private:
	std::string path;
	sf::Music::TimeSpan loop_points;
	bool loop_song = true;
};

