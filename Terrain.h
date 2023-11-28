#ifndef TERRAIN_H
#define TERRAIN_H

#include <SFML/Graphics.hpp>

class Terrain : public sf::Drawable {
public:
   Terrain(const std::string& filename, float scale); // Déclaration correcte du constructeur dans le header
    // ...
    void setPosition(float x, float y);

private:
    
sf::Sprite m_sprite; // Modifier le nom du sprite
    sf::Texture m_texture; // Ajouter la texture
    // Redéfinition de la fonction de dessin pour correspondre à l'interface de sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(m_sprite, states);
    }
};

#endif // TERRAIN_H
