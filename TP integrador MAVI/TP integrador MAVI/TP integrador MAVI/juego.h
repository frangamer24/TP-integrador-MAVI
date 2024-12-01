#pragma once
#include "lib.h"
#include "puntero.h"
#include "escenario.h"

#ifndef GAME_H
#define GAME_H


class juego {
private:
    sf::RenderWindow& window;    // Ventana del juego
    puntero puntero;            // Puntero del jugador
    escenario escenario;          // Escenario del juego

    sf::Font font;              // Fuente para el texto
    sf::Text scoreText;         // Texto para mostrar el puntaje
    sf::Text livesText;         // Texto para mostrar las vidas
    sf::Text endGameText;       // Texto para mostrar el mensaje final
    sf::Text findeljuego;
    std::string titulo;
    std::string menu;

    void updateUI();            // Actualiza el texto en pantalla
    void vistoriaOderrota();       // Verifica si se ganó o perdió

public:
    juego(sf::RenderWindow& ventana); //const std::string& titulo, const std::string& menu);

    void run();
};

#endif // GAME_H