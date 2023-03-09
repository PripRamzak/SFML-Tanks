#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(std::string image_name, float posX, float posY, int dir);
	void Movement(int dir, float time) override;
};

