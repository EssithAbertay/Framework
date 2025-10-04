#include "CircleEntity.h"

CircleEntity::CircleEntity()
{
	setRadius(15);

	collider.setRadius(15);
	collider.setPosition(sf::Vector2f(getPosition().x + getRadius(), getPosition().y + getRadius()));
}

CircleEntity::~CircleEntity()
{
}

void CircleEntity::fixedUpdate(float dt)
{
	CircleShape::update();
}

void CircleEntity::variableUpdate(float dt)
{
}

CircleCollider* CircleEntity::getCollider()
{
	collider.setPosition(sf::Vector2f(getPosition().x + getRadius(), getPosition().y + getRadius()));
	return & collider;
}
