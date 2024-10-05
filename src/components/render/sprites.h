#include "../../libraries.h"

class Sprite {

public:

    float posX, posY, rotation;
    Model loadedModel;

    void init(float POS_X, float POS_Y, float ROTATION) {

        posX = POS_X / 10;
        posY = POS_Y / 10;
        rotation = ROTATION;

    }

    void loadModel(Model& MODEL) {

        loadedModel = Model(MODEL);

    }

    void draw() {

        loadedModel.verts[0] =
        {
        .x = static_cast<float>((-0.25 * cos(degree2radian(rotation))) - ( 0.25 * sin(degree2radian(rotation)))),
        .y = static_cast<float>((-0.25 * sin(degree2radian(rotation))) + ( 0.25 * cos(degree2radian(rotation))))
        };
        loadedModel.verts[1] =
        {
        .x = static_cast<float>(( 0.25 * cos(degree2radian(rotation))) - ( 0.25 * sin(degree2radian(rotation)))),
        .y = static_cast<float>(( 0.25 * sin(degree2radian(rotation))) + ( 0.25 * cos(degree2radian(rotation))))
        };
        loadedModel.verts[2] =
        {
        .x = static_cast<float>(( 0.25 * cos(degree2radian(rotation))) - (-0.25 * sin(degree2radian(rotation)))),
        .y = static_cast<float>(( 0.25 * sin(degree2radian(rotation))) + (-0.25 * cos(degree2radian(rotation))))
        };
        loadedModel.verts[3] =
        {
        .x = static_cast<float>((-0.25 * cos(degree2radian(rotation))) - (-0.25 * sin(degree2radian(rotation)))),
        .y = static_cast<float>((-0.25 * sin(degree2radian(rotation))) + (-0.25 * cos(degree2radian(rotation))))
        };

        glBegin(GL_POLYGON);
        for (int i = 0; i < loadedModel.vertCount; i++) {

            glVertex2d(loadedModel.verts[i].x, loadedModel.verts[i].y);

        }
        glEnd();

    }

};