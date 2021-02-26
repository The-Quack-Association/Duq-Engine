////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Duq Engine/////////////////////////////////////
///////////////////////////////////Main Game File///////////////////////////////////
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

#include "libraries.h"

int main(int argc, char** argv) {

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CLI Arguments////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    info("Command Line Arguments:");
    extra("Count", std::to_string(argc));
    extra("Arguments Passed", "");

    for (int i = 0; i < argc; ++i) {

        std::cout << WHITE << argv[i] << "\n";

    }


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Configure OpenGL//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    sf::ContextSettings settings;
    info("OpenGL Configured With These Settings:");
    settings.majorVersion = 4;
    settings.minorVersion = 6;
    std::cout << BOLDMAGENTA << "Version:" << WHITE << settings.majorVersion << "." << settings.minorVersion << "\n";
    settings.depthBits = 24;


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////Create Window///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default, settings);
    sf::Event ev; // Create the window event
    info("Created Window With These Settings:");
    extra("Title", windowTitle);
    extra("Width", std::to_string(windowWidth));
    extra("Height", std::to_string(windowHeight));


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Initialize GLEW//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    glewExperimental = true; // Set GLEW to use experimental features

    // Return a message informing whether or not GLEW was able to inititalize
    if (glewInit() != GLEW_OK) {
        error("GLEW Failed to Initialize");
    } else if (glewInit() == GLEW_OK) {
        info("GLEW Initialized Successfully");
    }
    extra("GLEW Experimental", std::to_string(glewExperimental)); // Return a message informing if GLEW Experimental is true

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Create Objects///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    Player2D player0;
    player0.playerInit(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, window.getSize().x, window.getSize().y);

    info("Created Objects");


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////Box2D Stuff/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    b2Vec2 gravity(coordX(0), coordY(-10));
    b2World world(gravity);


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Texture Stuff////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    Material playerTex0;
    playerTex0.setTexture("./images/player.png");

    info("Did the Texture Stuff");


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Game Loop//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen()) {

        while (window.pollEvent(ev)) {

            switch (ev.type) {

                case sf::Event::Closed:

                    window.close();
                    break;

            }

        }


    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////Draw Things onto the Window/////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////
        // Clear the previous frame //
        //////////////////////////////

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        /////////////////////////////
        /// Take Input and Update ///
        /////////////////////////////

        player0.playerMove(

            sf::Keyboard::isKeyPressed(sf::Keyboard::W),
            sf::Keyboard::isKeyPressed(sf::Keyboard::S),
            sf::Keyboard::isKeyPressed(sf::Keyboard::A),
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)

        );


        /////////////////////////////
        ////// Draw stuff here //////
        /////////////////////////////

        player0.playerDraw(playerTex0);


        //////////////////////////////
        //// Background and stuff ////
        //////////////////////////////

        glClearColor(0.2f, 0.2f, 0.26f, 1.0f);


        ////////////////////////////////////////
        // Render everything onto the winodow //
        ////////////////////////////////////////

        window.display();

    }

    return 0;

}
