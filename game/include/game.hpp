#pragma once
#include "raylib.h"

class Game {

public:
    Game();

    void initialize();
    void update(float DELTA_TIME);
    void draw();
    void exit();

private:
    bool isRunning = false;

};