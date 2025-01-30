#include "../../libraries.h"

enum entity_types {

    EXAMPLE_ENEMY_A,
    EXAMPLE_ENEMY_B

};

class Entity {

public:

    float posX, posY, rotation;

    Entity(float POS_X, float POS_Y, float ROTATION) {

        posX = POS_X / 10;
        posY = POS_Y / 10;
        rotation = ROTATION;

    }
    ~Entity() {

        //

    }

    void update() {

        //
            
    }

    void draw() {

        //

    }

};