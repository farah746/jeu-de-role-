#include "Bouton.h"

Bouton::Bouton(const sf::Vector2f& position, const sf::Texture& texture) {
    m_sprite.setTexture(texture);
    m_sprite.setPosition(position);
}

sf::Vector2f Bouton::getPosition() const {
    return m_sprite.getPosition();
}

void Bouton::setPosition(unsigned int x, unsigned int y) {
    m_sprite.setPosition(x, y);
}

void Bouton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (m_visible) {
        target.draw(m_sprite, states);
    }
}

bool Bouton::contains(const sf::Vector2f& mousePosition) const {
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    return bounds.contains(mousePosition);
}

void Bouton::setVisible(bool visible) {
    m_visible = visible;
}
