#include "../../libraries.h"

class sprite {

public:

    float width, height, posX, posY, rotation;
    struct vector2d model[4];

    void drawQuadrilateral(float WIDTH, float HEIGHT, float POS_X, float POS_Y, float ROTATION) {

        float posX   = POS_X  * 0.5;
        float posY   = POS_Y  * 0.5;
        float width  = WIDTH  * 0.5;
        float height = HEIGHT * 0.5;

        model[1] =
        {
        .x = (-(width / 2.0f) * cos(degree2radian(ROTATION))) - ( (height / 2.0f) * sin(degree2radian(ROTATION))),
        .y = (-(width / 2.0f) * sin(degree2radian(ROTATION))) + ( (height / 2.0f) * cos(degree2radian(ROTATION)))
        };
        model[2] =
        {
        .x = ( (width / 2.0f) * cos(degree2radian(ROTATION))) - ( (height / 2.0f) * sin(degree2radian(ROTATION))),
        .y = ( (width / 2.0f) * sin(degree2radian(ROTATION))) + ( (height / 2.0f) * cos(degree2radian(ROTATION)))
        };
        model[3] =
        {
        .x = ( (width / 2.0f) * cos(degree2radian(ROTATION))) - (-(height / 2.0f) * sin(degree2radian(ROTATION))),
        .y = ( (width / 2.0f) * sin(degree2radian(ROTATION))) + (-(height / 2.0f) * cos(degree2radian(ROTATION)))
        };
        model[4] =
        {
        .x = (-(width / 2.0f) * cos(degree2radian(ROTATION))) - (-(height / 2.0f) * sin(degree2radian(ROTATION))),
        .y = (-(width / 2.0f) * sin(degree2radian(ROTATION))) + (-(height / 2.0f) * cos(degree2radian(ROTATION)))
        };

        glBegin(GL_POLYGON);
        for (int i = 1; i <= sizeof(model) / sizeof(model[0]); i++) {

            glVertex2d(model[i].x, model[i].y);

        }
        glEnd();

    }

};