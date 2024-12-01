#pragma once
#include "lib.h"
#include "personaje.h"

#ifndef POINTER_H
#define POINTER_H

class puntero
{
private:
	sf::Texture texturapuntero;
	sf::Sprite spritepuntero;
	int puntuacion;
	int vida;
	sf::Font fuente; // Fuente para el texto del mensaje
	sf::Text mensajeFinal; // Texto a mostrar cuando termina el juego
	bool juegoTerminado; // Estado del juego
	int enemigosAbatidos; // Nuevo: Contador de enemigos abatidos
	int inocentesDisparados; // Nuevo: Contador de inocentes disparados
	void cargar();

public:

	puntero();

	void manejar(const sf::RenderWindow& window);
	void disparar(std::vector<Personaje>& enemies, std::vector<Personaje>& hostages);
	void draw(sf::RenderWindow& window);
	int obtenerpuntos() const;
	int obtenervida() const;
};

#endif 