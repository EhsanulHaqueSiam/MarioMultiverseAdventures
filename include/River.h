// river.h
#ifndef RIVER_H
#define RIVER_H

#include "Character.h"

class River {
private:
    float rivX; // X-coordinate of the river's bottom-left corner
    float rivY; // Y-coordinate of the river's bottom-left corner
    float rivWidth; // Width of the river
    float rivHeight; // Height of the river
    float colorR; // Red component of the river's color
    float colorG; // Green component of the river's color
    float colorB; // Blue component of the river's color

public:
    // Constructor to initialize the river
    River(const float xPos, const float yPos, const float width, const float height, const float red, const float green, const float blue)
        : rivX(xPos), rivY(yPos), rivWidth(width), rivHeight(height), colorR(red), colorG(green), colorB(blue) {}

    // Function to draw the river using OpenGL
    void draw() const {
        glColor3f(colorR, colorG, colorB);
        glBegin(GL_QUADS);
        glVertex2f(rivX, rivY);
        glVertex2f(rivX + rivWidth, rivY);
        glVertex2f(rivX + rivWidth, rivY + rivHeight);
        glVertex2f(rivX, rivY + rivHeight);
        glEnd();
    }

    // Function to set the color of the river
    void setColor(const float red, const float green, const float blue) {
        colorR = red;
        colorG = green;
        colorB = blue;
    }

    // Function to check collision with the river
    [[nodiscard]] bool checkRiverCollision(const Character& character) const {
        const float charLeft = character.getX();
        const float charRight = character.getX() + character.getWidth();
        const float charTop = character.getY() + character.getHeight();
        const float charBottom = character.getY();

        const float riverLeft = rivX;
        const float riverRight = rivX + rivWidth;
        const float riverTop = rivY + rivHeight;
        const float riverBottom = rivY;

        // Check if the character collides with the river
        return !(charRight < riverLeft || charLeft > riverRight || charTop < riverBottom || charBottom > riverTop);
    }

    // Getters for the river properties
    [[nodiscard]] inline float getX() const { return rivX; }
    [[nodiscard]] inline float getY() const { return rivY; }
    [[nodiscard]] inline float getWidth() const { return rivWidth; }
    [[nodiscard]] inline float getHeight() const { return rivHeight; }
};

#endif // RIVER_H