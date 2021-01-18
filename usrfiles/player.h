#pragma once
#include "../informationType.h"
// Player 1 (player0)
float
// Configure the player's beginning size and position
xtlc = -0.25f,               // Top Left Corner x Coordinate
ytlc = 0.35f,               // Top Left Corner x Coordinate
xbrc = 0.25f,              // Bottom Right Corner x Coordinate
ybrc = -0.35f,            // Bottom Right Corner x Coordinate
xPlayerPos = 0.0f,       // x Player Position
yPlayerPos = 0.0f,      // y Player Position
PlayerSpeed = 1.0f;    // Player speed'

float textCoords[] = {};

// Just some stuff for objects
// You can ignore this for the most part


class Player {

    public:
    
        float
        x_tlc,
        y_tlc,
        x_brc,
        y_brc,
        x_player_pos,
        y_player_pos,
        x_player_speed,
        y_player_speed;

        int port;

        void playerInit(int WINDOW_WIDTH, int WINDOW_HEIGHT, float XTLC, float YTLC, float XBRC, float YBRC, int PLAYER_SPEED) {

            // Adjusts sizes and movement to the screen
            // Ye know
            // So it doesn't do that weird stretching thing
            x_brc = XBRC / float(WINDOW_WIDTH) * 1000; y_brc = ybrc / float(WINDOW_HEIGHT) * 1000;
            x_tlc = xtlc / float(WINDOW_WIDTH) * 1000; y_tlc = ytlc / float(WINDOW_HEIGHT) * 1000;
            x_player_speed = PlayerSpeed / float(WINDOW_WIDTH) * 1000;
            y_player_speed = PlayerSpeed / float(WINDOW_HEIGHT) * 1000;

            // std::cout << WINDOW_WIDTH << "\n" << WINDOW_HEIGHT << "\n"; // Commented out because it's only for debugging

        }

        void player(bool up, bool left, bool down, bool right) {

            static bool initialized = false;
            if (!initialized) {
                std::cout << "Put a thing here but only run it once\n";
                initialized = true;
            }

            // Keyboard input
            if (up) {                                                   // The base for upwards movement
                if (right) {                                            // If the Right key is ALSO pressed then move diagonally
                    x_player_pos = x_player_pos + x_player_speed / 20000;
                    y_player_pos = y_player_pos + y_player_speed / 20000;
                } else if (left) {                                      // If the Left key is ALSO pressed then move diagonally
                    x_player_pos = x_player_pos - x_player_speed / 20000;
                    y_player_pos = y_player_pos + y_player_speed / 20000;
                } else {                                                // If only the Up key is pressed then just move up
                    y_player_pos = y_player_pos + y_player_speed / 20000;
                }
            } else if (down) {                                          // The base for downwards movement
                if (right) {                                            // If the Right key is ALSO pressed then move diagonally
                    x_player_pos = x_player_pos + x_player_speed / 20000;
                    y_player_pos = y_player_pos - y_player_speed / 20000;
                } else if (left) {                                      // If the Left key is ALSO pressed then move diagonally
                    x_player_pos = x_player_pos - x_player_speed / 20000;
                    y_player_pos = y_player_pos - y_player_speed / 20000;
                } else {                                                // If only the Down key is pressed then just move down
                    y_player_pos = y_player_pos - y_player_speed / 20000;
                }
            } else if (right) {                                         // If only the Right key is pressed then just move right
                x_player_pos = x_player_pos + x_player_speed / 20000;
            } else if (left) {                                          // If only the Left key is pressed then just move left
                x_player_pos = x_player_pos - x_player_speed / 20000;
            }

            float x_corner_top_left = x_tlc + x_player_pos; float y_corner_top_left = y_tlc + y_player_pos;
            float x_corner_bottom_right = x_brc + x_player_pos; float y_corner_bottom_right = y_brc + y_player_pos;

            

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

        void netPlayerInit(int PORT) {

            port = 53000;

            sf::TcpSocket socket;
            sf::Socket::Status status = socket.connect("197.0.0.1", port);
            if (status != sf::Socket::Done)
            {
                error("Failed to connect to socket");
            }

        }

        void netPlayer() {

            float x_corner_top_left = x_tlc + x_player_pos; float y_corner_top_left = y_tlc + y_player_pos;
            float x_corner_bottom_right = x_brc + x_player_pos; float y_corner_bottom_right = y_brc + y_player_pos;

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

};

