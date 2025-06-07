
#include <cstdio>

#include <iostream>

#include <SFML/Graphics.hpp>
#include "../include/ResourceManager.hpp"
#include "../include/playerMovement.hpp"
#include "../include/player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 700, 700 }), "SFML works!");
    window.setFramerateLimit(60);
    
    // Load your texture once
   

    // Before the game loop
    ResourceManager::loadTexture("player", "assets\\green.png");
    auto& playerTexture = ResourceManager::getTexture("player");

    // Inside game loop setup
    sf::Sprite playerSprite(playerTexture);
   
    
    sf::Vector2f  position(20.f, 15.f);
    sf::Vector2f velocity(0.f, 0.f);

    

    // Create a player at (100,100) with speed 200 units/sec
    Player player{ playerTexture, position, 100.f };

    player.draw(window);
    

    //playerSprite.setPosition(position*30.f);
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>() || event->is<sf::Event::KeyReleased>())
            {
                player.handleInput(*event);
            }
        }   
        
        playerSprite.move(velocity);

        window.clear(sf::Color(30, 30, 30));
        player.update(dt);
        
        player.draw(window);
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
