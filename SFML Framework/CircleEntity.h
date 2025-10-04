#pragma once
#include "CircleCollider.h"
#include "SFML/Graphics.hpp"

class CircleEntity :public sf::CircleShape
{
public:
	CircleEntity();
	~CircleEntity();

	void fixedUpdate(float dt);
	void variableUpdate(float dt);

	CircleCollider* getCollider();

private:
	CircleCollider collider;
};

