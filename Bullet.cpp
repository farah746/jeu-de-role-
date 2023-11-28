#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
    : currVelocity(direction * 5.0f)
{
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void Bullet::update() {
    shape.move(currVelocity);
}
