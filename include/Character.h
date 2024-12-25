#ifndef CHARACTER_H
#define CHARACTER_H

#include "GlobalVariables.h"

class Character {
private:
    float x;
    float y;
    float speed;
    float size;

public:
    float jumpVelocity;
    float currentJumpVelocity;
    bool isJumping;
    bool moveLeftFlag;
    bool moveRightFlag;
    bool isDead;

    explicit Character(float initialX = charInitialX, float initialY = charInitialY);

    // Setters
    void setX(float x);
    void setY(float y);
    void setJumpVelocity(float velocity);
    void setCurrentJumpVelocity(float velocity);
    void setCharacterDead(bool dead);
    void setJumping(bool jump);
    void setSpeed(float speed);

    // Getters
    [[nodiscard]] float getJumpVelocity() const;
    [[nodiscard]] float getCurrentJumpVelocity() const;
    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;
    [[nodiscard]] bool isCharacterDead() const;
    [[nodiscard]] bool getJumping() const;
    static int getRespawnDelay();
    [[nodiscard]] float getSize() const;
    [[nodiscard]] bool getMoveLeftFlag() const;
    [[nodiscard]] bool getMoveRightFlag() const;
    [[nodiscard]] float getSpeed() const;
    [[nodiscard]] float getWidth() const;
    [[nodiscard]] float getHeight() const;

    void draw() const;
    void specialKeyPressed(int key, int x, int y);
    void specialKeyReleased(int key, int x, int y);
    void moveLeft();
    void moveRight();
    void jump();
};

#endif // CHARACTER_H