#pragma once

#include <SFML/Audio.hpp>

class Son {
public:
    Son();
    void jouerSon();
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};
