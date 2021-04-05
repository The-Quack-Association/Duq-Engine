#include "libraries.h"

class Player2D {

public:

    float posX, posY, width, height, speedX, speedY;

    //////////////////////////////
    //// Set Player Variables ////
    //////////////////////////////

    void playerInit(float START_POS_X, float START_POS_Y, float START_WIDTH, float START_HEIGHT, float PLAYER_SPEED,
    int WINDOW_WIDTH, int WINDOW_HEIGHT) {

        posX   = coordX(START_POS_X  * 100);
        posY   = coordY(START_POS_Y  * 100);
        width  = coordX(START_WIDTH  * 100);
        height = coordY(START_HEIGHT * 100);
        speedX = coordX(PLAYER_SPEED * 500);
        speedY = coordY(PLAYER_SPEED * 500);

    }

    //////////////////////////////
    ////// Input for Player //////
    //////////////////////////////

    void playerMove(bool UP, bool DOWN, bool LEFT, bool RIGHT, float DELTA_TIME) {

        if (UP) {

            if (LEFT) {

                posX = posX - speedX * DELTA_TIME;
                posY = posY + speedY * DELTA_TIME;

            } else if (RIGHT) {

                posX = posX + speedX * DELTA_TIME;
                posY = posY + speedY * DELTA_TIME;

            } else {

                posY = posY + speedY * DELTA_TIME;

            }

        } else if (DOWN) {

            if (LEFT) {

                posX = posX - speedX * DELTA_TIME;
                posY = posY - speedY * DELTA_TIME;

            } else if (RIGHT) {

                posX = posX + speedX * DELTA_TIME;
                posY = posY - speedY * DELTA_TIME;

            } else {

                posY = posY - speedY * DELTA_TIME;

            }


        } else if (LEFT) {

            posX = posX - speedX * DELTA_TIME;

        } else if (RIGHT) {

            posX = posX + speedX * DELTA_TIME;

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