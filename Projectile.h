#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	Projectile(std::string image_name);
	void Movement(int dir, float time) override;
	bool CollisionWithBounds();
	bool CollisionWithWall();
};
