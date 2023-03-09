#include "Projectile.h"
#include "Map.h"

Projectile::Projectile() : GameObject() {}

Projectile::Projectile(std::string image_name) : GameObject(image_name) 
{
	sprite.setOrigin(0, hRect / 2);
}

void Projectile::Movement(int dir, float time)
{
	direction = dir;
	switch (direction)
	{
	case 0:
		posX += 0.8 * time;
		sprite.move(0.8 * time, 0);
		sprite.setRotation(0);
		break;
	case 1:
		posX -= 0.8 * time;
		sprite.move(-0.8 * time, 0);
		sprite.setRotation(180);
		break;
	case 2:
		posY -= 0.8 * time * (3 / 4.);
		sprite.move(0, -0.8 * time * (3 / 4.));
		sprite.setRotation(270);
		break;
	case 3:
		posY += 0.8 * time * (3 / 4.);
		sprite.move(0, 0.8 * time * (3 / 4.));
		sprite.setRotation(90);
		break;
	}
}

bool Projectile::CollisionWithBounds()
{
	if ((direction == 0 && posX + wRect > ScreenWidth) || (direction == 1 && posX - wRect < 0) || (direction == 2 && posY - wRect < 0) || (direction == 3 && posY + wRect > ScreenHeight))
		return true;
	else
		return false;
}

bool Projectile::CollisionWithWall()
{
	switch (direction)
	{
	case 0:
		for (int i = posX / 50; i <= (posX + wRect) / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					Map[j][i] = ' ';
					return true;
				}
		break;
	case 1:
		for (int i = (posX - wRect) / 50; i <= posX / 50; i++)
			for (int j = (posY - hRect / 2) / 50; j <= (posY + hRect / 2) / 50; j++)
				if (Map[j][i] == 'b')
				{
					Map[j][i] = ' ';
					return true;
				}
		break;
	case 2:
		for (int i = (posX - hRect / 2) / 50; i <= (posX + hRect / 2) / 50; i++)
			for (int j = (posY - wRect) / 50; j <= posY / 50; j++)
				if (Map[j][i] == 'b')
				{
					Map[j][i] = ' ';
					return true;
				}
		break;
	case 3:
		for (int i = (posX - hRect / 2) / 50; i <= (posX + hRect / 2) / 50; i++)
			for (int j = posY / 50; j <= (posY + wRect) / 50; j++)
				if (Map[j][i] == 'b')
				{
					Map[j][i] = ' ';
					return true;
				}
		break;
	}
	return false;
}
