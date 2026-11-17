#include "iostream"
#include "raylib.h"
#include "game.hpp"

int main()
{
    InitWindow(800, 600, "My Cross-Platform Game");

    SetTargetFPS(60);

    Game game;

    game.initialize();

    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        game.update(deltaTime);
        game.draw();

    }

    game.exit();

    return 0;
}
