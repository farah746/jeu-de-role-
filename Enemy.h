#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>

enum class EnemyType {
    GREEN,
    // ... d'autres types d'ennemis
};

class Enemy {
public:
sf::CircleShape shape;
    sf::Vector2f currVelocity;

    EnemyType getType() const;

    Enemy(sf::Vector2f position, sf::Vector2f direction);

    void update(sf::Vector2f targetPosition);
    const sf::CircleShape& getShape() const; // Méthode pour récupérer la forme de l'ennemi
sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
}
private:
    sf::Sprite sprite; // Supposons que le sprite est stocké dans votre classe Enemy
    
};

#endif
