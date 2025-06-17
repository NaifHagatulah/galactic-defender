#include "../include/CollisionManager.hpp"

void CollisionManager::run(std::vector<std::unique_ptr<GameObject>>& objects) {
	for (size_t i = 0; i < objects.size(); ++i) {
		for (size_t j = i + 1; j < objects.size(); ++j) {
			GameObject& obj1 = *objects[i];
			GameObject& obj2 = *objects[j];
			broadPhase(obj1, obj2);
		}
	}
}

void CollisionManager::broadPhase( GameObject& obj1,  GameObject& obj2) {

	sf::FloatRect r1 = obj1.getPosition();
	sf::FloatRect r2 = obj2.getPosition();

    float x1 = r1.position.x;  
    float y1 = r1.position.y;
    float w1 = r1.size.x;
    float h1 = r1.size.y;

    float x2 = r2.position.x;
    float y2 = r2.position.y;
    float w2 = r2.size.x;
    float h2 = r2.size.y;

   
    bool overlapX = (x1 < x2 + w2)
        && (x1 + w1 > x2);

    
    bool overlapY = (y1 < y2 + h2)
        && (y1 + h1 > y2);

    
    if (overlapX && overlapY) {
        obj1.kill();
        obj2.kill();
    }
	

}

void CollisionManager::narrowPhase(GameObject& obj1, GameObject& obj2) {
	// if needed the side of collision and other spesific stuff, this will not be needed for now
}