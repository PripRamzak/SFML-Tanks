#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Tank : public GameObject
{
public:
	Tank();
	Tank(std::string image_name, float posX, float posY, int dir);
	void Movement(int dir, float time) override;
	void Fire(Projectile& projectile);
};

