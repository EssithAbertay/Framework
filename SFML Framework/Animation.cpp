#include "Animation.h"

void Animation::addFrame(sf::IntRect frameRect, float frameSpeed)
{
	frames.push_back({ frameRect, frameSpeed });
}

void Animation::addFramesRow(sf::IntRect frameRect, int numFrames, int offset)
{
	frames.push_back({ frameRect, 1.0f });
	sf::IntRect rect;
	for (int i = 1; i < numFrames; i++) {
		rect = { {rect.position.x + rect.size.x + offset, rect.position.y}, rect.size };
		frames.push_back({ rect, 1.0f });
	}
}

sf::IntRect Animation::getCurrentFrame()
{
	return frames[current_frame].rect;
}

int Animation::getFrameIndex()
{
	return 0;
}

int Animation::getFrameCount()
{
	return 0;
}

void Animation::setFrameIndex(int frameIndex)
{
}

bool Animation::hasFrameChanged()
{
	return false;
}

void Animation::setAnimationSpeed(float frameTime)
{
}

void Animation::setAnimationFps(float fps)
{
}

void Animation::setFrameSpeed(int frameIndex, float percent)
{
}

float Animation::getFrameSpeed(int frameIndex)
{
	return 0.0f;
}

void Animation::reset()
{
}
