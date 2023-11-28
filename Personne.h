#ifndef PERSONNE_H
#define PERSONNE_H

#include <SFML/Graphics.hpp>

class Personne {
public:
    Personne(sf::Vector2f position, sf::Texture& texture);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    void setScale(float scaleX, float scaleY);



    // Ajout de la fonction draw
    void draw(sf::RenderWindow& window);

    sf::FloatRect getLocalBounds() const;
 sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }
private:
        sf::Sprite sprite; // Supposons que le sprite est stocké dans votre classe Personne
};

#endif



