#ifndef COIN_H
#define COIN_H

#include "Character.h"

class Coin {
private:
    float x; // X-coordinate of the coin's center
    float y; // Y-coordinate of the coin's center
    float radius; // Radius of the coin
    float red; // Red component of the coin's color
    float green; // Green component of the coin's color
    float blue; // Blue component of the coin's color
    bool isActive; // Flag to check if the coin is active
    bool isCollected; // Flag to check if the coin is collected

public:
    // Constructor to initialize the coin
    Coin(float x, float y, float radius, float red, float green, float blue);

    // Getters for the coin properties
    [[nodiscard]] inline float getX() const { return x; }
    [[nodiscard]] inline float getY() const { return y; }
    [[nodiscard]] inline float getRadius() const { return radius; }
    [[nodiscard]] inline float getRed() const { return red; }
    [[nodiscard]] inline float getGreen() const { return green; }
    [[nodiscard]] inline float getBlue() const { return blue; }

    // Setters for the coin properties
    inline void setX(float newX) { x = newX; }
    inline void setY(float newY) { y = newY; }
    inline void setRadius(float newRadius) { radius = newRadius; }
    inline void setRed(float newRed) { red = newRed; }
    inline void setGreen(float newGreen) { green = newGreen; }
    inline void setBlue(float newBlue) { blue = newBlue; }

    // Function to draw the coin using OpenGL
    void draw() const;

    // Function to check collision with the coin
    [[nodiscard]] bool checkCollision(const Character& character) const;

    // Function to collect the coin and update the score
    void collect();

    // Function to check collision between character and coins
    void checkCoinCollision(const Character& character);
};

#endif // COIN_H