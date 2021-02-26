#include "libraries.h"

class Player2D {

public:

    float posX, posY, width, height, speedX, speedY;

    //////////////////////////////
    //// Set Player Variables ////
    //////////////////////////////

    void playerInit(float START_POS_X, float START_POS_Y, float START_WIDTH, float START_HEIGHT, float PLAYER_SPEED,
    int WINDOW_WIDTH, int WINDOW_HEIGHT) {

        posX   = START_POS_X  / WINDOW_WIDTH  * 100;
        posY   = START_POS_Y  / WINDOW_HEIGHT * 100;
        width  = START_WIDTH  / WINDOW_WIDTH  * 100;
        height = START_HEIGHT / WINDOW_HEIGHT * 100;
        speedX = PLAYER_SPEED / WINDOW_WIDTH  / 10;
        speedY = PLAYER_SPEED / WINDOW_HEIGHT / 10;

    }

    //////////////////////////////
    ////// Input for Player //////
    //////////////////////////////

    void playerMove(bool UP, bool DOWN, bool LEFT, bool RIGHT) {

        if (UP) {

            if (LEFT) {

                posX = posX - speedX;
                posY = posY + speedY;

            } else if (RIGHT) {

                posX = posX + speedX;
                posY = posY + speedY;

            } else {

                posY = posY + speedY;

            }

        } else if (DOWN) {

            if (LEFT) {

                posX = posX - speedX;
                posY = posY - speedY;

            } else if (RIGHT) {

                posX = posX + speedX;
                posY = posY - speedY;

            } else {

                posY = posY - speedY;

            }


        } else if (LEFT) {

            posX = posX - speedX;

        } else if (RIGHT) {

            posX = posX + speedX;

        }

    }

    //////////////////////////////
    ////// Draw the Player ///////
    //////////////////////////////

    void playerDraw(Material PLAYER_TEXTURE) {

        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        sf::Texture::bind(&PLAYER_TEXTURE.texData);

        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f); glVertex2f(-width / 2.0f + posX, -height / 2.0f + posY); // ◣ Corner
        glTexCoord2f(1.0f, 0.0f); glVertex2f( width / 2.0f + posX, -height / 2.0f + posY); // ◢ Corner
        glTexCoord2f(1.0f, 1.0f); glVertex2f( width / 2.0f + posX,  height / 2.0f + posY); // ◥ Corner
        glTexCoord2f(0.0f, 1.0f); glVertex2f(-width / 2.0f + posX,  height / 2.0f + posY); // ◤ Corner

        glEnd();

        sf::Texture::bind(NULL);

    }

};

class Ball {

public:

    void collision() {

        

    }

};