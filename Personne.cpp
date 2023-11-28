#include "Personne.h"

Personne::Personne(sf::Vector2f position, sf::Texture& texture) {
    sprite.setTexture(texture);
    setPosition(position);
}

void Personne::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Personne::setScale(float scaleX, float scaleY) {
    sprite.setScale(scaleX, scaleY);
}



sf::Vector2f Personne::getPosition() const {
    return sprite.getPosition();
}

void Personne::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Personne::getLocalBounds() const {
    return sprite.getLocalBounds();
}
