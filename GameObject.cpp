#include "GameObject.h"
#include <iostream>

GameObject::GameObject() : posX(0), posY(0), wRect(0), hRect(0), direction(0) {}

GameObject::GameObject(std::string image_name) : posX(0), posY(0), direction(0)
{
	texture.loadFromFile("E:/Programming/C++/Projects/SFML Tanks/images/" + image_name);
	sprite.setTexture(texture);
	wRect = sprite.getTextureRect().width;
	hRect = sprite.getTextureRect().height;
}

GameObject::GameObject(std::string image_name, float posX, float posY, int dir)
{
	texture.loadFromFile("E:/Programming/C++/Projects/SFML Tanks/images/" + image_name);
	sprite.setTexture(texture);
	wRect = sprite.getTextureRect().width;
	hRect = sprite.getTextureRect().height;
	sprite.setOrigin(wRect / 2, hRect / 2);
	this->posX = posX;
	this->posY = posY;
	sprite.setPosition(posX, posY);
	direction = dir;
	this->SetDirection(direction);
}

void GameObject::SetPos(float posX, float posY)
{
	GameObject::posX = posX;
	GameObject::posY = posY;
	sprite.setPosition(this->posX, this->posY);
}

float GameObject::GetPosX()
{
	return posX;
}

float GameObject::GetPosY()
{
	return posY;
}

void GameObject::SetDirection(int dir)
{
	direction = dir;
	switch (direction)
	{
	case 0:
		sprite.setRotation(0);
		break;
	case 1:
		sprite.setRotation(180);
		break;
	case 2:
		sprite.setRotation(270);
		break;
	case 3:
		sprite.setRotation(90);
		break;
	}
}

int GameObject::GetDirection()
{
	return direction;
}

float GameObject::GetWRect()
{
	return wRect;
}

float GameObject::GetHRect()
{
	return hRect;
}

sf::Sprite GameObject::GetSprite()
{
	return sprite;
}
