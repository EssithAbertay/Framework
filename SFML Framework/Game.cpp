#include "Game.h"


Game::Game(sf::RenderWindow* window)
{
	game_window = window;

	anim.addFramesRow({ {0, 0}, {250, 250} }, 3);
	anim.addFramesRow({ {0, 250}, {250, 250} }, 3);
	anim.addFramesRow({ {0, 500}, {250, 250} }, 2);
	anim.setAnimationFps(8);

	sprite.setTextureRect(anim.getCurrentFrame());
}

Game::~Game()
{
}


void Game::handleInput(Input *in)
{
	if (in->isKeyPressed(sf::Keyboard::Key::A)) {
		fps--;
		if (fps < 0) fps = 0;
		anim.setAnimationFps(fps);
	}
	if (in->isKeyPressed(sf::Keyboard::Key::D)) {
		fps++;
		anim.setAnimationFps(fps);
	}
	if (in->isKeyPressed(sf::Keyboard::Key::B)) {
		if (anim.isPlaying()) {
			anim.pause();
		}
		else anim.play();
	}
	if (in->isKeyPressed(sf::Keyboard::Key::Q)) {
		anim.reset();
	}
	if (in->isKeyPressed(sf::Keyboard::Key::E)) {
		switch (anim.getLooping()) {
		case AnimLoopType::NoLoop:
			anim.setLooping(AnimLoopType::Loop);
			break;
		case AnimLoopType::Loop:
			anim.setLooping(AnimLoopType::Boomerang);
			break;
		case AnimLoopType::Boomerang:
			anim.setLooping(AnimLoopType::NoLoop);
			break;
		}
	}
	if (in->isKeyPressed(sf::Keyboard::Key::S)) {
		anim.setHorizontalFlip(!anim.getHorizontalFlip());
	}
	if (in->isKeyPressed(sf::Keyboard::Key::W)) {
		anim.setVerticalFlip(!anim.getVerticalFlip());
	}
	if (in->isKeyPressed(sf::Keyboard::Key::R)) {
		anim.setFrameSpeed(0, 0.5);
		anim.setFrameSpeed(4, 0.5);
	}
	if (in->isKeyPressed(sf::Keyboard::Key::F)) {
		anim.setFrameSpeed(0, 2.5);
		anim.setFrameSpeed(4, 2.5);
	}
}

void Game::fixedUpdate(float fixed_timestep)
{
	anim.animate(fixed_timestep);
	if (anim.hasFrameChanged()) {
		sprite.setTextureRect(anim.getCurrentFrame());
	}
}

void Game::handleCollisions(float fixed_timestep)
{
}

void Game::variableUpdate(float variable_timestep)
{
}


void Game::renderGame()
{
    game_window->clear(sf::Color::White);
	game_window->draw(sprite);
	game_window->display();
}
