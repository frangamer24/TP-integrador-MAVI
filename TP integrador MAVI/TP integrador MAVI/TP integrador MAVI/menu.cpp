
#include "lib.h"
#include "Menu.h"

Menu::Menu()
{

    // Cargar la textura de fondo
    if (!backgroundTexture.loadFromFile("C:/SFML/TP integrador MAVI/imagenes/menu.png")) {
        std::cerr << "Error cargando la imagen de fondo: " << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);
    
    backgroundSprite.setScale(0.5f,0.5f); 

    // Cargar la fuente para el texto
    if (!font.loadFromFile("C:/SFML/TP integrador MAVI/tipografia/fuente.ttf")) {
        std::cerr << "Error cargando la fuente\n";
    }
    texto.setFont(font);
    texto.setString("precione ESC para salir del juego");
    texto.setPosition(10, 10);
    texto.setFillColor(sf::Color::White);
    texto.setCharacterSize(12);
    
}

void Menu::run(sf::RenderWindow& ventana) 
{

    sf::Vector2u textureSize = backgroundTexture.getSize();
    float scaleX = 800.f / textureSize.x;
    float scaleY = 600.f / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
    
    ventana.draw(backgroundSprite);
    ventana.draw(texto);
}