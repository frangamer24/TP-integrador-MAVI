#pragma once
#include "lib.h"
#ifndef MENU_H
#define MENU_H

class Menu {
private:
    
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;         // Fuente para el texto
    sf::Text texto;

public:
    Menu();
    void run(sf::RenderWindow& window);
};

#endif // MENU_H
