////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Duq Engine/////////////////////////////////////
//////////////////////////////By The Quack Association//////////////////////////////
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

// Import the core game files
#include "game.h"

// Import other things
#include <iostream>
#include "informationType.h"
#include "program/qonsole.h"

// Variables
bool setFullscreen = false;

// The main function
int main() {

    // Sets the settings for OpenGL
    sf::ContextSettings GLsettings;
    info("OpenGL Configured with these settings:");
    GLsettings.depthBits = 24;
    extra("Depth Bits", std::to_string(GLsettings.depthBits));
    GLsettings.majorVersion = 4;
    GLsettings.minorVersion = 6;
    cout << BOLDMAGENTA << "Version" << ": " << WHITE << GLsettings.majorVersion << "." << GLsettings.minorVersion << "\n";

    // Create the window and initialize the event
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Duq Engine", sf::Style::Titlebar | sf::Style::Close, GLsettings);
    sf::Event ev;

    // Initializes GLEW
    glewExperimental = GL_TRUE;
    if (!glewInit) {
        error("Failed to initialize GLEW");
    } else if (glewInit) {
        info("GLEW initialized successfully");
    }

    // Initialize Viewport
    cameraInit(xCameraPos, yCameraPos, window.getSize().x, window.getSize().y);
    info("Set viewport to:");
    extra("Width", std::to_string(windowWidth));
    extra("Height", std::to_string(windowHeight));
    extra("X Position", std::to_string(xCameraPos));
    extra("Y Position", std::to_string(yCameraPos));

    // Just prints the resolution for future reference when debugging
    info("Window created with the resolution of:");
    extra("Width", std::to_string(window.getSize().x));
    extra("Height", std::to_string(window.getSize().y));


    // Initialize players and enemies
    playerInit(window.getSize().x, window.getSize().y);

    // Begins the Developer Qonsole
    // qonsoleBegin(); // Read further down for more info on why this is commented

    // Game loop
    while (window.isOpen()) {

        // Event polling
        while (window.pollEvent(ev)) {

            switch (ev.type) {

            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {

                    window.close();

                }
                break;

            }

        }

        // Qonsole stuff
        // qonsole(); // Because I'm still mediocre at programming I couldn't get this to work properly.
        //               You can try fixing it in /program/qonsole.h
        //               and if you can fix it please put a pull request.
        //               Just please for the love of Wario and all that's holy please don't use classes

        // Clear previous frame
        glClear(GL_COLOR_BUFFER_BIT);

        // Update
        missingBackground();

        glBegin(GL_TRIANGLES);

        // camera();

        // Draw stuff on the screen
        player(xtlc, ytlc, xbrc, ybrc, xPlayerSpeed, yPlayerSpeed);
        glEnd();

        glClearColor(red, green, blue, 1.0f);

        // Render
        window.display();

    }

    // Return 0 to end the process
    return 0;

}