#include "libraries.h"

void drawSquare2D(float POS_X, float POS_Y, float SIZE, Material SHAPE_TEXTURE) {

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