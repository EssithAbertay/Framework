#include "Game.h"


Game::Game(sf::RenderWindow* window)
{
	game_window = window;

	testone.setFillColor(sf::Color::Blue);
	testone.setSize(sf::Vector2f(100, 100));


	testtwo.setFillColor(sf::Color::Green);
	testtwo.setSize(sf::Vector2f(100, 100));
	testtwo.setPosition(sf::Vector2f(200, 200));
}

Game::~Game()
{
}


void Game::handleInput(Input *in)
{
	if (in->dpad_right)
	{
		testone.setPosition(testone.getPosition() + sf::Vector2f(0.1, 0));
	}
	if (in->dpad_left)
	{
		testone.setPosition(testone.getPosition() + sf::Vector2f(-0.1, 0));
	}
	if (in->dpad_up)
	{
		testone.setPosition(testone.getPosition() + sf::Vector2f(0, -0.1));
	}
	if (in->dpad_down)
	{
		testone.setPosition(testone.getPosition() + sf::Vector2f(0, 0.1));
	}
}

void Game::fixedUpdate(float fixed_timestep)
{
	testone.fixedUpdate(fixed_timestep);
}

void Game::handleCollisions(float fixed_timestep)
{
	if(Collision::checkCollision(testone.getCollider(), testtwo.getCollider()))
	{
		testone.setFillColor(sf::Color::Red);
	}
	else
	{
		testone.setFillColor(sf::Color::Blue);
	}
}

void Game::variableUpdate(float variable_timestep)
{
	testone.variableUpdate(variable_timestep);
	testtwo.variableUpdate(variable_timestep);
}


void Game::renderGame()
{
    game_window->clear(sf::Color::White);

	game_window->draw(testone);
	game_window->draw(testtwo);

	game_window->display();
}
