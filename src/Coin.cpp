#include "Coin.h"

#include <cmath>
#include <GL/glut.h>

// Constructor to initialize the coin
Coin::Coin(float x, float y, float radius, float red, float green, float blue)
    : x(x), y(y), radius(radius), red(red), green(green), blue(blue), isActive(true), isCollected(false) {}

// Function to draw the coin using OpenGL
void Coin::draw() const {
    if (isActive && !isCollected) {
        const int triangleAmount = 100;
        const float twicePi = 2.0f * PI;

        // Draw outer circle
        glColor3ub(255, 215, 0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                       y + (radius * sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        // Draw inner black line
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius / 2 * cos(i * twicePi / triangleAmount)),
                       y + (radius / 2 * sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        // Draw outer black line
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                       y + (radius * sin(i * twicePi / triangleAmount)));
        }
        glEnd();
    }
}

// Function to check collision with the coin
bool Coin::checkCollision(const Character& character) const {
    float charLeft = character.getX();
    float charRight = character.getX() + character.getWidth();
    float charTop = character.getY() + character.getHeight();
    float charBottom = character.getY();

    float coinLeft = x - radius;
    float coinRight = x + radius;
    float coinTop = y + radius;
    float coinBottom = y - radius;

    return !(charRight < coinLeft || charLeft > coinRight || charTop < coinBottom || charBottom > coinTop);
}

// Function to collect the coin and update the score
void Coin::collect() {
    if (isActive) {
        isActive = false;
        isCollected = true;
        ++score;
    }
}

// Function to check collision between character and coins
void Coin::checkCoinCollision(const Character& character) {
    if (checkCollision(character)) {
        collect();
    }
}