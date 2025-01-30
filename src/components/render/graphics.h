#include "../../libraries.h"

class Shader {

public:

    GLuint ID;

    Shader() {

        //

    }
    ~Shader() {

        //

    }

    Shader& use() {

        glUseProgram(ID);
        return *this;

    }

    void compile(const char *VERTEX_SOURCE, const char *FRAGMENT_SOURCE, const char *GEOMETRY_SOURCE = nullptr) {

        GLuint sVertex, sFragment, gShader;
        int success;
        char infoLog[512];

        // Vertex Shader
        sVertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(sVertex, 1, &VERTEX_SOURCE, NULL);
        glCompileShader(sVertex);
        glGetShaderiv(sVertex, GL_COMPILE_STATUS, &success);
        if(!success) {

            glGetShaderInfoLog(sVertex, 512, NULL, infoLog);
            std::cout << "shader compilation error: \n" << infoLog << std::endl;

        }

        // Fragment Shader
        sFragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(sFragment, 1, &FRAGMENT_SOURCE, NULL);
        glCompileShader(sFragment);
        glGetShaderiv(sFragment, GL_COMPILE_STATUS, &success);
        if(!success) {

            glGetShaderInfoLog(sFragment, 512, NULL, infoLog);
            std::cout << "shader compilation error: \n" << infoLog << std::endl;

        }

        // Geometry Shader (if applicable)
        if (GEOMETRY_SOURCE != nullptr) {

            gShader = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(gShader, 1, &GEOMETRY_SOURCE, NULL);
            glCompileShader(gShader);
            glGetShaderiv(gShader, GL_COMPILE_STATUS, &success);
            if(!success) {

                glGetShaderInfoLog(gShader, 512, NULL, infoLog);
                std::cout << "shader compilation error: \n" << infoLog << std::endl;

            }

        }

        this -> ID = glCreateProgram();
        glAttachShader(this -> ID, sVertex);
        glAttachShader(this -> ID, sFragment);
        if (GEOMETRY_SOURCE != nullptr) {

            glAttachShader(this -> ID, gShader);

        }
        glLinkProgram(this -> ID);

        glDeleteShader(sVertex);
        glDeleteShader(sFragment);
        if (GEOMETRY_SOURCE != nullptr) {

            glDeleteShader(gShader);

        }

    }

    void setFloat(const char *NAME, float VALUE, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform1f(glGetUniformLocation(this -> ID, NAME), VALUE);

    }

    void setInteger(const char *NAME, int VALUE, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform1i(glGetUniformLocation(this -> ID, NAME), VALUE);

    }

    void setVector2f(const char *NAME, float X, float Y, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform2f(glGetUniformLocation(this -> ID, NAME), X, Y);

    }

    void setVector2f(const char *NAME, const glm::vec2 &VALUE, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform2f(glGetUniformLocation(this -> ID, NAME), VALUE.x, VALUE.y);

    }

    void setVector3f(const char *NAME, float X, float Y, float Z, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform3f(glGetUniformLocation(this -> ID, NAME), X, Y, Z);

    }

    void setVector3f(const char *NAME, const glm::vec3 &VALUE, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform3f(glGetUniformLocation(this -> ID, NAME), VALUE.x, VALUE.y, VALUE.z);

    }

    void setVector4f(const char *NAME, float X, float Y, float Z, float W, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform4f(glGetUniformLocation(this -> ID, NAME), X, Y, Z, W);

    }

    void setVector4f(const char *NAME, const glm::vec4 &VALUE, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniform4f(glGetUniformLocation(this -> ID, NAME), VALUE.x, VALUE.y, VALUE.z, VALUE.w);

    }

    void setMatrix4(const char *NAME, const glm::mat4 &MATRIX, bool USE_SHADER = false) {

        if (USE_SHADER) {

            this -> use();

        }

        glUniformMatrix4fv(glGetUniformLocation(this -> ID, NAME), 1, false, glm::value_ptr(MATRIX));

    }

};

class Texture {

public:

    GLuint ID;
    GLuint width, height;
    GLuint internalFormat;
    GLuint imageFormat;
    GLuint wrapS, wrapT;
    GLuint filterMin, filterMag;

    Texture() : width(0), height(0), internalFormat(GL_RGB), imageFormat(GL_RGB), wrapS(GL_REPEAT), wrapT(GL_REPEAT), filterMin(GL_NEAREST), filterMag(GL_NEAREST) {

        glGenTextures(1, &this -> ID);

    }

    void generate(GLuint WIDTH, GLuint HEIGHT, unsigned char* DATA) {

        this -> width = WIDTH;
        this -> height = HEIGHT;

        glBindTexture(GL_TEXTURE_2D, this -> ID);

        glTexImage2D(GL_TEXTURE_2D, 0, this -> internalFormat, WIDTH, HEIGHT, 0, this -> imageFormat, GL_UNSIGNED_BYTE, DATA);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this -> wrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this -> wrapT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this -> filterMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this -> filterMag);

        glBindTexture(GL_TEXTURE_2D, 0);

    }

    void bind() const {

        glBindTexture(GL_TEXTURE_2D, this -> ID);

    }

};

class ResourcePool {

private:

    Shader loadShaderFromFile(const char *V_SHADER_FILE, const char *F_SHADER_FILE, const char *G_SHADER_FILE = nullptr) {

        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;

        try {

            // Open files
            std::ifstream vertexShaderFile(V_SHADER_FILE);
            std::ifstream fragmentShaderFile(F_SHADER_FILE);
            std::stringstream vShaderStream, fShaderStream;

            // Read file's buffer contents into streams
            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();

            // Close file handlers
            vertexShaderFile.close();
            fragmentShaderFile.close();

            // Convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

            // If geometry shader path is present, also load a geometry shader
            if (G_SHADER_FILE != nullptr) {

                std::ifstream geometryShaderFile(G_SHADER_FILE);
                std::stringstream gShaderStream;
                gShaderStream << geometryShaderFile.rdbuf();
                geometryShaderFile.close();
                geometryCode = gShaderStream.str();

            }

        } catch (std::exception e) {

            std::cout << "error reading shader files" << std::endl;

        }

        const char *vShaderCode = vertexCode.c_str();
        const char *fShaderCode = fragmentCode.c_str();
        const char *gShaderCode = geometryCode.c_str();

        Shader flagShader;
        flagShader.compile(vShaderCode, fShaderCode, G_SHADER_FILE != nullptr ? gShaderCode : nullptr);
        return flagShader;

    }

    Texture loadTextureFromFile(const char *FILE, bool ALPHA) {

        Texture texture;
        if (ALPHA) {

            texture.internalFormat = GL_RGBA;
            texture.imageFormat = GL_RGBA;

        }

        // Load image file
        int width, height, nrChannels;
        unsigned char* data = stbi_load(FILE, &width, &height, &nrChannels, 0);

        // Generate texture
        texture.generate(width, height, data);

        // Free image data
        stbi_image_free(data);
        return texture;

    }

public:

    std::map<std::string, Shader> shaders;
    std::map<std::string, Texture> textures;

    ResourcePool() {

        //

    }
    ~ResourcePool() {

        for (auto iter : shaders) {

            glDeleteProgram(iter.second.ID);

        }

        for (auto iter : textures) {

            glDeleteTextures(1, &iter.second.ID);

        }

    }

    Shader loadShader(const char *V_SHADER_FILE, const char *F_SHADER_FILE, const char *G_SHADER_FILE, std::string NAME) {

        shaders[NAME] = loadShaderFromFile(V_SHADER_FILE, F_SHADER_FILE, G_SHADER_FILE);
        return shaders[NAME];

    }

    Shader getShader(std::string NAME) {

        return shaders[NAME];

    }

    Texture getTexture(std::string NAME) {

        return textures[NAME];

    }

    Texture loadTexture(const char *FILE, bool ALPHA, std::string NAME) {

        textures[NAME] = loadTextureFromFile(FILE, ALPHA);
        return textures[NAME];

    }

    Texture loadTexture(std::string NAME) {

        return textures[NAME];

    }

    void clear() {

        for (auto iter : shaders) {

            glDeleteProgram(iter.second.ID);

        }

        for (auto iter : textures) {

            glDeleteTextures(1, &iter.second.ID);

        }

    }

};