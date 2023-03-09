#include "Tank.h"
#include "Map.h"

Tank::Tank() : GameObject() {}

Tank::Tank(std::string image_name, float posX, float posY, int dir) : GameObject(image_name, posX, posY, dir) {}

void Tank::Movement(int dir, float time)
{
	direction = dir;
	switch (direction)
	{
	case 0:
		sprite.setRotation(0);
		for (int i = (posX + 0.3 * time - wRect / 2) / 50; i <= (posX + 0.3 * time + wRect / 2) / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
					return;
		if (posX + 0.3 * time + wRect / 2 > ScreenWidth)
			break;
		posX += 0.3f * time;
		sprite.move(0.3 * time, 0);
		break;
	case 1:
		sprite.setRotation(180);
		for (int i = (posX - 0.3 * time - wRect / 2) / 50; i <= (posX - 0.3 * time + wRect / 2) / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
					return;
		if (posX - 0.3 * time - wRect / 2 < 0)
			break;
		posX -= 0.3 * time;
		sprite.move(-0.3 * time, 0);
		break;
	case 2:
		sprite.setRotation(270);
		for (int i = (posX - wRect / 2) / 50; i <= (posX + wRect / 2) / 50; i++)
			for (int j = (posY - 0.3 * time - hRect / 2) / 50; j <= (posY - 0.3 * time + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
					return;
		if (posY - 0.3 * time - wRect / 2 < 0)
			break;
		posY -= 0.3 * time * (3 / 4.);
		sprite.move(0, -0.3 * time * (3 / 4.));
		break;
	case 3:
		sprite.setRotation(90);
		for (int i = (posX - wRect / 2) / 50; i <= (posX + wRect / 2) / 50; i++)
			for (int j = (posY + 0.3 * time - hRect / 2) / 50; j <= (posY + 0.3 * time + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
					return;
		if (posY + 0.3 * time + wRect / 2 > ScreenHeight)
			break;
		posY += 0.3f * time * (3 / 4.);
		sprite.move(0, 0.3 * time * (3 / 4.));
		break;
	}
}

void Tank::Fire(Projectile& projectile)
{
	switch (direction)
	{
	case 0:
		projectile.SetDirection(0);
		projectile.SetPos(posX + 42, posY);
		break;
	case 1:
		projectile.SetDirection(1);
		projectile.SetPos(posX - 42, posY);
		break;
	case 2:
		projectile.SetDirection(2);
		projectile.SetPos(posX, posY - 42);
		break;
	case 3:
		projectile.SetDirection(3);
		projectile.SetPos(posX, posY + 42);
	}
}
