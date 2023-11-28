#include "Score.h"

Score::Score(sf::Font& font, const sf::Vector2f& position) : score(0) {
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(position);
    scoreText.setString("Score: " + std::to_string(score));
}

void Score::update(int enemyCaught) {
    score += enemyCaught * 10;
    scoreText.setString("Score: " + std::to_string(score));
}

void Score::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
}
