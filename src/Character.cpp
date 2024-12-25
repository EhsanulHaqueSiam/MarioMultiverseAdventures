#include "Character.h"
#include <GL/glut.h>

Character::Character(float initialX, float initialY)
    : x(initialX), y(initialY), speed(initialSpeed), jumpVelocity(initialVelocity), size(charSize),
      isJumping(false), currentJumpVelocity(0.0f),
      isDead(false), moveLeftFlag(false), moveRightFlag(false) {
}

// Setters
void Character::setX(float x) { this->x = x; }
void Character::setY(float y) { this->y = y; }
void Character::setJumpVelocity(float velocity) { jumpVelocity = velocity; }
void Character::setCurrentJumpVelocity(float velocity) { currentJumpVelocity = velocity; }
void Character::setCharacterDead(bool dead) { isDead = dead; }
void Character::setJumping(bool jump) { isJumping = jump; }
void Character::setSpeed(float speed) { this->speed = speed; }

// Getters
float Character::getJumpVelocity() const { return jumpVelocity; }
float Character::getCurrentJumpVelocity() const { return currentJumpVelocity; }
float Character::getX() const { return x; }
float Character::getY() const { return y; }
bool Character::isCharacterDead() const { return isDead; }
bool Character::getJumping() const { return isJumping; }
int Character::getRespawnDelay() { return respawnDelay; }
float Character::getSize() const { return size; }
bool Character::getMoveLeftFlag() const { return moveLeftFlag; }
bool Character::getMoveRightFlag() const { return moveRightFlag; }
float Character::getSpeed() const { return speed; }
float Character::getWidth() const { return size; }
float Character::getHeight() const { return size; }

void Character::draw() const {
        // Implementation of draw function
    glColor3f(0.5f, 0.5f, 0.5f); // Set character color to gray

        /*glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
        glEnd();*/

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 5.9f, y + 4.5f);
        glVertex2f(x + 1.1f, y + 4.5f);
        glVertex2f(x + 1.1f, y + 0.7f);
        glVertex2f(x + 19.8f, y + 0.7f);
        glVertex2f(x + 19.9f, y + 7.7f);
        glVertex2f(x + 5.9f, y + 7.7f);
        glVertex2f(x + 5.9f, y + 4.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 53.9f, y + 4.5f);
        glVertex2f(x + 59.0f, y + 4.5f);
        glVertex2f(x + 59.0f, y + 0.8f);
        glVertex2f(x + 40.1f, y + 0.7f);
        glVertex2f(x + 40.3f, y + 7.7f);
        glVertex2f(x + 53.9f, y + 7.7f);
        glVertex2f(x + 53.9f, y + 4.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 10.9f, y + 7.7f);
        glVertex2f(x + 10.9f, y + 11.3f);
        glVertex2f(x + 24.8f, y + 11.3f);
        glVertex2f(x + 24.8f, y + 7.7f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 35.4f, y + 7.7f);
        glVertex2f(x + 35.4f, y + 11.3f);
        glVertex2f(x + 49.8f, y + 11.3f);
        glVertex2f(x + 49.8f, y + 7.7f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 10.9f, y + 11.3f);
        glVertex2f(x + 10.9f, y + 14.8f);
        glVertex2f(x + 49.8f, y + 14.8f);
        glVertex2f(x + 49.8f, y + 11.3f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 49.8f, y + 11.3f);
        glVertex2f(x + 49.8f, y + 22.0f);
        glVertex2f(x + 59.0f, y + 22.0f);
        glVertex2f(x + 59.0f, y + 11.3f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 0.7f, y + 11.3f);
        glVertex2f(x + 10.9f, y + 11.3f);
        glVertex2f(x + 10.9f, y + 22.0f);
        glVertex2f(x + 0.7f, y + 22.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 10.9f, y + 14.8f);
        glVertex2f(x + 10.9f, y + 18.5f);
        glVertex2f(x + 49.8f, y + 18.5f);
        glVertex2f(x + 49.8f, y + 14.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 10.9f, y + 14.8f);
        glVertex2f(x + 10.9f, y + 18.5f);
        glVertex2f(x + 15.3f, y + 18.5f);
        glVertex2f(x + 15.3f, y + 14.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.655, 0.576, 0.055); // yellow
        glVertex2f(x + 20.0f, y + 14.8f);
        glVertex2f(x + 20.0f, y + 18.5f);
        glVertex2f(x + 25.0f, y + 18.5f);
        glVertex2f(x + 25.0f, y + 14.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.655, 0.576, 0.055); // yellow
        glVertex2f(x + 35.0f, y + 14.8f);
        glVertex2f(x + 35.0f, y + 18.5f);
        glVertex2f(x + 40.0f, y + 18.5f);
        glVertex2f(x + 40.0f, y + 14.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 45.0f, y + 14.8f);
        glVertex2f(x + 45.0f, y + 18.5f);
        glVertex2f(x + 49.8f, y + 18.5f);
        glVertex2f(x + 49.8f, y + 14.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.047, 0.043, 0.549); // blue
        glVertex2f(x + 10.8f, y + 18.5f);
        glVertex2f(x + 10.8f, y + 33.3f);
        glVertex2f(x + 49.8f, y + 33.f);
        glVertex2f(x + 49.8f, y + 18.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 20.0f, y + 18.5f);
        glVertex2f(x + 20.0f, y + 33.3f);
        glVertex2f(x + 25.0f, y + 33.3f);
        glVertex2f(x + 25.0f, y + 18.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 25.0f, y + 18.5f);
        glVertex2f(x + 25.0f, y + 22.0f);
        glVertex2f(x + 40.0f, y + 22.0f);
        glVertex2f(x + 40.0f, y + 18.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 35.0f, y + 22.0f);
        glVertex2f(x + 35.0f, y + 33.3f);
        glVertex2f(x + 40.0f, y + 33.3f);
        glVertex2f(x + 40.0f, y + 22.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.047, 0.043, 0.549); // blue
        glVertex2f(x + 5.7f, y + 25.7f);
        glVertex2f(x + 5.7f, y + 29.5f);
        glVertex2f(x + 10.9f, y + 29.5f);
        glVertex2f(x + 10.9f, y + 22.0f);
        glVertex2f(x + 0.7f, y + 22.0f);
        glVertex2f(x + 0.7f, y + 25.7f);
        glVertex2f(x + 5.7f, y + 25.7f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.047, 0.043, 0.549); // blue
        glVertex2f(x + 54.7f, y + 25.7f);
        glVertex2f(x + 54.7f, y + 29.5f);
        glVertex2f(x + 50.0f, y + 29.5f);
        glVertex2f(x + 50.0f, y + 22.0f);
        glVertex2f(x + 59.3f, y + 22.0f);
        glVertex2f(x + 59.3f, y + 25.7f);
        glVertex2f(x + 54.7f, y + 25.7f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 15.7f, y + 33.3f);
        glVertex2f(x + 15.7f, y + 52.5f);
        glVertex2f(x + 45.0f, y + 52.5f);
        glVertex2f(x + 45.0f, y + 33.3f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 10.5f, y + 52.5f);
        glVertex2f(x + 10.5f, y + 56.0f);
        glVertex2f(x + 15.7f, y + 56.0f);
        glVertex2f(x + 15.7f, y + 52.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 15.7f, y + 52.5f);
        glVertex2f(x + 15.7f, y + 59.0f);
        glVertex2f(x + 40.0f, y + 59.0f);
        glVertex2f(x + 40.0f, y + 52.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.58, 0.055, 0.051); // red
        glVertex2f(x + 40.0f, y + 52.5f);
        glVertex2f(x + 40.0f, y + 56.0f);
        glVertex2f(x + 54.0f, y + 56.0f);
        glVertex2f(x + 54.0f, y + 52.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 10.7f, y + 48.5f);
        glVertex2f(x + 10.7f, y + 52.5f);
        glVertex2f(x + 25.0f, y + 52.5f);
        glVertex2f(x + 25.0f, y + 48.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 20.0f, y + 44.5f);
        glVertex2f(x + 20.0f, y + 48.5f);
        glVertex2f(x + 15.7f, y + 48.5f);
        glVertex2f(x + 15.7f, y + 41.0f);
        glVertex2f(x + 25.0f, y + 41.0f);
        glVertex2f(x + 25.0f, y + 44.5f);
        glVertex2f(x + 20.0f, y + 44.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 10.3f, y + 41.0f);
        glVertex2f(x + 10.3f, y + 48.5f);
        glVertex2f(x + 15.7f, y + 48.5f);
        glVertex2f(x + 15.7f, y + 41.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 10.3f, y + 41.0f);
        glVertex2f(x + 10.3f, y + 48.5f);
        glVertex2f(x + 6.0f, y + 48.5f);
        glVertex2f(x + 6.0f, y + 37.4f);
        glVertex2f(x + 15.7f, y + 37.4f);
        glVertex2f(x + 15.7f, y + 41.0f);
        glVertex2f(x + 10.3f, y + 41.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.043, 0.039, 0.024); // black
        glVertex2f(x + 35.4f, y + 44.5f);
        glVertex2f(x + 35.4f, y + 52.5f);
        glVertex2f(x + 40.0f, y + 52.5f);
        glVertex2f(x + 40.0f, y + 44.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 35.4f, y + 37.4f);
        glVertex2f(x + 35.4f, y + 41.0f);
        glVertex2f(x + 54.5f, y + 41.0f);
        glVertex2f(x + 54.5f, y + 37.4f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.212, 0.102, 0.047); // brown
        glVertex2f(x + 40.0f, y + 41.0f);
        glVertex2f(x + 40.0f, y + 44.5);
        glVertex2f(x + 45.0f, y + 44.5f);
        glVertex2f(x + 45.0f, y + 41.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 45.0f, y + 41.0f);
        glVertex2f(x + 45.0f, y + 48.3f);
        glVertex2f(x + 51.0f, y + 48.3f);
        glVertex2f(x + 51.0f, y + 41.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.784, 0.655, 0.533); // skin
        glVertex2f(x + 51.0f, y + 41.0f);
        glVertex2f(x + 51.0f, y + 44.3f);
        glVertex2f(x + 55.5f, y + 44.3f);
        glVertex2f(x + 55.5f, y + 41.0f);
        glEnd();
}

void Character::specialKeyPressed(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            moveLeftFlag = true;
            moveRightFlag = false;
            break;
        case GLUT_KEY_RIGHT:
            moveRightFlag = true;
            moveLeftFlag = false;
            break;
        case GLUT_KEY_UP:
            if (!isJumping) {
                isJumping = true;
                currentJumpVelocity = jumpVelocity;
            }
            break;
        default:
            break;
    }
}

void Character::specialKeyReleased(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            moveLeftFlag = false;
            break;
        case GLUT_KEY_RIGHT:
            moveRightFlag = false;
            break;
        default:
            break;
    }
}

void Character::moveLeft() {
    x -= speed;
    if (x < windowInitialX) {
        x = windowInitialX;
    }
}

void Character::moveRight() {
    x += speed;
    if (isStage1 || isStage2 || isStage3) {
        if (x > 7300) {
            x = 7300;
        }
    }
}

void Character::jump() {
    if (!isJumping) {
        isJumping = true;
        currentJumpVelocity = jumpVelocity;
    }
}