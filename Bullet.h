#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    sf::CircleShape shape;
    sf::Vector2f currVelocity;

    Bullet(sf::Vector2f position, sf::Vector2f direction);
    void update();
};

#endif

