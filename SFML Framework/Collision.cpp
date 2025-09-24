#include "Collision.h"

bool Collision::checkCollision(CollisionEntity& first_entity, CollisionEntity& second_entity)
{
	if (checkAABBCollision(first_entity, second_entity)) //first perfom an aabb collision check, this is slightly more expensive but means that if not then we don't perform a far more expensive SAT check for every collision
	{
		return checkSATCollision(first_entity.getCollider(), second_entity.getCollider());
	}

	return false;
}

bool Collision::checkAABBCollision(sf::RectangleShape & first_bounding_box, sf::RectangleShape &second_bounding_box)
{
	bool is_colliding = first_bounding_box.getGlobalBounds().findIntersection(second_bounding_box.getGlobalBounds()) ? true : false;

	if (is_colliding)
	{
		return true;
	}
	return false;
}

bool Collision::checkSATCollision(ColliderShape &first_collider, ColliderShape &second_collider)
{
	std::array<sf::Vector2f, 4> first_corners = first_collider.getTransformedCorners();
	std::array<sf::Vector2f, 4> second_corners = second_collider.getTransformedCorners();

	//axes of first shape

	for (sf::Vector2f edge : first_collider.getEdges())
	{
		sf::Vector2f normal = edge.perpendicular().normalized();

		sf::Vector2f p1 = project(normal, first_corners);
		sf::Vector2f p2 = project(normal, second_corners);

		if (!overlap(p1, p2))
		{
			return false;
		}

	}

	//axes of second shape

	for (sf::Vector2f edge : second_collider.getEdges())
	{
		sf::Vector2f normal = edge.perpendicular().normalized();

		sf::Vector2f p1 = project(normal, first_corners);
		sf::Vector2f p2 = project(normal, second_corners);

		if (!overlap(p1, p2))
		{
			return false;
		}

	}

	return true;
}

sf::Vector2f Collision::project(sf::Vector2f axis, std::array<sf::Vector2f, 4> vertices)
{
	float min = axis.dot(vertices[0]);
	float max = min;

	for (int i = 1; i < 4; i++)
	{
		float p = axis.dot(vertices[i]);
		if (p < min)
		{
			min = p;
		}
		else if (p > max)
		{
			max = p;
		}
	}

	return sf::Vector2f(min,max);
}

bool Collision::overlap(sf::Vector2f proj_one, sf::Vector2f proj_two)
{

	return !(proj_one.y < proj_two.x || proj_two.y < proj_one.x);
}

