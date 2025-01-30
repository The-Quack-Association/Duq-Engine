#include "../../libraries.h"

class Player : public Entity {

public:

    Sprite *sprite;
    float posX, posY, rotation;

    Player(float POS_X, float POS_Y, float ROTATION) : Entity(POS_X, POS_Y, ROTATION) {

        // sprite = new Sprite();

    }
    ~Player() {

        //

    }

    void update() {

        //
            
    }

    void draw() {

        // sprite -> draw();

    }

};