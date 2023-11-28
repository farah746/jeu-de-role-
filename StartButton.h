#pragma once
#include <SFML/Graphics.hpp>

class StartButton {
public:
    StartButton(sf::Texture& texture, const sf::Vector2f& position);

    void draw(sf::RenderWindow& window);

private:
    sf::Sprite startButton;
};
