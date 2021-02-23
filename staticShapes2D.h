#include "libraries.h"

void drawSquare2D(float posX, float posY, float size) {
    glBegin(GL_TRIANGLES);
    
    // Triangle One
    // ◥
    glVertex2f(-size / 2 + posX,  size / 2 + posY); // Top Left Corner
    glVertex2f(-size / 2 + posX, -size / 2 + posY); // Bottom Left Corner (Shared with Triangle Two)
    glVertex2f( size / 2 + posX,  size / 2 + posY); // Top Right Corner (Shared with Triangle Two)
    // Triangle Two
    // ◣
    glVertex2f( size / 2 + posX, -size / 2 + posY); // Bottom Right Corner
    glVertex2f(-size / 2 + posX, -size / 2 + posY); // Bottom Left Corner (Shared with Triangle Two)
    glVertex2f( size / 2 + posX,  size / 2 + posY); // Top Right Corner (Shared with Triangle Two)
    
    glEnd();
}