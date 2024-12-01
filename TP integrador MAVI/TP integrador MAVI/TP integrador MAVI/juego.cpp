#include "lib.h"
#include"juego.h"
#include"escenario.h"

juego::juego(sf::RenderWindow& ventana) 
   : window(ventana)
{    
    ventana.setMouseCursorVisible(false);

    // Cargar fuente
    if (!font.loadFromFile("C:/SFML/TP integrador MAVI/tipografia/Space 3D Project.otf")) { // Usa una fuente válida
        std::cerr << "Error al cargar la fuente." << std::endl;
    }

    // Configurar el texto del puntaje
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(90, 10); // Esquina superior izquierda

    // Configurar el texto de las vidas
    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::Black);
    livesText.setPosition(650, 10); // Justo debajo del puntaje

    findeljuego.setFont(font);
    findeljuego.setCharacterSize(50);
    findeljuego.setPosition(270, 250); // Centrado
    findeljuego.setString("");
}

void juego::updateUI() {
    // Actualizar texto de puntaje y vidas
    scoreText.setString("Puntaje: " + std::to_string(puntero.obtenerpuntos()));
    livesText.setString("Vidas: " + std::to_string(puntero.obtenervida()));
}
void juego::vistoriaOderrota() {
    if (puntero.obtenervida() <= 0) {
        // Mostrar mensaje de derrota
        findeljuego.setFillColor(sf::Color::Red);
        findeljuego.setString("¡Perdiste! :(");
        window.clear();
        window.draw(findeljuego);
        window.display();
        sf::sleep(sf::seconds(3)); // Pausa para mostrar el mensaje
        window.close();
    }

}

void juego::run() 
{
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) { // Detecta la tecla ESC
                    std::cout << "Tecla ESC presionada. Cerrando el juego...\n";
                    window.close(); // Cierra la ventana del juego
                }
            }

        }


        // Manejar entrada del puntero
        puntero.manejar(window);
        
        // Disparar con el puntero
        puntero.disparar(escenario.getEnemies(), escenario.getHostages());

        // Actualizar UI
        updateUI();

        vistoriaOderrota();
        // Dibujar todo
        window.clear();
        escenario.draw(window);
        puntero.draw(window);
        window.draw(scoreText);
        window.draw(livesText);
        window.display();
        escenario.update(window);
    }
}