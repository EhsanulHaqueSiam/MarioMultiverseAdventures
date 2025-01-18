#ifndef COVERPAGEOPENGL_H
#define COVERPAGEOPENGL_H


#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "menu.h"
#include "Character.h"
#include "StageComponents.h"
static int windowWidth = 840;  // Scaled width for A4 (210 * 4)
static int windowHeight = 1188; // Scaled height for A4 (297 * 4)
inline Character MarioCoverPage(230,49);

// Main display function
inline void CoverPage() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1843f, 0.1922f, 0.4157f, 1.0f);

    // renderTextWithSize("Adventure", 431, 470, 0.689, 0.992f, 0.737f, 0.694f);
    // renderText("START NEW GAME", 520, 420, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
    renderTextWithSize("COVER PAGE", 33, 120, 0.05, 0.992f, 0.737f, 0.694f);

    renderTextWithSize("American International University - Bangladesh", 10, 115, 0.03, 0.992f, 0.737f, 0.694f);
    renderText("Course Name: Computer Graphics", 32, 110, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Section: F", 34, 105, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Group No: 2", 56, 105, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Project Report On:", 42, 100, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Mario Multiverse Adventure", 35, 96, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Course Name: Computer Graphics", 32, 110, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderTextWithSize("Submitted To:", 38, 85, 0.038, 0.992f, 0.737f, 0.694f);
    renderText("Mahfujur Rahman", 43, 80, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);

    // Scale down the cloud (e.g., scaling by 0.5x in all directions)
    glPushMatrix();  // Save the current matrix
    glScalef(0.14f, 0.14f, 1.0f);  // Scale the cloud by 0.5x on X and Y axes, no scaling on Z axis
    drawCloud(40, 600);  // Draw the scaled-down cloud
    glPopMatrix();  // Restore the original matrix
    // Scale down the cloud (e.g., scaling by 0.5x in all directions)
    glPushMatrix();  // Save the current matrix
    glScalef(0.15f, 0.15f, 1.0f);  // Scale the cloud by 0.5x on X and Y axes, no scaling on Z axis
    drawCloud(46, 600);  // Draw the scaled-down cloud
    glPopMatrix();  // Restore the original matrix


    // Scale down the cloud (e.g., scaling by 0.5x in all directions)
    glPushMatrix();  // Save the current matrix
    glScalef(0.15f, 0.15f, 1.0f);  // Scale the cloud by 0.5x on X and Y axes, no scaling on Z axis
    drawCloud(535, 600);  // Draw the scaled-down cloud
    glPopMatrix();  // Restore the original matrix
    // Scale down the cloud (e.g., scaling by 0.5x in all directions)
    glPushMatrix();  // Save the current matrix
    glScalef(0.14f, 0.14f, 1.0f);  // Scale the cloud by 0.5x on X and Y axes, no scaling on Z axis
    drawCloud(590, 600);  // Draw the scaled-down cloud
    glPopMatrix();  // Restore the original matrix



    renderTextWithSize("Submitted BY:", 38, 72, 0.038, 0.992f, 0.737f, 0.694f);


    // Headers
    renderText("NAME", 13, 65, GLUT_BITMAP_TIMES_ROMAN_24 , 0.992f, 0.737f, 0.694f);
    renderText("ID", 50, 65, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Contribution", 80, 65, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);

    // Person 1: Aonyendo Paul Neteish
    renderText("AONYENDO PAUL NETEISH", 2, 85-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("22-49421-3", 45, 85-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("25%", 85, 85-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);

    // Person 2: Md Ehsanul Haque
    renderText("MD EHSANUL HAQUE", 2, 77-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("22-49370-3", 45, 77-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("25%", 85, 77-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);

    // Person 3: Souhardo Rahman
    renderText("SOUHARDO RAHMAN", 2, 69-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("22-49068-3", 45, 69-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("25%", 85, 69-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);

    // Person 4: Nasif Safwan
    renderText("NASIF SAFWAN", 2, 61-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("22-49041-3", 45, 61-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("25%", 85, 61-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);

    // Person 5: Taharat Muhammad Jabir
    renderText("TAHARAT MUHAMMAD JABIR", 2, 53-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("22-49037-3", 45, 53-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);
    renderText("25%", 85, 53-28, GLUT_BITMAP_HELVETICA_18, 0.992f, 0.737f, 0.694f);



    float addYinBox=0;
    for (int i=0; i<6; i++)
    {
        //header
        glBegin(GL_LINE_LOOP);
        glColor3ub(255, 255, 255);
        glVertex2f(0.1f, 70.0f-addYinBox);
        glVertex2f(105.0f, 70.0f-addYinBox);
        glVertex2f(105.0f, 62.0f-addYinBox);
        glVertex2f(0.1f, 62.0f-addYinBox);
        glEnd();

        addYinBox += 8;

    }

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(35.0f, 70.0f);
    glVertex2f(35.0f, 22.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(70.0f, 70.0f);
    glVertex2f(70.0f, 22.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(14, 12, 94);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(110, 0.0f);
    glVertex2f(110.0f, 10.0f);
    glVertex2f(0.0f, 10.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(105.0f, 0.0f);
    glVertex2f(105.0f, 10.0f);
    glVertex2f(0.1f, 10.0f);
    glEnd();

    renderText("Submitted On: 20 January 2025", 34, 5, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.737f, 0.694f);
    renderText("Press 'M' to go Main Menu", 37, 1, GLUT_BITMAP_TIMES_ROMAN_24, 0.992f, 0.01f, 0.01);


    // Scale the character (e.g., scaling by 2x in all directions)
    glPushMatrix();  // Save the current matrix
    glScalef(0.2f, 0.2f, 0.2f);  // Scale the character by 2x on X and Y axes, no scaling on Z axis
    MarioCoverPage.draw();  // Draw the character
    glPopMatrix();  // Restore the original matrix
    ;

    glFlush();
    glutSwapBuffers();
}

// Main function


inline int CoverPageOpenGL() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Graphics Project_AONYENDO");

    gluOrtho2D(0.0, 105, 0.0, 150.0); // A4 dimensions centered

    // Use a regular function pointer

    glutReshapeFunc([](int, int) {
        glutReshapeWindow(windowWidth, windowHeight);
    });
    glutDisplayFunc(CoverPage);
    glutMainLoop();
    return 0;
}



#endif //COVERPAGEOPENGL_H

