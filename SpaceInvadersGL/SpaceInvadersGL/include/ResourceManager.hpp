#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager {
public:
    // Loads texture from file and stores it under a key
    static void loadTexture(const std::string& name, const std::string& filename);

    // Returns a reference to the stored texture
    static sf::Texture& getTexture(const std::string& name);

    // Optional: Clear all resources (e.g., when resetting game)
    static void clear();

private:
    ResourceManager() = default;

    static std::unordered_map<std::string, sf::Texture> textures;
};

#endif // RESOURCE_MANAGER_HPP