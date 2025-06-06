#include "../include/ResourceManager.hpp"
#include <iostream>


std::unordered_map<std::string, sf::Texture> ResourceManager::textures;

void ResourceManager::loadTexture(const std::string& name, const std::string& filename) 
{
    if (textures.find(name) == textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(filename)) {
            std::cerr << "Failed to load texture: " << filename << "\n";
            return;
        }
        textures[name] = std::move(texture);
    }
    
}

