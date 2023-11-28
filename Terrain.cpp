// Terrain.cpp
#include "Terrain.h"
Terrain::Terrain(const std::string& filename, float scale) {
    if (!m_texture.loadFromFile(filename)) {
        // Gestion de l'erreur si la texture n'est pas chargée
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(scale, scale);
}

void Terrain::setPosition(float x, float y) {
    m_sprite.setPosition(x, y);
}





