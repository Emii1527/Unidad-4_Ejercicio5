#include <iostream>
#include <vector>
#include <ctime>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana con límites de redimensionado");

    // Definir los límites de tamaño
    const unsigned int minWidth = 100;
    const unsigned int minHeight = 100;
    const unsigned int maxWidth = 1000;
    const unsigned int maxHeight = 1000;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Manejar el evento de redimensionado
            if (event.type == sf::Event::Resized)
            {
                // Obtener el nuevo tamaño
                unsigned int newWidth = event.size.width;
                unsigned int newHeight = event.size.height;
                std::cout << "Hola";
                // Verificar y ajustar el tamaño dentro de los límites
                if (newWidth < minWidth) newWidth = minWidth;
                if (newWidth > maxWidth) newWidth = maxWidth;
                if (newHeight < minHeight) newHeight = minHeight;
                if (newHeight > maxHeight) newHeight = maxHeight;

                // Actualizar el tamaño de la ventana solo si cambia
                if (newWidth != event.size.width || newHeight != event.size.height)
                    window.setSize(sf::Vector2u(newWidth, newHeight));


              
            }
        }

        // Limpiar la ventana
        window.clear();

        // Mostrar en pantalla
        window.display();
    }

    return 0;
}
