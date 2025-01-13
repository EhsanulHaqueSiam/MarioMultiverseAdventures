#ifndef RIVERGAME_H
#define RIVERGAME_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define MAX_BOMB 3
#include "Character.h"
#include "Coin.h"

// Global variables
inline int border_y = 200;
inline int dividor_y = 220;
inline int finishLine_y = 160;

inline int a = 0;
inline int speed = 1;
inline int steerSpeed = 1;
inline int temp = 0;
inline int seconds = 0;
inline int distance = 178; // finish-line distance
inline int fuel = 178; // fuel amount
float angle = 0.0;

inline int game_state = 0;

inline int lane[MAX_BOMB];
inline int pos[MAX_BOMB];
inline int speeds[MAX_BOMB];
inline int speedsTemp[MAX_BOMB];

inline bool boatMoveLeft = false, boatMoveRight = false, boatMoveFast = false, boatStopped = false;
inline bool reachedEnd = false, gameCompleted = false, fuelOver = false;

inline int boat_x = -15;
inline int boat_y = -150;
inline Character boat(boat_x, boat_y); // Initialize the boat character

inline int fuel_x = 0;
inline int fuel_y = -80;
inline Coin coin(fuel_x, fuel_y, 5, 1, 1, 0); // Initialize the coin

void updateRudder(int value) {
    angle += 2.5; // Increment the angle for smooth rotation
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateRudder, 0); // Call update every 16 milliseconds (~60 FPS)
}

inline void drawTree(void){
    glPushMatrix();
    glLineWidth(3);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(30, 0.0);
    glColor3f(0.0, 0.5, 0.0);
    glVertex2f(0.0, 25);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(-30, 0.0);
    glEnd();
    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_POLYGON);
    glVertex2f(-10, 0.0);
    glVertex2f(10, 0.0);
    glVertex2f(10, -20);
    glVertex2f(-10, -20);
    glEnd();
    glPopMatrix();
    glLineWidth(1);
}


inline void drawRudder(void)
{
    glPushMatrix();
    glLineWidth(3);
    glRotatef(angle, 0, 0, 1.0); // Rotate around the z-axis
    glColor3f(0.878, 0.337, 0.129);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.3, -0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.4, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.3, 0.3);
    glEnd();
    glPopMatrix();
    glLineWidth(1);
}

// Drawing functions
inline void drawBoat() {
    glPushMatrix();
    glScalef(0.5, 0.5, 0);
    glTranslated(boat_x, boat_y, 0.0);
    glScaled(2.5, 2.5, 0);
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(5, -50, 0.0);

    // Draw the boat's outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0, 20.0);
        glVertex2f(12.0, 9.0);
        glVertex2f(12.0, 0.0);
        glVertex2f(-10.0, 0.0);
        glVertex2f(-10.0, 9.0);
    glEnd();

    // Draw the boat's body
    glBegin(GL_QUADS);
        glVertex2f(13.0, 9.0);
        glVertex2f(13.0, -12.0);
        glVertex2f(-11.0, -12.0);
        glVertex2f(-11.0, 9.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0);
    glTranslated(boat_x, boat_y, 0.0);
    boat.draw(); // Draw character on top of boat
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0); // Apply the same scaling
    glTranslated(boat_x, boat_y-150, 0.0); // Apply the same translation
    glScalef(30, 30, 0);
    drawRudder();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0); // Apply the same scaling
    glTranslated(boat_x + 30, boat_y-150, 0.0); // Apply the same translation
    glScalef(30, 30, 0);
    drawRudder();
    glPopMatrix();
}

inline void drawBomb(const int i) {
    glPushMatrix();
    glTranslated((lane[i] - 1) * 37, pos[i], 0.0);
    switch (speeds[i]) {
        case 0: glColor3f(1.0, 0.0, 0.0); break;
        case 1: glColor3f(0.0, 1.0, 0.0); break;
        case 2: glColor3f(0.0, 1.0, 0.0); break;
        case 3: glColor3f(0.0, 1.0, 0.0); break;
    default: ;
    }
    glRectf(-8, 12, 8, 13);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.0, 12.0);
        glVertex2f(6.0, 7.0);
        glVertex2f(6.0, -7.0);
        glVertex2f(10.0, -12.0);
        glVertex2f(-10.0, -12.0);
        glVertex2f(-6.0, -7.0);
        glVertex2f(-6.0, 7.0);
        glVertex2f(-10.0, 12.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.0, 7.0);
        glVertex2f(6.0, -7.0);
        glVertex2f(-6.0, -7.0);
        glVertex2f(-6.0, 7.0);
    glEnd();

    glPopMatrix();
}

inline void drawBorder() {
    int i;
    glPushMatrix();
    glTranslated(60, 0, 0);
    int y = border_y + 20;
    for (i = 0; i < 20; i++) {
        if (a == 0) {
            if (i % 2 == 0)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(1.0, 1.0, 0.0);
        } else {
            if (i % 2 == 1)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(1.0, 1.0, 0.0);
        }
        y -= 20;
        glRectd(5, y, -5, y - 20);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslated(-60, 0, 0);
    y = border_y + 20;
    for (i = 0; i < 20; i++) {
        if (a == 0) {
            if (i % 2 == 0)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(1.0, 1.0, 0.0);
        } else {
            if (i % 2 == 1)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(1.0, 1.0, 0.0);
        }
        y -= 20;
        glRectd(5, y, -5, y - 20);
    }
    glPopMatrix();
}

inline void drawDivider() {
    int y = dividor_y + 80;
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < 8; i++) {
        y -= 80;
        glRectd(22, y, 18, y - 40);
        glRectd(-18, y, -22, y - 40);
    }
}

inline void drawSurroundings() {
    glColor3f(0.71, 0.604, 0.361);
    glRectd(240, 160, 65, -160);
    glRectd(-240, 160, -65, -160);
}

inline void PlaceBomb() {
    for (int i = 0; i < MAX_BOMB; i++) {
        drawBomb(i);
    }
}

inline void draw_string(std::string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *(str.begin() + i));
    }
}

inline void drawMainMenu() {
    glClearColor(0.239, 0.592, 0.859, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    drawBorder();
    drawSurroundings();
    drawDivider();
    drawBoat(); // Draw the boat character
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslated(0, 30, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(50, 15);
        glVertex2f(50, -15);
        glVertex2f(-50, -15);
        glVertex2d(-50, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20, 30, 0);
    glScalef(0.1, 0.1, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    draw_string("START(s)");
    glPopMatrix();
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslated(0, -30, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(50, 15);
        glVertex2f(50, -15);
        glVertex2f(-50, -15);
        glVertex2d(-50, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, -30, 0);
    glScalef(0.1, 0.1, 0.1);
    draw_string("EXIT(esc)");
    glPopMatrix();
}

inline void drawExitMenu() {
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslated(0, 30, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(50, 15);
        glVertex2f(50, -15);
        glVertex2f(-50, -15);
        glVertex2d(-50, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-25, 30, 0);
    glScalef(0.1, 0.1, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    draw_string("RESTART(s)");
    glPopMatrix();
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslated(0, -30, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(50, 15);
        glVertex2f(50, -15);
        glVertex2f(-50, -15);
        glVertex2d(-50, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, -30, 0);
    glScalef(0.1, 0.1, 0.1);
    draw_string("EXIT(esc)");
    glPopMatrix();
}

inline void drawTime(const int clock) {
    int temp = clock;
    int str[20], i = 0;
    while (temp > 0) {
        str[i++] = (temp % 10);
        temp /= 10;
    }
    i--;
    while (i >= 0) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i--] + '0');
    }
    if (clock == 0) glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
}

inline void drawTime() {
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslated(-200, 90, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(50, 15);
        glVertex2f(50, -15);
        glVertex2f(-30, -15);
        glVertex2d(-30, 15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-220, 85, 0);
    glScalef(0.1, 0.1, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    draw_string("Time: ");
    glPopMatrix();

    glPushMatrix();
    glTranslated(-180, 85, 0);
    glScalef(0.1, 0.1, 0.1);
    glColor3f(1.0, 0.0, 0.0);
    drawTime(seconds);
    glPopMatrix();
}

inline void drawDistanceBar() {
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslated(-75, 40, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(5, 90);
        glVertex2f(5, -90);
        glVertex2f(-5, -90);
        glVertex2d(-5, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-75, -49, 0);
    glColor3f(0.9, 0.2, 0.2);
    glRectd(4, 0, -4, distance);
    glPopMatrix();
}

inline void drawFuelBar() {
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslated(75, 40, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(5, 90);
        glVertex2f(5, -90);
        glVertex2f(-5, -90);
        glVertex2d(-5, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(75, -49, 0);
    glColor3f(0, 1, 0);
    glRectd(4, 0, -4, fuel);
    glPopMatrix();
}

inline void drawEnd() {
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0)
            glColor3f(0.0, 0.0, 0.0);
        else
            glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslated(-55, finishLine_y + 10 * i, 0);
        for (int j = 0; j < 11; j++) {
            if (i % 2) {
                if (j % 2 == 0)
                    glColor3f(0.0, 0.0, 0.0);
                else
                    glColor3f(1.0, 1.0, 1.0);
            } else {
                if (j % 2)
                    glColor3f(0.0, 0.0, 0.0);
                else
                    glColor3f(1.0, 1.0, 1.0);
            }
            glRectd(10 * j, 0, 10 * (j + 1), 10);
        }
        glPopMatrix();
    }
}

inline void fuelMessage() {
    glPushMatrix();
    glTranslated(75, -70, 0);
    glScalef(0.1, 0.1, 0.1);
    glColor3f(0, 1.0, 0);
    draw_string("Fuel Exhausted\n");
    glPopMatrix();
}

inline void drawFuel() {
    glPushMatrix();
    glTranslated(fuel_x, fuel_y, 0);
    coin.draw(); // Draw the coin
    glPopMatrix();
}

// Game control functions
inline void stopGame() {
    speed = 0;
    steerSpeed = 0;
}

inline void resumeGame() {
    speed = 2;
    steerSpeed = 1;
}

inline void setBomb() {
    for (int i = 0; i < MAX_BOMB; i++) {
        lane[i] = i;
        pos[i] = 110 + rand() % 100;
        speeds[i] = 1 + i + rand() % 4;
    }
}

inline void moveDivider() {
    dividor_y -= speed;
    if (dividor_y < 120 && distance > 0) {
        dividor_y = 200;
        if (boatMoveFast) {
            distance -= 1.5;
            fuel -= 4;
        } else {
            distance -= 0.5;
            fuel -= 2;
        }
        if (fuel < 0)
            fuelOver = true;
        if (distance < 5)
            reachedEnd = true;
    }
}

inline void moveBoat() {
    if (boatMoveLeft)
        boat_x -= steerSpeed;
    else if (boatMoveRight)
        boat_x += steerSpeed;
    if (boat_x > 65 || boat_x < -95) {
        game_state = 2;
        boatStopped = true;
    }
}

inline void moveBorder() {
    border_y -= speed;
    if (border_y < 160) {
        border_y = 180;
        a = 1 - a;
    }
}

inline void moveOtherBomb() {
    for (int i = 0; i < MAX_BOMB; i++) {
        pos[i] += -speed + speeds[i];
        if (pos[i] < -200 || pos[i] > 200) {
            pos[i] = 200 + rand() % 100;
            speeds[i] = 2 + rand() % 4;
        }
    }
}

inline void moveEnd() {
    if (reachedEnd)
        finishLine_y -= speed;
    if (finishLine_y < -125) {
        boatStopped = true;
        gameCompleted = true;
        game_state = 2;
    }
}

inline void moveFuel() {
    fuel_y -= speed;
    if (fuel_y < -200) {
        fuel_y = 600 + rand() % 150;
        fuel_x = (rand() % 3 - 1) * 37;
    }
}

inline int detectCollision() {
    if (game_state != 1)
        return 0;
    for (int i = 0; i < MAX_BOMB; i++) {
        if (pos[i] < -95 && pos[i] > -200) {
            int limit = (i - 1) * 40;
            if (boat_x < limit + 2 && boat_x > limit - 22) {
                speeds[i] = 0;
                boatStopped = true;
                game_state = 2;
                return 1;
            }
        }
    }
    if ((fuel_x > boat_x && fuel_x - boat_x < 30) || (fuel_x < boat_x && boat_x - fuel_x < 30)) {
        if (fuel_y < -80 && fuel_y > -120) {
            fuel += 40;
            if (fuel > 178)
                fuel = 178;
            fuel_y = 600 + rand() % 150;
            fuel_x = (rand() % 3 - 1) * 37;
        }
    }
    return 0;
}

inline void timerCock(int v) {
    if (boatStopped)
        stopGame();
    else
        resumeGame();
    if (speed != 0) {
        if (boatMoveFast)
            speed = 6;
        else
            speed = 2;
    }
    if (fuelOver) {
        boatStopped = true;
        game_state = 2;
    }
    moveBorder();
    moveDivider();
    moveBoat();
    moveOtherBomb();
    moveEnd();
    moveFuel();
    if (!detectCollision() && !boatStopped && game_state == 1)
        temp += 15;
    if (temp > 1000) {
        temp = 0;
        seconds++;
    }
    glutPostRedisplay();
    glutTimerFunc(10, timerCock, v);
}

// Input handling functions
inline void keyBoardFunc(const int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: boatMoveLeft = true; boatMoveRight = false; break;
        case GLUT_KEY_RIGHT: boatMoveRight = true; boatMoveLeft = false; break;
        case GLUT_KEY_UP: boatMoveFast = true; break;
    default: ;
    }
}

inline void keyboard_up_func(const int k, int x, int y) {
    switch (k) {
        case GLUT_KEY_LEFT: boatMoveLeft = false; break;
        case GLUT_KEY_RIGHT: boatMoveRight = false; break;
        case GLUT_KEY_UP: boatMoveFast = false; break;
    default: ;
    }
}

inline void normalKeyBoardFunc(const unsigned char key, int x, int y) {
    if (game_state == 0) {
        if (key == 13 || key == 's' || key == 'S') {
            setBomb();
            game_state = 1;
        } else if (key == 27) {
            exit(0);
        }
    } else if (game_state == 2) {
        if (key == 's' || key == 'S') {
            boatStopped = false;
            gameCompleted = false;
            reachedEnd = false;
            seconds = 0;
            distance = 178;
            fuel = 178;
            fuelOver = false;
            finishLine_y = 160;
            setBomb();
            game_state = 1;
            boat_x = 0;
        } else if (key == 27) {
            exit(0);
        }
    }
}

// Main display function
inline void level_1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.239, 0.592, 0.859, 0.0);
            glBegin(GL_QUADS);
            glColor3f(0.118, 0.286, 0.678); // Dark Blue
            glVertex2f(-240.0, -160.0);
            glColor3f(0.118, 0.286, 0.678); // Dark Blue
            glVertex2f(240.0, -160.0);
            glColor3f(0.239, 0.592, 0.859); // Light Blue
            glVertex2f(240.0, 160.0);
            glColor3f(0.239, 0.592, 0.859); // Light Blue
            glVertex2f(-240.0, 160.0);
            glEnd();
    switch (game_state) {
        case 1:
            drawBorder();
            drawSurroundings();
            drawDivider();
            drawBoat();
            PlaceBomb();
            drawTime();
            drawDistanceBar();
            drawFuelBar();
            drawFuel();
            break;
        case 0:
            drawMainMenu();
            break;
        case 2:
            drawBorder();
            drawSurroundings();
            drawDivider();
            if (gameCompleted)
                drawEnd();
            if (fuelOver)
                fuelMessage();
            drawBoat();
            PlaceBomb();
            drawDistanceBar();
            drawFuelBar();
            drawExitMenu();
            drawTime();
            break;
        default: ;
    }
    glFlush();
    glutSwapBuffers();
}

// Main function
inline int startRiverGame() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Graphics Project_Souhardo");
    gluOrtho2D(-240.0, 240.0, -160.0, 160.0);
    glutDisplayFunc(level_1);
    glutTimerFunc(100, timerCock, 0);
    glutSpecialFunc(keyBoardFunc);
    glutSpecialUpFunc(keyboard_up_func);
    glutKeyboardFunc(normalKeyBoardFunc);
    glutTimerFunc(16, updateRudder, 0); // Ensure updateRudder is called
    glutReshapeFunc([](int w, int h) { glutReshapeWindow(800, 500); }); // Disable window resizing
    glutMainLoop();
    return 0;
}


#endif //RIVERGAME_H
