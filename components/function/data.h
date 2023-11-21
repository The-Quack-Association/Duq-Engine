#include "../../libraries.h"

class Model {

public:

    struct vector2f *verts;
    int vertCount;

    void loadFile(std::string FILE_LOCATION) {

        std::string x, y;
        std::vector<vector2f> temp; 
	    std::ifstream modelFile;
	    modelFile.open (FILE_LOCATION);

        for (int i = 0; !modelFile.eof(); i++) {

            getline(modelFile, x, ',');
            getline(modelFile, y, '\n');

            temp.push_back(vector2f {std::stof(x), std::stof(y)});

        }
	    modelFile.close();

        verts = new vector2f[temp.size()];
        vertCount = temp.size();
        for (int i = 0; i < temp.size(); i++) {

            verts[i] = temp[i];

        }

    }

};