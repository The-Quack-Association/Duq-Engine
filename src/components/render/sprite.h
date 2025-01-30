#include "../../libraries.h"

class Sprite {

private:

    Shader shader;
    GLuint quadVAO;

public:

    glm::vec3 position;
    float posX, posY, rotation;

    Sprite(float POS_X, float POS_Y, float ROTATION, const Shader &SHADER) : posX(POS_X / 10), posY(POS_Y / 10), rotation(ROTATION), shader(SHADER) {

        GLuint VBO;
        float vertices[24] = {

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f

        };

        glGenVertexArrays(1, &this -> quadVAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(this -> quadVAO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }
    ~Sprite() {

        glDeleteVertexArrays(1, &this -> quadVAO);

    }

    void draw(const Texture &TEXTURE, glm::vec2 POSITION, glm::vec2 SIZE, float ROTATION, glm::vec3 COLOR) {

        posX = POSITION.x;
        posY = POSITION.y;
        rotation = ROTATION;

        this -> shader.use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(POSITION, 0.0f));

        // Flip
        model = glm::scale(model, glm::vec3(1.0f, -1.0f, 1.0f));

        model = glm::translate(model, glm::vec3(0.5f * SIZE.x, 0.5f * SIZE.y, 0.0f));
        model = glm::rotate(model, glm::radians(ROTATION), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-SIZE.x, -SIZE.y, 0.0f));

        model = glm::scale(model, glm::vec3(SIZE, 1.0f));

        this -> shader.setMatrix4("model", model);

        this -> shader.setVector3f("spriteColor", COLOR);

        glActiveTexture(GL_TEXTURE0);
        TEXTURE.bind();

        glBindVertexArray(this -> quadVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

    }

};