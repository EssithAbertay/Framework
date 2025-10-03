#include "AudioManager.h"

bool AudioManager::addMusic(std::string filename, std::string key)
{
	if (music_objects.count(key) > 0) return false;
	music_objects[key] = MusicObject(filename);
	return true;
}

bool AudioManager::addSound(std::string filename, std::string key, int maxPlaying)
{
	if (sound_objects.count(key) > 0) return false;

	// clamp num concurrent sfx
	if (maxPlaying < 1) maxPlaying = 1;
	if (maxPlaying > 8) maxPlaying = 8;

	SoundObject soundObj;
	soundObj.loadSound(filename, maxPlaying);
	sound_objects[key] = soundObj;
	return true;
}

sf::Music* AudioManager::getMusicStream()
{
	return &music;
}

MusicObject* AudioManager::getMusicObject(std::string key)
{
	if (music_objects.count(key) == 0) return nullptr;
	return &music_objects[key];
}

SoundObject* AudioManager::getSoundObject(std::string key)
{
	if (sound_objects.count(key) == 0) return nullptr;
	return &sound_objects[key];
}

void AudioManager::playMusic(std::string key)
{
	// can't play music that doesn't exist
	if (music_objects.count(key) == 0) return;

	// get the music object and load the file into the stream
	MusicObject musicObj = music_objects[key];
	music.openFromFile(musicObj.getFilename());

	// If the song loops, set music stream to loop
	music.setLooping(musicObj.getLooping());

	// If it has custom loop points, use them
	if (musicObj.getLoopPoints().length > sf::Time::Zero) {
		music.setLoopPoints(musicObj.getLoopPoints());
	}
	// Otherwise, reset the loop points
	else {
		music.setLoopPoints({ sf::Time::Zero, sf::Time::Zero });
	}

	music.play();
}

void AudioManager::playSound(std::string key)
{
	if (sound_objects.count(key) == 0) return;

	SoundObject soundObj = sound_objects[key];
	if (soundObj.getMaxConcurrent() == 1) {
		soundObj.getSound()->play();
	}
	else {
		sf::Sound* freeSound = soundObj.getFreeSound();
		if (freeSound == nullptr) { 
			soundObj.getSound()->play();
			return;
		}
		freeSound->play();
	}
}

void AudioManager::stopMusic()
{
	music.stop();
}

void AudioManager::stopAllSounds()
{
	for (auto& keyValPair : sound_objects) {
		SoundObject sObj = keyValPair.second;
		for (sf::Sound* snd : *sObj.getSounds()) {
			snd->stop();
		}
	}
}
