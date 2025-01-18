#ifndef Menu_h
#define Menu_h
#include <string>
#include <thread>
#include <chrono>

#include "AudioManager.h"
#include "StageComponents.h"

#include "GlobalVariables.h"
#include "Character.h"
#include "CoverPageOpenGL.h"
#include "InstructionPage.h"
inline Character hero (100,200);
// Handle keyboard inputs
inline void handleKeyboardInput(const unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Space-bar
        case 49: // Numpad 1 key
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

// Mouse click handling
inline void handleMouseClick(const int button, const int state, const int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            // Convert mouse coordinates to OpenGL coordinates
            const int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            y = windowHeight - y;

            // Check if the click is level-1
            if (x >= 500 && x <= 760 && y >= 375 && y <= 400) {
                isStage1 = true;
                isStage2 = false;
                isStage3 = false;
                glutPostRedisplay();
            }
            // Check if the click is level-2
            else if (x >= 500 && x <= 760 && y >= 345 && y <= 370) {
                isStage2 = true;
                isStage1 = false;
                isStage3 = false;
                glutPostRedisplay();
            }
            // Check if the click is level-3
            else if (x >= 500 && x <= 760 && y >= 315 && y <= 340) {
                isStage3 = true;
                isStage1 = false;
                isStage2 = false;
                glutPostRedisplay();
            }
            // Check if the click is Sound On
            else if (x >= 440 && x <= 500 && y >= 205 && y <= 250) {    // Handle Sound On click

                AudioManager::getInstance().unmute();

                glutPostRedisplay();
            }
            // Check if the click is Sound Off
            else if (x >= 740 && x <= 800 && y >= 205 && y <= 250) {    // Handle Sound Off click


                AudioManager::getInstance().mute();

                glutPostRedisplay();
            }
            // Check if click is on Instructions
            else if (x >= 570 && x <= 690 && y >= 240 && y <= 265) {    //Open instructions window

                InstructionPage();
                glutPostRedisplay();
            }
            // Check if click is on ESC
            else if (x >= 530 && x <= 725 && y >= 275 && y <= 300) {
                exit(0);
                glutPostRedisplay();
            }
            else if (x >= 570 && x <= 690 && y >= 210 && y <= 235) {
                CoverPageOpenGL();
                glutPostRedisplay();

            }
        }
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

    //Start New Game Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(510.0f, 440.0f);
    glVertex2f(510.0f, 415.0f);
    glVertex2f(750.0f, 415.0f);
    glVertex2f(750.0f, 440.0f);
    glEnd();

    //Start 1 game Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(500.0f, 400.0f);
    glVertex2f(500.0f, 375.0f);
    glVertex2f(760.0f, 375.0f);
    glVertex2f(760.0f, 400.0f);
    glEnd();

    //Start 2 game Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(500.0f, 370.0f);
    glVertex2f(500.0f, 345.0f);
    glVertex2f(760.0f, 345.0f);
    glVertex2f(760.0f, 370.0f);
    glEnd();

    //Start 3 game Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(500.0f, 340.0f);
    glVertex2f(500.0f, 315.0f);
    glVertex2f(760.0f, 315.0f);
    glVertex2f(760.0f, 340.0f);
    glEnd();

    //Exit Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(530.0f, 300.0f);
    glVertex2f(530.0f, 275.0f);
    glVertex2f(725.0f, 275.0f);
    glVertex2f(725.0f, 300.0f);
    glEnd();

    //Instruction Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(570.0f, 265.0f);
    glVertex2f(570.0f, 240.0f);
    glVertex2f(690.0f, 240.0f);
    glVertex2f(690.0f, 265.0f);
    glEnd();

    //Cover Page Background
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(570.0f, 235.0f);
    glVertex2f(570.0f, 210.0f);
    glVertex2f(690.0f, 210.0f);
    glVertex2f(690.0f, 235.0f);
    glEnd();

    //Sound On Background
    glBegin(GL_QUADS);
    glColor3ub(200, 255, 255);
    glVertex2f(440.0f, 250.0f);
    glVertex2f(440.0f, 205.0f);
    glVertex2f(500.0f, 205.0f);
    glVertex2f(500.0f, 250.0f);
    glEnd();

    //Sound ON back
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(450.0f, 230.0f);
    glVertex2f(450.0f, 220.0f);
    glVertex2f(460.0f, 220.0f);
    glVertex2f(460.0f, 230.0f);
    glEnd();

    //Sound ON front
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(460.0f, 230.0f);
    glVertex2f(460.0f, 220.0f);
    glVertex2f(470.0f, 210.0f);
    glVertex2f(470.0f, 240.0f);
    glEnd();

    //Sound On line Start
    glBegin(GL_LINES);
    glColor3ub(0, 42, 37);
    glVertex2f(475.0f, 230.0f);
    glVertex2f(490.0f, 240.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 42, 37);
    glVertex2f(475.0f, 225.0f);
    glVertex2f(495.0f, 225.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 42, 37);
    glVertex2f(475.0f, 220.0f);
    glVertex2f(490.0f, 210.0f);
    glEnd();

    //Sound On line end

    //Sound Off Background
    glBegin(GL_QUADS);
    glColor3ub(200, 255, 255);
    glVertex2f(740.0f, 250.0f);
    glVertex2f(740.0f, 205.0f);
    glVertex2f(800.0f, 205.0f);
    glVertex2f(800.0f, 250.0f);
    glEnd();

    //Sound Off back
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(750.0f, 230.0f);
    glVertex2f(750.0f, 220.0f);
    glVertex2f(760.0f, 220.0f);
    glVertex2f(760.0f, 230.0f);
    glEnd();

    //Sound Off front
    glBegin(GL_QUADS);
    glColor3ub(0, 42, 37);
    glVertex2f(760.0f, 230.0f);
    glVertex2f(760.0f, 220.0f);
    glVertex2f(770.0f, 210.0f);
    glVertex2f(770.0f, 240.0f);
    glEnd();

    //Sound OFF line
    glLineWidth(50.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 42, 37);
    glVertex2f(745.0f, 210.0f);
    glVertex2f(785.0f, 240.0f);
    glEnd();





    // Render menu text

    renderTextWithSize("Mario Multiverse", 431, 555, 0.4, 0.992f, 0.737f, 0.694f);
    renderTextWithSize("Adventure", 431, 470, 0.689, 0.992f, 0.737f, 0.694f);
    renderText("START NEW GAME", 520, 420, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press 'Esc' to Exit", 535, 280, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Instruction", 575, 245, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Cover Page", 574, 215, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    // renderText("Sound On", 535, 280, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    // renderText("Sound Off", 535, 280, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);

    renderText("Press '1' to Start Level 1", 510, 380,GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press '2' to Start Level 2", 510, 350,GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText("Press '3' to Start Level 3", 510, 320, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    //TODO: When win go to next level
    //TODO: When lose go to game over screen
    //TODO: Press "Esc" to exit the game
    //TODO: when loose come back to main menu
    //TODO: Add description of the game



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