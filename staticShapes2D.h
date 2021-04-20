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

    /* top returns the top y
       bottom returns the bottom y
       left returns the left x
       right returns the right x*/ 
    float top, bottom, left, right;

    // Do the math to calculate the positions of each side
    top     =  height / 2.0f + posY;
    bottom  = -height / 2.0f + posY;
    left    = -width  / 2.0f + posX;
    right   =  width  / 2.0f + posX;

    // Perform collision detection
    if (PLAYER.top > bottom && PLAYER.bottom < top && PLAYER.left < right && PLAYER.right > left) {

        if (PLAYER.posX > posX) {

            PLAYER.canMoveLeft  = false;

        } else if (PLAYER.posX < posX) {

            PLAYER.canMoveRight = false;

        } else if (PLAYER.posY < posY) {

            PLAYER.canMoveUp    = false;

        } else if (PLAYER.posY > posY) {

            PLAYER.canMoveDown  = false;

        }

    } else {

        PLAYER.canMoveLeft  = true;
        PLAYER.canMoveRight = true;
        PLAYER.canMoveUp    = true;
        PLAYER.canMoveDown  = true;

    }

}