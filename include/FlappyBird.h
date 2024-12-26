#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <string>

// Game parameters
const int window_width = 800;
const int window_height = 600;
float bird_x = 200, bird_y = 300;
float bird_velocity = 0, bird_gravity = -0.5, bird_lift = 10.0;
bool is_jumping = false;
const int max_pipes = 5;
struct Pipe {
    int x;
    int gap_position;
    bool passed;
};
Pipe pipes[max_pipes];
int pipe_gap = 200;
int pipe_width = 80;
float pipe_velocity = -2.0;

// Game state
bool game_over = false;
int num_pipes = 0;
int scoreFlappy = 0;

// Function to draw the bird
void draw_bird() {
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(bird_x - 10, bird_y - 10);
    glVertex2f(bird_x + 10, bird_y - 10);
    glVertex2f(bird_x + 10, bird_y + 10);
    glVertex2f(bird_x - 10, bird_y + 10);
    glEnd();
}

// Function to draw pipes
void draw_pipes() {
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < num_pipes; i++) {
        glBegin(GL_QUADS);
        glVertex2f(pipes[i].x, pipes[i].gap_position + pipe_gap / 2);
        glVertex2f(pipes[i].x + pipe_width, pipes[i].gap_position + pipe_gap / 2);
        glVertex2f(pipes[i].x + pipe_width, window_height);
        glVertex2f(pipes[i].x, window_height);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2f(pipes[i].x, 0);
        glVertex2f(pipes[i].x + pipe_width, 0);
        glVertex2f(pipes[i].x + pipe_width, pipes[i].gap_position - pipe_gap / 2);
        glVertex2f(pipes[i].x, pipes[i].gap_position - pipe_gap / 2);
        glEnd();
    }
}

// Function to draw the scoreFlappy
void draw_score() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(10, window_height - 30);
    std::string score_text = "Score: " + std::to_string(scoreFlappy);
    for (char c : score_text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

// Function to updateFlappy the game state
void updateFlappy(int value) {
    if (!game_over) {
        if (is_jumping) {
            bird_velocity = bird_lift;
            is_jumping = false;
        } else {
            bird_velocity += bird_gravity;
        }
        bird_y += bird_velocity;

        if (bird_y <= 0) {
            bird_y = 0;
            bird_velocity = 0;
        } else if (bird_y >= window_height) {
            bird_y = window_height;
            bird_velocity = 0;
        }

        for (int i = 0; i < num_pipes; i++) {
            pipes[i].x += pipe_velocity;
            if (!pipes[i].passed && pipes[i].x + pipe_width < bird_x) {
                scoreFlappy++;
                pipes[i].passed = true;
            }
        }

        if (num_pipes == 0 || pipes[num_pipes - 1].x < window_width - 300) {
            pipes[num_pipes].x = window_width;
            pipes[num_pipes].gap_position = rand() % (window_height - pipe_gap) + pipe_gap / 2;
            pipes[num_pipes].passed = false;
            num_pipes++;
        }

        if (num_pipes > 0 && pipes[0].x + pipe_width < 0) {
            for (int i = 1; i < num_pipes; i++) {
                pipes[i - 1] = pipes[i];
            }
            num_pipes--;
        }

        for (int i = 0; i < num_pipes; i++) {
            if (bird_x + 10 > pipes[i].x && bird_x - 10 < pipes[i].x + pipe_width) {
                if (bird_y - 10 < pipes[i].gap_position - pipe_gap / 2 || bird_y + 10 > pipes[i].gap_position + pipe_gap / 2) {
                    game_over = true;
                    break;
                }
            }
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateFlappy, 0);
}

// Function to displayFlappy the game
void displayFlappy() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (game_over) {
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2f(window_width / 2 - 50, window_height / 2);
        const char* message = "GAME OVER";
        for (int i = 0; message[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
        }
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(window_width / 2 - 80, window_height / 2 - 40);
        const char* restart_msg = "Press ENTER to Restart";
        for (int i = 0; restart_msg[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, restart_msg[i]);
        }
    } else {
        draw_bird();
        draw_pipes();
        draw_score();
    }

    glFlush();
    glutSwapBuffers();
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }

    if (key == 13) {
        if (game_over) {
            game_over = false;
            bird_x = 200;
            bird_y = 300;
            bird_velocity = 0;
            scoreFlappy = 0;
            num_pipes = 0;

            for (int i = 0; i < max_pipes; i++) {
                pipes[i].x = 0;
                pipes[i].gap_position = 0;
                pipes[i].passed = false;
            }

            glutPostRedisplay();
        }
    }
}

// Function to handle special key input (up arrow for jumping)
void special_keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_UP && !game_over) {
        is_jumping = true;
    }
}

// Function to initialize the game
void initFlappy() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, window_width, 0, window_height, -1, 1);
}

// Function to start the game
void startGame(int argc, char** argv) {
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Flappy Bird in Space");

    initFlappy();

    glutDisplayFunc(displayFlappy);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keyboard);
    glutTimerFunc(25, updateFlappy, 0);

    glutMainLoop();
}

#endif // FLAPPYBIRD_H