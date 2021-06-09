#include "libraries.h"

void drawSquare2D(float POS_X, float POS_Y, float SIZE, Material &SHAPE_TEXTURE) {

    float posX   = coordX(POS_X * 100);
    float posY   = coordY(POS_Y * 100);
    float width  = coordX(SIZE  * 100);
    float height = coordY(SIZE  * 100);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    sf::Texture::bind(&SHAPE_TEXTURE.texData);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f); glVertex2f(-width / 2.0f + posX, -height / 2.0f + posY); // ◣ Corner
    glTexCoord2f(1.0f, 0.0f); glVertex2f( width / 2.0f + posX, -height / 2.0f + posY); // ◢ Corner
    glTexCoord2f(1.0f, 1.0f); glVertex2f( width / 2.0f + posX,  height / 2.0f + posY); // ◥ Corner
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-width / 2.0f + posX,  height / 2.0f + posY); // ◤ Corner

    glEnd();

    sf::Texture::bind(NULL);

}

void collideSquare2D(float POS_X, float POS_Y, float SIZE, Player2D &PLAYER) {

    float posX   = coordX(POS_X * 100);
    float posY   = coordY(POS_Y * 100);
    float width  = coordX(SIZE  * 100);
    float height = coordY(SIZE  * 100);

    /*
    top returns the top y
    bottom returns the bottom y
    left returns the left x
    right returns the right x
    */ 
    float top, bottom, left, right;

    /* Returns what side a sprite is on in relation to the object
    0 = not on one specific side
    1 = top
    2 = bottom
    3 = left
    4 = right
    5 = undefined (something horribly wrong has probably happened and you should hide in a bomb shelter immediately)
    */
    int sideOn;

    // Speaks for itself
    float isColliding;

    // Do the math to calculate the positions of each side
    top     =  height / 2.0f + posY;
    bottom  = -height / 2.0f + posY;
    left    = -width  / 2.0f + posX;
    right   =  width  / 2.0f + posX;

    // Perform collision detection
    if (PLAYER.bottom > top && PLAYER.top > bottom && PLAYER.right < left && PLAYER.left < right) {

        sideOn = 0; // if top left

    } else if (PLAYER.bottom > top && PLAYER.top > bottom && PLAYER.left > right && PLAYER.right > left) {

        sideOn = 0; // if top right

    } else if (PLAYER.bottom < top && PLAYER.top < bottom && PLAYER.right < left && PLAYER.left < right) {

        sideOn = 0; // if bottom right

    } else if (PLAYER.bottom < top && PLAYER.top < bottom && PLAYER.left > right && PLAYER.right > left) {

        sideOn = 0; // if bottom left

    } else if (PLAYER.bottom > bottom && PLAYER.right > left && PLAYER.left < right) {

        sideOn = 1; // if top

    } else if (PLAYER.top < top && PLAYER.left < right && PLAYER.right > left) {

        sideOn = 2; // if bottom

    } else if (PLAYER.bottom < top && PLAYER.top > bottom && PLAYER.right < right) {

        sideOn = 3; // if left

    } else if (PLAYER.bottom < top && PLAYER.top > bottom && PLAYER.left > left) {

        sideOn = 4; // if right

    } else {

        sideOn = 5;

    }

    if (PLAYER.top > bottom && PLAYER.bottom < top && PLAYER.left < right && PLAYER.right > left) {
    
        if (sideOn == 1) {

            PLAYER.canMoveDown = false;

        } else if (sideOn == 2) {

            PLAYER.canMoveUp = false;

        } else if (sideOn == 3) {

            PLAYER.canMoveRight = false;

        } else if (sideOn == 4) {

            PLAYER.canMoveLeft = false;

        }

    } else {

        PLAYER.canMoveUp = true;
        PLAYER.canMoveDown = true;
        PLAYER.canMoveLeft = true;
        PLAYER.canMoveRight = true;

    }

    std::cout << sideOn << "\n";

}