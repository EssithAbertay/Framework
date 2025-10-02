#include "AudioManager.h"

bool AudioManager::addMusic(std::string filename, std::string key)
{
	if (music_files.count(key) > 0) return false;
	music_files[key] = filename;
	return true;
}

bool AudioManager::addSound(std::string filename, std::string key)
{
	if (sound_objects.count(key) > 0) return false;
	//sound_objects[key] = filename;
	return true;
}

sf::Music* AudioManager::getMusic()
{
	return &music;
}

sf::Sound* AudioManager::getSound(std::string key)
{
	if (sound_objects.count(key) == 0) return nullptr;
	return sound_objects[key];
}

void AudioManager::playMusic(std::string key)
{
	// can't play music that doesn't exist
	if (music_files.count(key) == 0) return;

	music.openFromFile(music_files[key]);
	music.play();
}

void AudioManager::playSound(std::string key)
{
}

void AudioManager::stopMusic()
{
	music.stop();
}

void AudioManager::stopAllSounds()
{
}
