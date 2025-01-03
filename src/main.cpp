#ifdef _WIN32 // Check if compiling for Windows
#include <windows.h> // Include windows.h for window management (only for Windows)
#include <GL/glut.h>
#elif __APPLE__ // Check if compiling for macOS
#define GL_SILENCE_DEPRECATION // Define GL_SILENCE_DEPRECATION only for macOS to suppress warnings
#include <GLUT/glut.h> // Include GLUT header for OpenGL (for macOS)
#else // Assume Linux or other platforms
#include <GL/glut.h> // Include GLUT header for OpenGL (for Linux)
#endif

#include "GlobalVariables.h"
#include "menu.h"
#include "../include/main.h"

#include "RiverGame.h"
#include "FlappyBird.h"

// Main Function
int main(int argc, char **argv) {
    startRiverGame(argc, argv);
    startFlappyGame(argc, argv);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowFinalX, windowFinalY);
    glutCreateWindow("SUPER MARIO");
    init();
    // sound();
    glutKeyboardFunc(handleKeyboardInput); // Set Menu Keyboard Function
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0); // Start the character movement timer
    glutSpecialFunc(specialKeyPressed); // Set the special key callback function
    glutSpecialUpFunc(specialKeyReleased); // Set the special key release callback function
    glutMainLoop();
    return 0;
}