#include "lib.h"
#include "escenario.h"


escenario::escenario() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // Semilla para números aleatorios
    loadResources();

    // Configurar el fondo
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(800.0f / backgroundTexture.getSize().x,
        600.0f / backgroundTexture.getSize().y);

    spawnCharacters();
}

void escenario::loadResources() {
    if (!enemyTexture.loadFromFile("C:/SFML/TP integrador MAVI/imagenes/alien.png")) {
        std::cerr << "Error al cargar textura de enemigo." << std::endl;
    }
    if (!hostageTexture.loadFromFile("C:/SFML/TP integrador MAVI/imagenes/rehen.png")) {
        std::cerr << "Error al cargar textura de rehén." << std::endl;
    }
    if (!backgroundTexture.loadFromFile("C:/SFML/TP integrador MAVI/imagenes/fondo.png")) {
        std::cerr << "Error al cargar textura de fondo." << std::endl;
    }
}

void escenario::spawnCharacters() {
    // Crear enemigos con posiciones aleatorias
    for (int i = 0; i < maxEnemies; ++i) {
        sf::Vector2f position(
            static_cast<float>(std::rand() % 750), // Aleatorio en X (750 porque queremos margen para el sprite)
            static_cast<float>(std::rand() % 550)  // Aleatorio en Y (550 para margen vertical)
        );
        Personaje enemigo(enemyTexture, true, position);
        enemigo.setScale(0.3f, 0.3f); // Escalar al 50%
        enemies.push_back(enemigo);
    }

    // Crear rehenes con posiciones aleatorias
    for (int i = 0; i < maxHostages; ++i) {
        sf::Vector2f position(
            static_cast<float>(std::rand() % 750), // Aleatorio en X
            static_cast<float>(std::rand() % 550)  // Aleatorio en Y
        );
        Personaje rehen(hostageTexture, false, position);
        rehen.setScale(0.3f, 0.3f); // Escalar al 50%
        hostages.push_back(rehen);
    }
}
void escenario::respawnCharacter(std::vector<Personaje>& characters, bool esEnemigo) {
    for (auto& character : characters) {
        if (!character.estavivo()) {  // Si está marcado como eliminado
            sf::Vector2f newPosition(
                static_cast<float>(std::rand() % 750), // Aleatorio en X
                static_cast<float>(std::rand() % 550)  // Aleatorio en Y
            );
            character = Personaje(esEnemigo ? enemyTexture : hostageTexture, esEnemigo, newPosition);
            character.setScale(0.3f, 0.3f); // Restaurar escala
            break;
        }
    }
}
void escenario::update(sf::RenderWindow& window) {
    // Revivir enemigos y rehenes si fueron eliminados
    respawnCharacter(enemies, true);
    respawnCharacter(hostages, false);
}

void escenario::draw(sf::RenderWindow& window) const {
    window.draw(backgroundSprite); // Dibujar el fondo

    for (const auto& enemy : enemies) {
        enemy.draw(window); // Dibujar cada enemigo vivo
    }

    for (const auto& hostage : hostages) {
        hostage.draw(window); // Dibujar cada rehén vivo
    }
}
std::vector<Personaje>& escenario::getEnemies() {
    return enemies;
}

std::vector<Personaje>& escenario::getHostages() {
    return hostages;
}