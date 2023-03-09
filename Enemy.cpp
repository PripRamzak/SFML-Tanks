#include "Enemy.h"
#include "Map.h"

Enemy::Enemy() : GameObject() {}

Enemy::Enemy(std::string image_name, float posX, float posY, int dir) : GameObject(image_name, posX, posY, dir) {}

void Enemy::Movement(int dir, float time)
{
	direction = dir;
	switch (direction)
	{
	case 0:
		sprite.setRotation(0);
		for (int i = (posX + 0.3 * time - wRect / 2) / 50; i <= (posX + 0.3 * time + wRect / 2) / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					direction = 1;
					sprite.setRotation(180);
					return;
				}
		if (posX + 0.3 * time + wRect / 2 > ScreenWidth)
		{
			direction = 1;
			break;
		}
		posX += 0.3 * time;
		sprite.move(0.3 * time, 0);
		break;
	case 1:
		sprite.setRotation(180);
		for (int i = (posX - 0.3 * time - wRect / 2) / 50; i <= (posX - 0.3 * time + wRect / 2) / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					direction = 0;
					sprite.setRotation(0);
					return;
				}
		if (posX - 0.3 * time - wRect / 2 < 0)
		{
			direction = 0;
			break;
		}
		posX -= 0.3 * time;
		sprite.move(-0.3 * time, 0);
		break;
	case 2:
		sprite.setRotation(270);
		for (int i = (posX - wRect / 2) / 50; i <= (posX + wRect / 2) / 50; i++)
			for (int j = (posY - 0.3 * time - hRect / 2) / 50; j <= (posY - 0.3 * time + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					direction = 3;
					sprite.setRotation(90);
					return;
				}
		if (posY - 0.3 * time - wRect / 2 < 0)
		{
			direction = 3;
			break;
		}
		posY -= 0.3 * time * (3 / 4.);
		sprite.move(0, -0.3 * time * (3 / 4.));
		break;
	case 3:
		sprite.setRotation(90);
		for (int i = (posX - wRect / 2) / 50; i <= (posX + wRect / 2) / 50; i++)
			for (int j = (posY + 0.3 * time - hRect / 2) / 50; j <= (posY + 0.3 * time + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					direction = 2;
					sprite.setRotation(270);
					return;
				}
		if (posY + 0.3 * time + wRect / 2 > ScreenHeight)
		{
			direction = 2;
			break;
		}
		posY += 0.3 * time * (3 / 4.);
		sprite.move(0, 0.3 * time * (3 / 4.));
		break;
	}
}
