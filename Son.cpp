#include "Son.h"
#include <iostream>

Son::Son() {
    if (!buffer.loadFromFile("/home/vboxuser/Desktop/o/son.wav")) {
        std::cout << "Erreur : Impossible de charger le fichier audio." << std::endl;
        std::string filename = "/home/vboxuser/Desktop/o/son.wav";
        std::cout << "Chargement du fichier audio '" << filename << "' a échoué." << std::endl;
    }
    sound.setBuffer(buffer);
    sound.setLoop(true);
}

void Son::jouerSon() {
    sound.play();
}
