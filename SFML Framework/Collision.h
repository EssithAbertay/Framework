#pragma once
#include <SFML/Graphics.hpp>
#include "ColliderShape.h"
#include "CollisionEntity.h"

class Collision
{
public:
	static bool checkCollision(CollisionEntity &first_entity, CollisionEntity&second_entity);

private:
	static bool checkAABBCollision(sf::RectangleShape &first_bounding_box, sf::RectangleShape &second_bounding_box);
	static bool checkSATCollision(ColliderShape &first_collider, ColliderShape &second_collider);

	//functions for SAT collision
	static sf::Vector2f project(sf::Vector2f axis, std::array<sf::Vector2f, 4> vertices);
	static bool overlap(sf::Vector2f proj_one, sf::Vector2f proj_two);
};

