#include "Enemy.h"
#include <cmath>

Enemy::Enemy(sf::Vector2f position, sf::Vector2f direction)
    : currVelocity(direction * 2.0f)
{
    shape.setRadius(15.0f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void Enemy::update(sf::Vector2f targetPosition) {
    sf::Vector2f direction = targetPosition - shape.getPosition();
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction /= magnitude;
    }
    currVelocity = direction * 2.0f;
    shape.move(currVelocity);
}

const sf::CircleShape& Enemy::getShape() const {
    return shape;
}
