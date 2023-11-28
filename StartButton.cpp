#include "StartButton.h"

StartButton::StartButton(sf::Texture& texture, const sf::Vector2f& position) {
    startButton.setTexture(texture);
    startButton.setOrigin(startButton.getLocalBounds().width / 2, startButton.getLocalBounds().height / 2);
    startButton.setPosition(position);
    // Autres initialisations si nécessaires
}

void StartButton::draw(sf::RenderWindow& window) {
    window.draw(startButton);
}
