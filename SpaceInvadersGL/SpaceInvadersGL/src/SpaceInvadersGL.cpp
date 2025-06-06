
#include <cstdio>

#include <iostream>

#include <SFML/Graphics.hpp>
#include "../include/playerMovement.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "SFML works!");
    sf::CircleShape shape(50.f);

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("pixil - frame - 0.png")) {
        std::cerr << "Failed to load player.png\n";
        return 1;
    }

    shape.setFillColor(sf::Color::Green);
    sf::Vector2f  position(20.f, 15.f);
    sf::Vector2f velocity(0.f, 0.f);
    shape.setPosition(position);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (event->is<sf::Event::KeyPressed>() || event->is<sf::Event::KeyReleased>())
            {
                handlePlayerMovement(*event, velocity);
            }
        }   
        position += velocity;
        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();

        
        
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
