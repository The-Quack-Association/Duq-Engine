#include "libraries.h"

class timeClock {

public:

    sf::Clock deltaClock;
    float dt;

    void deltaTimeUpdate() {

        dt = deltaClock.restart().asSeconds();

    }

};