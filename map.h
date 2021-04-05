#include "libraries.h"

int mapX = 9; int mapY = 9; int mapN = mapX * mapY;
int mapLayout[] =
{
1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1
};

void drawMap2D(Material TILE_TEXTURES) {

    int
    countX, countY,
    blockX, blockY,
    centerOffsetX,
    centerOffsetY;

    if (mapX % 2 == 0) {

        centerOffsetX = mapX / 2 + 0.5;

    } else {

        centerOffsetX = mapX / 2;

    }

    if (mapY % 2 == 0) {

        centerOffsetY = mapY / 2 + 0.5;

    } else {

        centerOffsetY = mapY / 2;

    }

    for (countY = 0; mapY > countY; countY++) {

        for (countX = 0; mapX > countX; countX++) {

            //drawSquare2D();

            if (mapLayout[countY * mapX + countX] == 1) {

                glColor3f(1.0f, 0.5f, 0.3f);

            } else if (mapLayout[countY * mapX + countX] == 0) {

                glColor3f(0.0f, 0.0f, 0.0f);

            }

            blockX = countX * mapN; blockY = countY * mapN;

            drawSquare2D(countX - centerOffsetX, countY - centerOffsetY, 1.0f, TILE_TEXTURES);

        }

    }    

    glColor3f(1.0f, 0.5f, 0.3f);

}