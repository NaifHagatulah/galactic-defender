// playerMovement.cpp
#include "../include/playerMovement.hpp"
#include <SFML/Graphics.hpp>

// You can customize these “step sizes” however you like:
static constexpr float PLAYER_SPEED = 2.f;

void handlePlayerMovement(const sf::Event& evt, sf::Vector2f& position)
{
    // Try to extract a KeyPressed event; get_if returns nullptr if it's not KeyPressed.
    if (const auto* keyEvt = evt.getIf<sf::Event::KeyPressed>())
    {
        // keyEvt->key is the actual sf::Keyboard::Key enum value
        sf::Keyboard::Key keyCode = keyEvt->code;
        

        // Move based on which arrow was pressed:
        switch (keyCode)
        {
        case sf::Keyboard::Left:
            position.x -= 2.f;
            break;
        case sf::Keyboard::Right:
            position.x += 2.f;
            break;
        case sf::Keyboard::Up:
            position.y -= 2.f;
            break;
        case sf::Keyboard::Down:
            position.y += 2.f;
            break;
        default:
            break;
        }

        // If you need to know if Ctrl was held down:
        bool wasControlHeld = keyEvt->control;
        // …do something with wasControlHeld if needed…
    }
}
