#include "personne.h"

Personne::Personne(sf::Texture& texture, float initialVitesse, float facteurReduction) : vitesse(initialVitesse) {
    sprite.setTexture(texture);
    sprite.setScale(facteurReduction, facteurReduction);
}

void Personne::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

sf::Vector2f Personne::getPosition() const {
    return sprite.getPosition();
}

void Personne::move(float offsetX, float offsetY) {
    sprite.move(offsetX * vitesse, offsetY * vitesse);
}

void Personne::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
