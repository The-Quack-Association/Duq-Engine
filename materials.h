#include "libraries.h"

class Material {

public:

    sf::Texture texData;

    std::string imageLocation;

    int width, height;

    void setTexture(std::string IMAGE_LOCATION) {

        imageLocation = IMAGE_LOCATION;

        width = texData.getSize().x; height = texData.getSize().y;

        if (!texData.loadFromFile(imageLocation))
        {

            error("Failed to Load Texture");
            extra("Location", IMAGE_LOCATION);

        }

    }

};