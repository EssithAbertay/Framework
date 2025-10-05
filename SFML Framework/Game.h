#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Input.h"
#include "Entity.h"
#include "CollisionEntity.h"
#include "CircleEntity.h"
#include "AudioManager.h"
#include "Animation.h"
#include "Collision.h"

class Game
{
public:
	Game(sf::RenderWindow* window);
	~Game();

	void handleInput(Input *in);

	void fixedUpdate(float fixed_timestep);
	void handleCollisions(float fixed_timestep);

	void variableUpdate(float variable_timestep);
	void renderGame();

private:
	sf::RenderWindow* game_window;

	CollisionEntity testone;
	CollisionEntity testtwo;

	CircleEntity testthree;
};

