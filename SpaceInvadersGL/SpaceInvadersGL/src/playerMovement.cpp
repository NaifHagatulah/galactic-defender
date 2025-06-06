// playerMovement.cpp
#include <SFML/Graphics.hpp>
#include "../include/playerMovement.hpp"


// You can customize these “step sizes” however you like:
static constexpr float PLAYER_SPEED = 2.f;

void handlePlayerMovement(const sf::Event& evt, sf::Vector2f& velocity)
{
    // 1) If it’s a KeyPressed event, set the appropriate velocity component:
    if (const auto* keyEvt = evt.getIf<sf::Event::KeyPressed>())
    {

        switch (keyEvt->code)
        {
        case sf::Keyboard::Key::Left:
            velocity.x = -PLAYER_SPEED;
            break;
        case sf::Keyboard::Key::Right:
            velocity.x = PLAYER_SPEED;
            break;
        case sf::Keyboard::Key::Up:
            velocity.y = -PLAYER_SPEED;
            break;
        case sf::Keyboard::Key::Down:
            velocity.y = PLAYER_SPEED;
            break;
        default:
            // If you have other keys (e.g. “Jump”), you can handle them here.
            break;
        }
    }
    // 2) If it’s a KeyReleased event, zero out that component:
    else if (const auto* keyEvt = evt.getIf<sf::Event::KeyReleased>())
    {
        switch (keyEvt->code)
        {
        case sf::Keyboard::Key::Left:
        case sf::Keyboard::Key::Right:
            // Either left or right was released → stop horizontal motion
            velocity.x = 0.f;
            break;
        case sf::Keyboard::Key::Up:
        case sf::Keyboard::Key::Down:
            // Either up or down was released → stop vertical motion
            velocity.y = 0.f;
            break;
        default:
            break;
        }
    }
}
