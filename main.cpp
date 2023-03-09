#include "Tank.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Map.h"
#include <iostream>

extern const int ScreenWidth = 1280;
extern const int ScreenHeight = 720;

int main()
{

    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Tanks");

    Tank ally_tank("ally_tank.png", 50.f, 670.f, 0);
    bool alive = true;

    Projectile ally_projectile("tank_projectile.png");
    bool ally_projectile_exists = false;
    float explosion_time = 151;

    Enemy enemy_tank("enemy_tank.png", 1230.f, 70.f, 1);
    bool enemy_tank_alive = true;

    sf::Texture explosion_texture;
    explosion_texture.loadFromFile("E:/Programming/C++/Projects/SFML Tanks/images/explosion.png");
    sf::Sprite explosion_sprite;
    explosion_sprite.setTexture(explosion_texture);
    explosion_sprite.setOrigin(explosion_sprite.getTextureRect().width / 2, explosion_sprite.getTextureRect().height / 2);

    sf::Texture brick_wall_texture;
    brick_wall_texture.loadFromFile("E:/Programming/C++/Projects/SFML Tanks/images/brick_wall.jpg");
    sf::Sprite brick_wall_sprite;
    brick_wall_sprite.setTexture(brick_wall_texture);

    sf::Event event;

    sf::Clock clock;

    while (window.isOpen()) 
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (alive)
        {

            window.clear();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                ally_tank.Movement(0, time);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                ally_tank.Movement(1, time);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                ally_tank.Movement(2, time);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                ally_tank.Movement(3, time);

            if (enemy_tank_alive)
            {
                enemy_tank.Movement(enemy_tank.GetDirection(), time);
                window.draw(enemy_tank.GetSprite());
            }

            if (!ally_projectile_exists && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                ally_tank.Fire(ally_projectile);
                ally_projectile_exists = true;
            }

            if (ally_projectile_exists)
            {
                ally_projectile.Movement(ally_projectile.GetDirection(), time);
                if (ally_projectile.CollisionWithBounds())
                {
                    explosion_sprite.setPosition(ally_projectile.GetPosX(), ally_projectile.GetPosY());
                    ally_projectile_exists = false;
                    explosion_time = 0;
                }
                else if (ally_projectile.GetSprite().getGlobalBounds().intersects(enemy_tank.GetSprite().getGlobalBounds()))
                {
                    explosion_sprite.setPosition(ally_projectile.GetPosX(), ally_projectile.GetPosY());
                    ally_projectile_exists = false;
                    enemy_tank_alive = false;
                    enemy_tank.SetPos(-100.f, -100.f);
                    explosion_time = 0;
                }
                else if (ally_projectile.CollisionWithWall())
                {
                    explosion_sprite.setPosition(ally_projectile.GetPosX(), ally_projectile.GetPosY());
                    ally_projectile_exists = false;
                    explosion_time = 0;
                }
                else
                    window.draw(ally_projectile.GetSprite());
            }

            if (ally_tank.GetSprite().getGlobalBounds().intersects(enemy_tank.GetSprite().getGlobalBounds()))
            {
                alive = false;
                ally_tank.SetPos(-100.f, -100.f);
            }

            if (explosion_time < 150)
            {
                explosion_time += time;
                window.draw(explosion_sprite);
            }

            window.draw(ally_tank.GetSprite());

            for (int i = 0; i < MapHeight; i++)
                for (int j = 0; j < MapWidth; j++)
                    if (Map[i][j] == 'b')
                    {
                        brick_wall_sprite.setPosition(j * 50, i * 50);
                        window.draw(brick_wall_sprite);
                    }
        }
        else
        {
            sf::Font font;
            font.loadFromFile("E:/Programming/C++/Projects/SFML Tanks/fonts/Roboto-Black.ttf");
            sf::Text txt;
            txt.setFont(font);
            txt.setString("Game Over!");
            txt.setCharacterSize(84);
            txt.setFillColor(sf::Color::Red);
            txt.setOrigin(txt.getGlobalBounds().width / 2, txt.getGlobalBounds().height / 2);
            txt.setPosition(ScreenWidth / 2, ScreenHeight / 2);
            window.draw(txt);
        }

        window.display();
    }

    return 0;
}