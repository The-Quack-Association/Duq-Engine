#include "../../libraries.h"

enum game_state {

    GAME_SCENE,
    GAME_TITLE,
    GAME_PAUSE

};

class Game {

public:

    game_state state;
    bool keys[1024];
    GLuint width, height;

    std::map<std::string, Scene> scenes;

    float velocity = 1.0f;

    Game(GLuint WIDTH, GLuint HEIGHT) : width(WIDTH), height(HEIGHT) {

        scenes["test"] = Scene(WIDTH, HEIGHT);

    }
    ~Game() {

        //

    }

    void processInput(float DT) {

        if (glfwJoystickPresent(GLFW_JOYSTICK_1)) {

            float dead = 0.12f;

            int axesCount;
            const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);

            if (axes) {

                glm::vec2 rightStick(axes[3], axes[4]);
                glm::vec2 leftStick(axes[0], axes[1]);

                if (rightStick.x < dead && rightStick.x > -dead)
                    rightStick.x = 0.0f;

                if (rightStick.y < dead && rightStick.y > -dead)
                    rightStick.y = 0.0f;

                if (leftStick.x < dead && leftStick.x > -dead)
                    leftStick.x = 0.0f;

                if (leftStick.y < dead && leftStick.y > -dead)
                    leftStick.y = 0.0f;

                scenes["test"].camera -> position += glm::vec3(rightStick.x, -rightStick.y, 0.0f) * DT * 5.0f;
                camera -> zoom += -leftStick.y * DT / 10.0f;

            }

        }

        //

    }
double time = 0.0f;
float g = 0.0f;
bool a = false;
bool b = false;
bool c = false;
bool d = false;
    void update(float DT) {

        time += DT / 100.0f;
        if (time > 1.0f) {

            if (!a) {

                std::cout << time << std::endl;
                std::cout << g << std::endl;

            }
            a = true;

        }
        if (time > 2.0f) {

            if (!b) {

                std::cout << time << std::endl;
                std::cout << g << std::endl;

            }
            b = true;

        }
        if (time > 3.0f) {

            if (!c) {

                std::cout << time << std::endl;
                std::cout << g << std::endl;

            }
            c = true;

        }
        if (time > 4.0f) {

            time = 0.0f;
            if (!d) {

                std::cout << time << std::endl;
                std::cout << g << std::endl;

            }
            a = false;
            b = false;
            c = false;
            d = false;
            g = 0.0f;

        }

        g += 1.0f * velocity * DT;

        //

    }

    void render() {

        scene

    }

};