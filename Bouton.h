#ifndef BOUTON_H
#define BOUTON_H

#include <SFML/Graphics.hpp>

class Bouton : public sf::Drawable {
public:
    Bouton(const sf::Vector2f& position, const sf::Texture& texture);
    sf::Vector2f getPosition() const;
    void setPosition(unsigned int x, unsigned int y);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    bool contains(const sf::Vector2f& mousePosition) const;
    void setVisible(bool visible);

private:
    sf::Sprite m_sprite;
    bool m_visible = true; // Ajout d'une variable pour la visibilité du bouton
};

#endif // BOUTON_H
