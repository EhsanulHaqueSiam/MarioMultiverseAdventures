#ifndef Menu_h
#define Menu_h

#include <string>

#include "GlobalVariables.h"

// Handle keyboard inputs
inline void handleKeyboardInput(const unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Spacebar
            isStage1 = true;
        break;
        case 50: // Numpad 2 key
            isStage2 = true;
        break;
        case 51: // Numpad 3 key
            isStage3 = true;
        break;
        case 27: // 'Esc' key
            exit(0);
        break;
        default:
            return;
    }
    glutPostRedisplay(); // Request window redraw
}

// Render text on screen
inline void renderText(const std::string &text, const int x, const int y, void *font, const float r, const float g, const float b) {
    glColor3f(r, g, b);
    glRasterPos2i(x, y);

    for (const char c: text) {
        glutBitmapCharacter(font, c);
    }
}

// Display the menu
inline void displayMenu() {// Draw background rectangle
    glBegin(GL_QUADS);
    glColor3f(0.576f, 0.627f, 0.835f);
    glVertex2f(500.0f, 483.0f);
    glVertex2f(500.0f, 535.0f);
    glVertex2f(785.0f, 535.0f);
    glVertex2f(785.0f, 483.0f);
    glEnd();

    // Draw border
    glBegin(GL_LINE_LOOP);
    glLineWidth(3.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(500.0f, 483.0f);
    glVertex2f(500.0f, 535.0f);
    glVertex2f(785.0f, 535.0f);
    glVertex2f(785.0f, 483.0f);
    glEnd();

    // Render menu text
    renderText("Mario Multiverse Adventure", 560, 500, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("START NEW GAME", 532, 420, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press 'Space' to Start New Game", 475, 380, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    //TODO: When win go to next level
    //TODO: When lose go to game over screen
    //TODO: Press "Esc" to exit the game
    //TODO: when loose come back to main menu
    //TODO: Add description of the game

    renderText("Press '2' to Start Level 2", 500, 350, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press '3' to Start Level 3", 500, 320, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);

    // Render credits
    renderText("Md Ehsanul Haque (22-49370-3)", 460, 160, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Aonyendo Paul Neteish (22-49421-3)", 460, 130, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Souhardo Rahman (22-49068-3)", 460, 100, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Taharat Muhammad Jabir (22-49037-3)", 460, 70, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Md Nasif Safwan (22-49041-3)", 460, 40, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
}


#endif // MENU_H
