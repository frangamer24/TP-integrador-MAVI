#pragma once
#include "lib.h"

#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
private:
	sf::Sprite sprite;
	bool esenemigo;
	bool vivo;


public:
    Personaje(const sf::Texture& texture, bool enemigo, sf::Vector2f position)
        : esenemigo(enemigo), vivo(true) {
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }
    void draw(sf::RenderWindow& window) const{
        if (vivo) window.draw(sprite);
    }

    void setScale(float x, float y);
    bool esenemigopersonaje() const { return esenemigo;}
    void eliminar() { vivo = false;}
    bool estavivo() const { return vivo;}
    sf::FloatRect getBounds() const { return sprite.getGlobalBounds();}
};

#endif
