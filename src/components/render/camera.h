#include "../../libraries.h"

class Camera {

public:

    int width, height;
    glm::vec3 position;
    float yaw, pitch;
    float zoom;

    Camera(int WIDTH, int HEIGHT, glm::vec3 POSITION = glm::vec3(0.0f, 0.0f, 0.0f), float YAW = 0.0f, float PITCH = 0.0f, float ZOOM = 0.0f) : width(WIDTH), height(HEIGHT), position(POSITION), yaw(YAW), zoom(ZOOM) {

        //

    }

    glm::mat4 project() {

        glm::mat4 projection = glm::ortho(
                                            0.0f + position.x + (zoom * width  / 10.0f),
                       static_cast<float>(width) + position.x - (zoom * width  / 10.0f),
                                            0.0f + position.y + (zoom * height / 10.0f),
                      static_cast<float>(height) + position.y - (zoom * height / 10.0f),
                                           -1.0f, 1.0f);
        return(projection);

    }

};