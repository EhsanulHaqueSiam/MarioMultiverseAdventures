#ifndef Menu_h
#define Menu_h
#include <string>

#include "StageComponents.h"

#include "GlobalVariables.h"
#include "Character.h"
inline Character hero (100,200);
// Handle keyboard inputs
inline void handleKeyboardInput(const unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Space-bar
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

//render text with scale
inline void renderTextWithSize(const std::string &text, const float x, const float y, const float size, const float r, const float g, const float b) {
    glColor3f(r, g, b);          // Set text color
    glPushMatrix();              // Save the current transformation matrix
    glTranslatef(x, y, 0.0f);    // Move to the specified position
    glScalef(size, size, size);  // Scale the text for desired size

    for (const char c : text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c); // Use stroke font
    }

    glPopMatrix();               // Restore the transformation matrix
}


// Display the menu
inline void displayMenu() {// Draw background rectangle


    // Clouds in the first group
    drawCloud(90.0f, 630.0f);   // First cloud in the first group
    // Clouds in the second group
    drawCloud(400.0f, 580.0f);  // Second cloud in the first group

    // Clouds in the Third group
    drawCloud(1010.0f, 590.0f); // First cloud in the second group
    drawCloud(1050.0f, 550.0f); // Second cloud in the second group
    drawCloud(1050.0f, 620.0f); // Third cloud in the second group
    drawCloud(1100.0f, 590.0f); // Fourth cloud in the second group


    //Hill
    drawHill(50, 500, 300); //2ndt hill
    drawHill(-30, 300, 230); //1st hill
    drawHill(500, 250, 300); //1st hill
    drawHill(900, 350, 400); //1st hill

    //water
    glBegin(GL_QUADS);
    glColor3ub(14, 12, 94);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1300.0f, 0.0f);
    glVertex2f(1300.0f, 100.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();

    //middle water
    glBegin(GL_QUADS);
    glColor3ub(14, 12, 94);
    glVertex2f(250.0f, 100.0f);
    glVertex2f(400.0f, 100.0f);
    glVertex2f(400.0f, 200.0f);
    glVertex2f(0.0f, 200.0f);
    glEnd();

    //Bricks
    glBegin(GL_QUADS);
    glColor3ub(114, 42, 37);
    glVertex2f(0.0f, 100.0f);
    glVertex2f(250.0f, 100.0f);
    glVertex2f(250.0f, 200.0f);
    glVertex2f(0.0f, 200.0f);
    glEnd();
    //draw bricks
    drawBorder(0, 100, 250, 200, 3.0f);
    drawBrickLines(0, 100, 250, 200, 50, 50, 3);

    //2nd Bricks
    glBegin(GL_QUADS);
    glColor3ub(114, 42, 37);
    glVertex2f(400.0f, 100.0f);
    glVertex2f(1300.0f, 100.0f);
    glVertex2f(1300.0f, 200.0f);
    glVertex2f(400.0f, 200.0f);
    glEnd();
    //draw bricks
    drawBorder(400, 100, 1300, 200, 3.0f);
    drawBrickLines(400, 100, 1300, 200, 50, 50, 3);

    //Middle box
    glBegin(GL_QUADS);
    glColor3ub(195, 78, 25);
    glVertex2f(430.0f, 460.0f);
    glVertex2f(830.0f, 460.0f);
    glVertex2f(830.0f, 600.0f);
    glVertex2f(430.0f, 600.0f);

    glEnd();
    drawBorder(430, 460, 830, 600, 3.0f);

    // glBegin(GL_QUADS);
    // glColor3f(0.576f, 0.627f, 0.835f);
    // glVertex2f(0.0f, 0.0f);
    // glVertex2f(200.0f, 0.0f);
    // glVertex2f(200.0f, 200.0f);
    // glVertex2f(0.0f, 200.0f);
    // glEnd();






    // Render menu text

    renderTextWithSize("Mario Multiverse", 431, 555, 0.4, 0.992f, 0.737f, 0.694f);
    renderTextWithSize("Adventure", 431, 470, 0.689, 0.992f, 0.737f, 0.694f);
    renderText("START NEW GAME", 520, 420, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press 'Space' to Start New Game", 475, 380, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    //TODO: When win go to next level
    //TODO: When lose go to game over screen
    //TODO: Press "Esc" to exit the game
    //TODO: when loose come back to main menu
    //TODO: Add description of the game

    renderText("Press '1' to Start Level 1", 500, 350, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press '2' to Start Level 2", 500, 320, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press '3' to Start Level 3", 500, 290, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);

    // Render credits
    renderText("Credits:", 650, 80, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("______", 650, 79, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Md Ehsanul Haque (22-49370-3)", 15, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Aonyendo Paul Neteish (22-49421-3)", 470, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Souhardo Rahman (22-49068-3)", 935, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Taharat Muhammad Jabir (22-49037-3)", 180, 15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Md Nasif Safwan (22-49041-3)", 740, 15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    hero.draw();
}


#endif // MENU_H
