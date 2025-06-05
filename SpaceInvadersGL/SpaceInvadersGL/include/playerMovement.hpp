#pragma once
#include  <SFML/Graphics.hpp>
// Moves the player’s position by inspecting the incoming event.
// - 'evt' is the event you polled from the window.
// - 'position' is the current player position; we pass by reference so we can modify it.
// You could also pass the shape itself, but here we just update the position vector.
void handlePlayerMovement(const sf::Event& evt, sf::Vector2f& position);