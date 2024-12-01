#include "lib.h"
#include "menu.h"
#include "juego.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego: Unknown Origins");
    Menu menu;
    juego mijuego(window);

    bool jugando = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (!jugando && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Espacio presionado. Iniciando el juego...\n";
                    jugando = true; // Cambiar a modo de juego
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) { // Detecta la tecla ESC
                        std::cout << "Tecla ESC presionada. Cerrando el juego...\n";
                        window.close(); // Cierra la ventana del juego
                    }
                }
            }
        }

        window.clear();

        if (!jugando) {
            // Dibujar el menú
            menu.run(window);
        }
        else {
            // Ejecutar el juego
            mijuego.run();
        }

        window.display();
    }

    return 0;
}