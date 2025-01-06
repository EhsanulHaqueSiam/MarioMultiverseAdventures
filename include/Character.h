#ifndef CHARACTER_H
#define CHARACTER_H

#include "GlobalVariables.h"
#include <vector>

class Character {
private:
    float x;
    float y;
    float speed;
    float size;
    int currentFrame;
    int frameCounter;
    std::vector<void (Character::*)() const> walkFrames;
    std::vector<void (Character::*)() const> jumpFrames;

    void drawWalk1() const;
    void drawWalk2() const;
    void drawWalk3() const;
    void drawWalk4() const;
    void drawJump1() const;
    void drawJump2() const;
    void drawJump3() const;
    void drawIdle() const; // New method for idle state

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

    void draw();
    void specialKeyPressed(int key, int x, int y);
    void specialKeyReleased(int key, int x, int y);
    void moveLeft();
    void moveRight();
    void jump();
};

#endif // CHARACTER_H