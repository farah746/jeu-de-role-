#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "Bouton.h" // Incluez la classe Bouton
#include "Personne.h" // Incluez la classe Personne
#include "Terrain.h"
#include "Son.h" // Ajout du fichier d'en-tête de la classe Son
#include "Score.h"
#include <iostream>
#include <cmath> 
#include <vector>




int main() {
 sf::RenderWindow window(sf::VideoMode(800, 600), "Déplacement du personnage");
    sf::Clock clock;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    float elapsedTime = 0.0f;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }
    Score score(font, sf::Vector2f(window.getSize().x - 150, 10)); // Création de l'objet Score
    Son son; // Création de l'objet Son




  

   
   sf::Texture startButtonTexture;
    if (!startButtonTexture.loadFromFile("play.png")) {
        return -1;
    }

    Bouton startButton(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), startButtonTexture);



    








    // ... Vos initialisations de textures, sprites et variables restent inchangées

    float enemyDelay = 0.0f; // Délai avant le début du mouvement de l'ennemi
    float enemyMoveDelay = 3.0f; // Délai après lequel l'ennemi commence à bouger
  
   
    //sf::Sprite startButton(startButtonTexture);

    startButton.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    bool gameStarted = false;



sf::Texture personnageTexture;
if (!personnageTexture.loadFromFile("new.png")) {
    return -1;
}


    float facteurReduction = 0.1f; // Changer le facteur de réduction selon vos besoins




Personne personnage(sf::Vector2f((window.getSize().x - personnageTexture.getSize().x * facteurReduction) / 2,
    (window.getSize().y - personnageTexture.getSize().y * facteurReduction) / 2), personnageTexture);

    personnage.setScale(facteurReduction, facteurReduction); // Redimensionner le sprite de la personne


    float vitesse = 0.7f;

        Terrain terrain("terrain.jpg", 1.0f); // Création d'un objet Terrain
    // sf::Texture terrainTexture;
    // if (!terrainTexture.loadFromFile("terrain.jpg")) {
    //     return -1;
    // }
    // sf::Sprite terrain(terrainTexture);

    sf::Vector2f position((window.getSize().x - personnage.getLocalBounds().width * facteurReduction) / 2, (window.getSize().y - personnage.getLocalBounds().height * facteurReduction) / 2);
/////// instance de bouton 

 int ennemisTouches = 0; // Variable pour compter les ennemis touchés


   while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {

if (event.type == sf::Event::Closed) {
                window.close(); // Fermer la fenêtre si l'événement de fermeture est détecté
            }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                                son.jouerSon();
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                if (startButton.contains(mousePosition)) {
                    startButton.setVisible(false); // Change la visibilité du bouton lorsque cliqué
                }
            }
        }
    

if (event.type == sf::Event::Resized) {
                // Mise à jour de la position du bouton "Start" en cas de redimensionnement de la fenêtre
                startButton.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            }



  
 
          
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // Créer une balle et l'ajouter au vector
                Bullet bullet(personnage.getPosition(), sf::Vector2f(0.0f, -1.0f)); // Direction de la balle (vers la droite)
                bullets.push_back(bullet);
            }
             elapsedTime += clock.restart().asSeconds();

            if (elapsedTime >= enemyMoveDelay) {
                sf::Vector2f enemyPosition(rand() % window.getSize().x, rand() % window.getSize().y);
                sf::Vector2f enemyDirection(-1.0f, 0.0f);

                Enemy enemy(enemyPosition, enemyDirection);
                enemies.push_back(enemy);

                elapsedTime = 0.0f;
                gameStarted = true;
            }
        }



        window.clear();
        window.draw(terrain);

    


        if (gameStarted) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                position.x -= vitesse;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                position.x += vitesse;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                position.y -= vitesse;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                position.y += vitesse;
            }
            personnage.setPosition(position);
    personnage.draw(window); // Utilisation de la méthode draw de Personne        } else {
            window.draw(startButton);
        }
else {
        window.draw(startButton);
    }

        for (size_t i = 0; i < bullets.size(); ++i) {
            bullets[i].update(); // Mettre à jour la position de la balle
            window.draw(bullets[i].shape); // Dessiner la balle
            
        }

            for (size_t i = 0; i < enemies.size(); ++i) {
            enemies[i].update(personnage.getPosition());
            ennemisTouches++; 
            window.draw(enemies[i].getShape()); // Dessiner l'ennemi
            
            // Vérifier la collision entre le personnage et l'ennemi
            if (personnage.getGlobalBounds().intersects(enemies[i].getGlobalBounds())) {
                ennemisTouches++; // Incrémenter le compteur d'ennemis touchés
                std::cout << "Collision avec un ennemi !" << std::endl; // Message de débogage
            }

                    for (size_t j = 0; j < enemies.size(); ++j) {
                if (bullets[i].shape.getGlobalBounds().intersects(enemies[j].shape.getGlobalBounds())) {
                    // Collision détectée entre la balle et l'ennemi
                    bullets.erase(bullets.begin() + i); // Supprimer la balle
                    enemies.erase(enemies.begin() + j); // Supprimer l'ennemi
                    score.update(1); // Mettre à jour le score en fonction du nombre d'ennemis touchés
                    break; // Sortir de la boucle des ennemis après la suppression
                }
            }
        }
        



        window.display();

        //  score.incrementEnemyCaught(enemies,personnage);
    // score.displayFinalScore();
    }
        std::cout << "Nombre d'ennemis touches : " << ennemisTouches/500 << std::endl;
            return 0;
}
