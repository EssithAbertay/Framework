#pragma once
#include "SFML/Audio.hpp"

class SoundObject
{
public:
	SoundObject(){};
	~SoundObject(){};

	void loadSound(std::string filename);
	sf::Sound* getSound();

private:
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
};

class MusicObject
{

};

