#pragma once
#include "SFML/Graphics.hpp"

extern const int ScreenWidth;
extern const int ScreenHeight;

class GameObject
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	float posX;
	float posY;
	float wRect;
	float hRect;
	int direction;
public:
	GameObject();
	GameObject(std::string image_name);
	GameObject(std::string image_name, float posX, float posY, int dir);
	void SetPos(float posX, float posY);
	float GetPosX();
	float GetPosY();
	void SetDirection(int dir);
	int GetDirection();
	float GetWRect();
	float GetHRect();
	sf::Sprite GetSprite();
	virtual void Movement(int dir, float time) = 0;
};

