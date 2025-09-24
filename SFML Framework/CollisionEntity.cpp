#include "CollisionEntity.h"

CollisionEntity::CollisionEntity()
{
}

CollisionEntity::~CollisionEntity()
{
}

void CollisionEntity::fixedUpdate(float dt)
{
}

void CollisionEntity::variableUpdate(float dt)
{
}

ColliderShape & CollisionEntity::getCollider()
{
	return collider;
}
