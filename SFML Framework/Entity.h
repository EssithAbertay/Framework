#pragma once

#include <SFML/Graphics.hpp>

class Entity: public sf::RectangleShape
{
public:

	Entity();
	Entity(sf::Vector2f position, sf::Vector2f size);
	~Entity();

	virtual void handleInput(float dt);

	virtual void fixedUpdate(float dt);
	virtual void variableUpdate(float dt);


	sf::Vector2f position;
	sf::Vector2f velocity = sf::Vector2f(0, 0);
};

