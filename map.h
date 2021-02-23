#include "libraries.h"

int mapX = 8; int mapY = 8; int mapN = mapX * mapY;
int mapLayout[] =
{
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,1,0,1,
1,0,0,1,0,0,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1
};

void drawMap2D() {

    int countX;
    int countY;
    int blockX;
    int blockY;

    for (countY = 0; mapY > countY; countY++) {

        for (countX = 0; mapX > countX; countX++) {

            //drawSquare2D();

            if (mapLayout[countY * mapX + countX] == 1) {

                std::cout << "# ";
                glColor3f(1.0f, 0.5f, 0.3f);

            } else if (mapLayout[countY * mapX + countX] == 0) {

                std::cout << "  ";
                glColor3f(0.0f, 0.0f, 0.0f);

            } else if (mapLayout[countY * mapX + countX] == 9) {

                std::cout << "\n";

            }           

            blockX = countX * mapN; blockY = countY * mapN;
            std::cout << blockX << "," << blockY << "\n";

            drawSquare2D(blockX * 0.01f, blockY * 0.01f, 0.2f);

        }

    }    

    glColor3f(1.0f, 0.5f, 0.3f);

}