#include "../../libraries.h"

class Scene {

private:

    int map[8][8] = {
                {1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1}
    };

    ResourcePool pool;

    std::vector<Entity> entities;
    Camera camera(0, 0);

    Sprite *player;
    Sprite *arrow;

public:

    Scene(GLuint WIDTH, GLuint HEIGHT) {

        pool.loadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.frag", nullptr, "sprite");
        glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(WIDTH), 0.0f, static_cast<float>(HEIGHT), -1.0f, 1.0f);
        pool.getShader("sprite").use().setInteger("image", 0);
        pool.getShader("sprite").setMatrix4("projection", projection);

        player = new Sprite(0.0f, 0.0f, 0.0f, pool.getShader("sprite"));
        arrow = new Sprite(0.0f, 0.0f, 0.0f, pool.getShader("sprite"));
        pool.loadTexture("resources/textures/test.png", true, "test");
        pool.loadTexture("resources/textures/arrow.png", true, "arrow");

        ;

    }
    ~Scene() {

        //

    }

    

    void draw() {

        pool.getShader("sprite").setMatrix4("projection", camera -> project());

        for (int i = 0; i < entities.size(); i++) {

            entities[i].draw();

        }

    }

};