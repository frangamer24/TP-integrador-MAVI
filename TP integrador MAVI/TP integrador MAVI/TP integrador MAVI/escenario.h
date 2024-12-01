#pragma once
#include "lib.h"
#include "personaje.h"

#ifndef ESCENARIO_H
#define ESCENARIO_H

class escenario {
private:
    sf::Texture enemyTexture, hostageTexture, backgroundTexture;
    sf::Sprite backgroundSprite;

    std::vector<Personaje> enemies;
    std::vector<Personaje> hostages;

    const int maxEnemies = 2;
    const int maxHostages = 1;

    void loadResources();  // Carga texturas
    void respawnCharacter(std::vector<Personaje>& characters, bool esEnemigo);

public:
    escenario();

    void spawnCharacters();       
    void update(sf::RenderWindow& window);         // Actualizar escenario
    void draw(sf::RenderWindow& window) const;     // Dibujar escenario
    std::vector<Personaje>& getEnemies();         // Acceso a los enemigos
    std::vector<Personaje>& getHostages();        // Acceso a los rehenes
};

#endif // SCENARIO_H