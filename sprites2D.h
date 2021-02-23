#include "libraries.h"

class Player2D {

public:

    float posX, posY, width, height, speed;

    //////////////////////////////
    //// Set Player Variables ////
    //////////////////////////////

    void playerInit(float START_POS_X, float START_POS_Y, float START_WIDTH, float START_HEIGHT, float PLAYER_SPEED,
    int WINDOW_WIDTH, int WINDOW_HEIGHT) {

        posX   = START_POS_X  / WINDOW_WIDTH  * 100;
        posY   = START_POS_Y  / WINDOW_HEIGHT * 100;
        width  = START_WIDTH  / WINDOW_WIDTH  * 100;
        height = START_HEIGHT / WINDOW_HEIGHT * 100;
        speed = PLAYER_SPEED / 5000.0f;

    }

    //////////////////////////////
    ////// Input for Player //////
    //////////////////////////////

    void playerMove(bool UP, bool DOWN, bool LEFT, bool RIGHT) {

        if (UP) {

            if (LEFT) {

                posX = posX - speed;
                posY = posY + speed;

            } else if (RIGHT) {

                posX = posX + speed;
                posY = posY + speed;

            } else {

                posY = posY + speed;

            }

        } else if (DOWN) {

            if (LEFT) {

                posX = posX - speed;
                posY = posY - speed;

            } else if (RIGHT) {

                posX = posX + speed;
                posY = posY - speed;

            } else {

                posY = posY - speed;

            }


        } else if (LEFT) {

            posX = posX - speed;

        } else if (RIGHT) {

            posX = posX + speed;

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