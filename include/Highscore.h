//
// Created by heisenberg on 1/19/25.
//

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <algorithm> // For std::sort

#include "Character.h"
#include "DatabaseHandler.h"
#include "StageComponents.h"

// Character declaration
inline Character MarioThe(580, 160);



// Main display function
inline void Highscore() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2392f, 0.5843f, 0.6392f, 1.0f);

    // Clouds in the first group
    drawCloud(90.0f, 630.0f);   // First cloud in the first group
    // Clouds in the second group
    drawCloud(400.0f, 580.0f);  // Second cloud in the first group

    // Clouds in the Third group
    drawCloud(1010.0f, 590.0f); // First cloud in the second group
    drawCloud(1050.0f, 550.0f); // Second cloud in the second group
    drawCloud(1050.0f, 620.0f); // Third cloud in the second group
    drawCloud(1100.0f, 590.0f); // Fourth cloud in the second group

    // Hill
    drawHill(50, 500, 300); // 2nd hill
    drawHill(-30, 300, 230); // 1st hill
    drawHill(500, 250, 300); // 1st hill
    drawHill(900, 350, 400); // 1st hill

    // Water
    glBegin(GL_QUADS);
    glColor3ub(14, 12, 94);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1300.0f, 0.0f);
    glVertex2f(1300.0f, 100.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();

    // Middle water
    glBegin(GL_QUADS);
    glColor3ub(14, 12, 94);
    glVertex2f(250.0f, 100.0f);
    glVertex2f(400.0f, 100.0f);
    glVertex2f(400.0f, 200.0f);
    glVertex2f(0.0f, 200.0f);
    glEnd();

    // Bricks
    glBegin(GL_QUADS);
    glColor3ub(114, 42, 37);
    glVertex2f(0.0f, 100.0f);
    glVertex2f(250.0f, 100.0f);
    glVertex2f(250.0f, 200.0f);
    glVertex2f(0.0f, 200.0f);
    glEnd();
    // Draw bricks
    drawBorder(0, 100, 250, 200, 3.0f);
    drawBrickLines(0, 100, 250, 200, 50, 50, 3);

    // 2nd Bricks
    glBegin(GL_QUADS);
    glColor3ub(114, 42, 37);
    glVertex2f(400.0f, 100.0f);
    glVertex2f(1300.0f, 100.0f);
    glVertex2f(1300.0f, 200.0f);
    glVertex2f(400.0f, 200.0f);
    glEnd();
    // Draw bricks
    drawBorder(400, 100, 1300, 200, 3.0f);
    drawBrickLines(400, 100, 1300, 200, 50, 50, 3);

    // Middle box
    glBegin(GL_QUADS);
    glColor3ub(195, 78, 25);
    glVertex2f(350.0f, 130.0f);
    glVertex2f(890.0f, 130.0f);
    glVertex2f(890.0f, 700.0f);
    glVertex2f(350.0f, 700.0f);
    glEnd();
    drawBorder(350, 130, 890, 700, 3.0f);

    // Text Title
    renderTextWithSize("HighScore", 410, 600, 0.689, 0.992f, 0.737f, 0.694f);

    DatabaseHandler& dbHandler = DatabaseHandler::getInstance();

    // Retrieve and display high scores
    std::vector<std::pair<int, int>> highScores = dbHandler.getHighScores();

    // Sort the scores in descending order based on the second element (score)
    std::sort(highScores.begin(), highScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Descending order
    });

    std::cout << "Top 5 High Scores:" << std::endl;
    int y = 430;
    int count = 0;
    for (const auto& score : highScores) {
        if (count++ >= 5) break; // Show only the top 5 scores

        std::cout << "ID: " << score.first << ", Score: " << score.second << std::endl;

        renderText2("Best Score: " + std::to_string(score.second), 460, y += 30, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    }



    // Render credits
    renderText2("Credits:", 650, 80, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("______", 650, 79, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("Md Ehsanul Haque (22-49370-3)", 15, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("Aonyendo Paul Neteish (22-49421-3)", 470, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("Souhardo Rahman (22-49068-3)", 935, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("Taharat Muhammad Jabir (22-49037-3)", 180, 15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderText2("Md Nasif Safwan (22-49041-3)", 740, 15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);

    renderText2("Press 'Esc' to Return Main Menu", 485, 138, GLUT_BITMAP_HELVETICA_18, 1.0f, 1.0f, 0.01f);

    MarioThe.draw();

    glEnd();

    glFlush();
    glutSwapBuffers();
}

// Function to handle keyboard input
// inline void handleKeyboardInputForInstructions(unsigned char key, int x, int y) {
//     if (key == 27) { // ESC key
//         glutHideWindow();
//         glutPostRedisplay(); // Call glutPostRedisplay after setting the current window
//     }
// }

// Main function for instruction page
inline int HighscorePage() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Instruction Page");

    // Set up viewport and projection
    glViewport(0, 0, 1280, 720);
    gluOrtho2D(0.0f, 1280.0f, 0.0f, 720.0f);

    glutDisplayFunc(Highscore);
    glutKeyboardFunc(handleKeyboardInputForInstructions); // Set the keyboard callback function
    glutMainLoop();
    return 0;
}


#endif //HIGHSCORE_H
