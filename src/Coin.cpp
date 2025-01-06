#include "Coin.h"

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>


// Constructor to initialize the coin
Coin::Coin(const float x, const float y, const float radius, const float red, const float green, const float blue)
    : x(x), y(y), radius(radius), red(red), green(green), blue(blue), isActive(true), isCollected(false) {}

// Function to draw the coin using OpenGL
void Coin::draw() const {
    if (isActive && !isCollected) {
        constexpr int triangleAmount = 100;
        constexpr float twicePi = 2.0f * PI;

        // Draw outer circle
        glColor3ub(255, 215, 0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius * std::cos(i * twicePi / triangleAmount)),
                       y + (radius * std::sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        // Draw inner black line
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius / 2 * std::cos(i * twicePi / triangleAmount)),
                       y + (radius / 2 * std::sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        // Draw outer black line
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= triangleAmount; ++i) {
            glVertex2f(x + (radius * std::cos(i * twicePi / triangleAmount)),
                       y + (radius * std::sin(i * twicePi / triangleAmount)));
        }
        glEnd();
    }
}

// Function to check collision with the coin
bool Coin::checkCollision(const Character& character) const {
    const float charLeft = character.getX();
    const float charRight = character.getX() + character.getWidth();
    const float charTop = character.getY() + character.getHeight();
    const float charBottom = character.getY();

    const float coinLeft = x - radius;
    const float coinRight = x + radius;
    const float coinTop = y + radius;
    const float coinBottom = y - radius;

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