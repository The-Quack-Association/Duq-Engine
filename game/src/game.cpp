#include "game.hpp"

Game::Game() { }

void Game::initialize() {

    isRunning = true;

}

void Game::update(float DELTA_TIME) {

    //

}

void Game::draw() {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(
        "My Game",
        20,
        20,
        30,
        DARKGRAY
    );

    EndDrawing();

}

void Game::exit() {

    isRunning = false;
    CloseWindow();

}