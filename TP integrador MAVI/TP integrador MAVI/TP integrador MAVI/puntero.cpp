#include "lib.h"
#include "puntero.h"
#include "personaje.h"

puntero::puntero() : vida(3), puntuacion(0)
{
	cargar();

	spritepuntero.setTexture(texturapuntero);
	spritepuntero.setScale(0.2f, 0.2f);
	spritepuntero.setOrigin(texturapuntero.getSize().x / 2, texturapuntero.getSize().y / 2);
}
void puntero::cargar() 
{
	if (!texturapuntero.loadFromFile("C:/SFML/TP integrador MAVI/imagenes/punto de mira.png")) { 
		std::cerr << "Error al cargar la textura del puntero." << std::endl;
	}
};
void puntero::manejar(const sf::RenderWindow& window)
{
	sf::Vector2i mouseposicion = sf::Mouse::getPosition(window);
	spritepuntero.setPosition(static_cast<float>(mouseposicion.x), static_cast<float>(mouseposicion.y));

}
void puntero::disparar(std::vector<Personaje>& enemies, std::vector<Personaje>& hostages) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Manejar enemigos
        for (auto& enemy : enemies) {
            if (enemy.estavivo() && spritepuntero.getGlobalBounds().intersects(enemy.getBounds())) {
                enemy.eliminar();  // Marcar como eliminado
                puntuacion += 1;   // Incrementar puntuación
                break;
            }
        }

        // Manejar rehenes
        for (auto& hostage : hostages) {
            if (hostage.estavivo() && spritepuntero.getGlobalBounds().intersects(hostage.getBounds())) {
                hostage.eliminar(); // Marcar como eliminado
                vida -= 1;          // Restar una vida
                break;
            }
        }
    }
}

void puntero::draw(sf::RenderWindow& window) {
    window.draw(spritepuntero);
}

int puntero::obtenerpuntos() const {
    return puntuacion;
}

int puntero::obtenervida() const {
    return vida;
}