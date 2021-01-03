////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Duq Engine/////////////////////////////////////
////////////////////////////////Core Game Functions/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////#%&@@@@@@@&%#////////////////////////////////////
///////////////////////////#@@@@@@@@@@@@@@@@@@@@@@@@@@@@%///////////////////////////
//////////////////////%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&//////////////////////
//////////////////#@&%@@@@@@@@@@@@@%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@%./////////////////
///////////////(@@%@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@&///////////////
/////////////@@@%@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,////////////
///////////@@@@&@@@@@@@@@@@@@@@@&@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#//////////
////////.@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*////////
///////&@@@@@@&&@@@@@@&@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&///////
//////%@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//////
////,&@@@@@@@@@%@@@@@@@@@@&@@@&&@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/////
///.&@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&*///
///#@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.//
///@@@@@@@@@@@@@@@@@@@@&%%@@@@@%#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,//
//#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&(******#&@@@@@@@@@@@@@@@@@@@@@@@@@@%//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*&@@@@@@@@@@@@@@%,&@@@@@@@@@@@@@@@@@@@@@&//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(%@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@//
//&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(&@@@@@@@@@@@@@@@@@@@@@@@@#%@@@@@@@@@@@@@@@@@&//
//(@@@@@@@@@#*,/&@@@@@@@@@@@@@@@@@@(&@@@@@@@@@@&/,,(@@@@@@@@@@@&(@@@@@@@@@@@@@@@@,//
// @@@@@@%.       .@@@@@@@@@@@@@@@%%@@@@@@@@@*        (@@@@@@@@@#&@@@@@@@@@@@@@@@,//
///.@@@@@/         #@@@@@@@@@@@@@@##@@@@@@@@&.        ,&@@@@@@@@%%@@@@@@@@@@@@@@////
////*@@@@&,       /@@@@@@@@@@@@@@@%%@@@@@@@@@#       .%@@@@@@@@@#&@@@@@@@@@@@@@#////
/////(@@@@@@@@&@@@@@@@@@@@@@@@@@@@@#&@@@@@@@@@@@@&&@@@@@@@@@@@@#%@@@@@@@@@@@@@&/////
//////#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/@@@@@@@@@@@@@@@@@@@@@@@@,@@@@@@@@@@@@@@&//////
////////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%/@@@@@@@@@@@@@@@@@@@&/&@@@@@@@@@@@@@@,///////
/////////*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%,%@@@@@@@@@@@@#,&@@@@@@@@@@@@@@@#/////////
///////////%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@*#@@@@@@@@@@@@@@@&///////////
/////////////.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(.@@@@@@@@@@@@//////////////
////////////////%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@./@@@@@@&,////////////////
///////////////////*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*,////////////////////
///////////////////////.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*///////////////////////
/////////////////////////////,&@@@@@@@@@@@@@@@@@@@@@@@//////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Imports the SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// Include OpenGL libraries
#include <GL/glew.h>

// Include other libraries
#include <iostream>
#include "usrfiles/camera.h"
#include "usrfiles/player.h"


// Variables
float red = 0;
float green = 0;
float blue = 0;
bool a = false;
float x_corner_top_left;
float y_corner_top_left;
float x_corner_bottom_right;
float y_corner_bottom_right;
int windowWidth;
int windowHeight;

void cameraInit(int X_POS, int Y_POS, int WIDTH, int HEIGHT) {

    windowWidth = WIDTH;
    windowHeight = HEIGHT;

    glViewport(X_POS, Y_POS, WIDTH, HEIGHT);

}

void missingBackground() {
    if (red <= 0) {
            a = true;
        } else if (red >= 1.0f) {
            a = false;
        }
        if (a) {
            red = red + 0.0001f;
            blue = blue + 0.0001f * (1.0f/0.863f);
        } else if (!a) {
            red = red - 0.0001f;
            blue = blue - 0.0001f * (1.0f/0.863f);
        }
}

void playerInit(int WINDOW_WIDTH, int WINDOW_HEIGHT) {

    // Adjusts sizes and movement to the screen
    // Ye know
    // So it doesn't do that weird stretching thing
    xbrc = xbrc / float(WINDOW_WIDTH) * 1000; ybrc = ybrc / float(WINDOW_HEIGHT) * 1000;
    xtlc = xtlc / float(WINDOW_WIDTH) * 1000; ytlc = ytlc / float(WINDOW_HEIGHT) * 1000;
    xPlayerSpeed = xPlayerSpeed / float(WINDOW_WIDTH) * 1000; yPlayerSpeed = yPlayerSpeed / float(WINDOW_HEIGHT) * 1000;

    // std::cout << WINDOW_WIDTH << "\n" << WINDOW_HEIGHT << "\n"; // Commented out because it's only for debugging
}

/*
void camera() {

    // Keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {              // The base for upwards camera movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {          // If the camera Right key is ALSO pressed then move diagonally
            yCameraPos = yCameraPos + 100;
            xCameraPos = xCameraPos + 100;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {   // If the camera Left key is ALSO pressed then move diagonally
            yCameraPos = yCameraPos + 100;
            xCameraPos = xCameraPos - 100;
        } else {                                                    // If only the camera Up key is pressed then just move up
            yCameraPos = yCameraPos + 100;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {       // The base for downwards camera movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {          // If the camera Right key is ALSO pressed then move diagonally
            yCameraPos = yCameraPos - 100;
            xCameraPos = xCameraPos + 100;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {   // If the camera Left key is ALSO pressed then move diagonally
            yCameraPos = yCameraPos - 100;
            xCameraPos = xCameraPos - 100;
        } else {                                                    // If only the camera Down key is pressed then just move down
            yCameraPos = yCameraPos - 100;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {       // If only the camera Right key is pressed then just move right
        xCameraPos = xCameraPos + 100;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {       // If only the camera Left key is pressed then just move left
        xCameraPos = xCameraPos - 100;
    }
    glViewport(xCameraPos, yCameraPos, windowWidth, windowHeight);

}
*/

void player(float X_CORNERTL, float Y_CORNERTL, float X_CORNERBR, float Y_CORNERBR, float X_PLAYER_SPEED, float Y_PLAYER_SPEED) {

    // Keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {              // The base for upwards movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {          // If the Right key is ALSO pressed then move diagonally
            xPlayerPos = xPlayerPos + X_PLAYER_SPEED / 20000;
            yPlayerPos = yPlayerPos + Y_PLAYER_SPEED / 20000;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {   // If the Left key is ALSO pressed then move diagonally
            xPlayerPos = xPlayerPos - X_PLAYER_SPEED / 20000;
            yPlayerPos = yPlayerPos + Y_PLAYER_SPEED / 20000;
        } else {                                                    // If only the Up key is pressed then just move up
            yPlayerPos = yPlayerPos + Y_PLAYER_SPEED / 20000;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {       // The base for downwards movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {          // If the Right key is ALSO pressed then move diagonally
            xPlayerPos = xPlayerPos + X_PLAYER_SPEED / 20000;
            yPlayerPos = yPlayerPos - Y_PLAYER_SPEED / 20000;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {   // If the Left key is ALSO pressed then move diagonally
            xPlayerPos = xPlayerPos - X_PLAYER_SPEED / 20000;
            yPlayerPos = yPlayerPos - Y_PLAYER_SPEED / 20000;
        } else {                                                    // If only the Down key is pressed then just move down
            yPlayerPos = yPlayerPos - Y_PLAYER_SPEED / 20000;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {       // If only the Right key is pressed then just move right
        xPlayerPos = xPlayerPos + X_PLAYER_SPEED / 20000;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {       // If only the Left key is pressed then just move left
        xPlayerPos = xPlayerPos - X_PLAYER_SPEED / 20000;
    }

    float x_corner_top_left = X_CORNERTL + xPlayerPos; float y_corner_top_left = Y_CORNERTL + yPlayerPos;
    float x_corner_bottom_right = X_CORNERBR + xPlayerPos; float y_corner_bottom_right = Y_CORNERBR + yPlayerPos;

    // Triangle One
    // ◤
    glVertex2f(x_corner_top_left, y_corner_top_left); // Top Left Corner
    glVertex2f(x_corner_top_left, y_corner_bottom_right); // Bottom Left Corner (Shared with Triangle Two)
    glVertex2f(x_corner_bottom_right, y_corner_top_left); // Top Right Corner (Shared with Triangle Two)

    // Triangle Two
    // ◢
    glVertex2f(x_corner_bottom_right, y_corner_bottom_right); // Bottom Right Corner
    glVertex2f(x_corner_top_left, y_corner_bottom_right); // Bottom Left Corner (Shared with Triangle Two)
    glVertex2f(x_corner_bottom_right, y_corner_top_left); // Top Right Corner (Shared with Triangle Two)

}