#include "Game.h"


Game::Game(sf::RenderWindow* window)
{
	game_window = window;

}

Game::~Game()
{
}


void Game::handleInput(Input *in)
{
}

void Game::fixedUpdate(float fixed_timestep)
{

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

	game_window->display();
}
