#include "SoundObject.h"

void SoundObject::loadSound(std::string filename, int maxPlaying)
{
	buffer = new sf::SoundBuffer();
	buffer->loadFromFile(filename);

	max_playing = maxPlaying;
	for (int i = 0; i < maxPlaying; i++) {
		sounds.push_back(new sf::Sound(*buffer));
	}
}

sf::Sound* SoundObject::getSound()
{
	return sounds[0];
}

std::vector<sf::Sound*>* SoundObject::getSounds()
{
	return &sounds;
}

sf::Sound* SoundObject::getFreeSound()
{
	for (sf::Sound* snd : sounds) {
		if (snd->getStatus() != sf::SoundSource::Status::Playing) return snd;
	}
	return nullptr;
}



MusicObject::MusicObject(std::string filename)
{
	path = filename;
}

void MusicObject::setSongLoopPoints(sf::Music::TimeSpan span)
{
	loop_points = span;
}

void MusicObject::setLooping(bool loop)
{
	loop_song = loop;
}
