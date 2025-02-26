#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Character.h"

class Obstacle {
private:
    float obsX; // X-coordinate of the obstacle's bottom-left corner
    float obsY; // Y-coordinate of the obstacle's bottom-left corner
    float obsWidth; // Width of the obstacle
    float obsHeight; // Height of the obstacle
    float colorR; // Red component of the obstacle's color
    float colorG; // Green component of the obstacle's color
    float colorB; // Blue component of the obstacle's color

public:
    // Constructor to initialize the obstacle
    Obstacle(const float xPos, const float yPos, const float width, const float height, const float red, const float green, const float blue)
        : obsX(xPos), obsY(yPos), obsWidth(width), obsHeight(height), colorR(red), colorG(green), colorB(blue) {}

    // Function to draw the obstacle using OpenGL
    void draw() const {
        glColor3f(colorR, colorG, colorB);
        glBegin(GL_QUADS);
        glVertex2f(obsX, obsY);
        glVertex2f(obsX + obsWidth, obsY);
        glVertex2f(obsX + obsWidth, obsY + obsHeight);
        glVertex2f(obsX, obsY + obsHeight);
        glEnd();
    }

    // Function to set the color of the obstacle
    void setColor(const float red, const float green, const float blue) {
        colorR = red;
        colorG = green;
        colorB = blue;
    }

    // Function to check collision with the character
    [[nodiscard]] bool checkCollision(const Character& character) const {
        const float charLeft = character.getX();
        const float charRight = character.getX() + character.getWidth();
        const float charTop = character.getY() + character.getHeight();
        const float charBottom = character.getY();

        const float obstacleLeft = obsX;
        const float obstacleRight = obsX + obsWidth;
        const float obstacleTop = obsY + obsHeight;
        const float obstacleBottom = obsY;

        // Check if the character collides with the obstacle
        return !(charRight < obstacleLeft || charLeft > obstacleRight || charTop < obstacleBottom || charBottom > obstacleTop);
    }

    // Getters for the obstacle properties
    [[nodiscard]] inline float getX() const { return obsX; }
    [[nodiscard]] inline float getY() const { return obsY; }
    [[nodiscard]] inline float getWidth() const { return obsWidth; }
    [[nodiscard]] inline float getHeight() const { return obsHeight; }
};

#endif // OBSTACLE_H