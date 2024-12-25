//
// Created by heisenberg on 12/25/24.
//

#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>

#include "Character.h"
#include "Coin.h"
#include "Obstacle.h"
#include "River.h"
#include "StageComponents.h"

inline Character playerCharacter;

inline std::vector<Obstacle> obstacles;
inline std::vector<River> rivers;


// Stage 01 Coins
inline Coin coin1(1050.0f, 437.0f, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin2(1385, 218, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin3(2252, 320, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin4(2252, 380, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin5(4014, 520, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin6(4526, 336, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin7(4525, 560, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin8(5102, 267, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin9(5246, 267, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin10(5390, 267, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin11(5246, 462, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin


// Stage 02 Coins
inline Coin coin41(540, 230, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin42(830, 330, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin43(950, 530, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin44(1240, 190, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin45(1430, 390, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin46(1835, 540, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin47(2000, 540, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin48(2445, 190, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin49(2885, 190, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin50(3255, 335, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin51(3670, 490, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin52(3850, 490, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin53(4290, 440, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin54(4865, 290, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin55(5280, 490, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin56(5410, 490, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin57(5555, 490, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin58(5890, 190, 20.0f, 1.0f, 0.843f, 0.0f);
inline Coin coin59(6270, 330, 20.0f, 1.0f, 0.843f, 0.0f);


// Stage 03 Coins
inline Coin coin14(1230, 335, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin15(1290, 460, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin16(1410, 460, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin17(1470, 335, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin18(1870, 375, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin19(1950, 375, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin20(2020, 375, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin21(2180, 375, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin22(2270, 375, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin23(2690, 355, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin24(2900, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin25(2965, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin26(3030, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin27(3260, 300, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin28(3480, 300, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin29(4270, 300, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin30(4410, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin31(4485, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin32(4560, 435, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin33(4690, 300, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin34(4990, 340, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin35(5055, 340, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin36(5300, 340, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin37(5365, 340, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin38(5830, 390, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin39(5905, 390, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin
inline Coin coin40(5980, 390, 20.0f, 1.0f, 0.843f, 0.0f); // Yellow coin


inline void cameraMovement() {
    // Calculate the camera's position to center the stage around the character
    float cameraX = -(playerCharacter.getX() - windowFinalX / 2);
    float cameraY = 0.0f; // Keep a fixed Y position for the camera
    float cameraZ = 0.0f; // Set a suitable Z position for the camera (you can adjust this based on your scene)

    // Apply the translation transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(cameraX, cameraY, cameraZ);
}


// Function to check collision with all the obstacles and the river
inline bool checkAllObstacleCollisions(Character playerCharacter) {
    for (const auto &obstacle: obstacles) {
        if (obstacle.checkCollision(playerCharacter)) {
            return true;
        }
    }
    return false; // No collision
}


// Function to check collision with all the river
inline bool checkAllRiverCollisions(Character playerCharacter) {
    for (const auto &river: rivers) {
        if (river.checkRiverCollision(playerCharacter)) {
            return true;
        }
    }
    return false; // No Collision
}


// Function to respawn the character after a delay
inline void respawnCharacter(int value) {
    lives--;

    playerCharacter.setCharacterDead(false);
    // Set the character's position to the starting position
    playerCharacter.setX(charInitialX);
    playerCharacter.setY(charInitialY);
    // Reset jump state and velocity
    playerCharacter.setJumping(false);
    playerCharacter.setCurrentJumpVelocity(0.0f);
    glutPostRedisplay(); // Mark the window for a redraw
}


//Function to show Scoreboard
inline void drawScoreboard(int characterX) {
    int scoreboardX = characterX - windowFinalX / 2;
    int scoreboardY = 10; // Adjust this as needed

    // Draw the scoreboard at the calculated position
    renderText("Score: " + std::to_string(score), scoreboardX, scoreboardY, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
}


//Function to show Lives
inline void drawLives(int characterX) {
    int livesX = characterX - windowFinalX / 2;
    int livesY = 40; // Adjust this as needed


    renderText("Lives: " + std::to_string(lives), livesX, livesY, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
}


//Update function
inline void update(int value) {
    // Store the current character position for collision checking
    float prevCharacterX = playerCharacter.getX();
    float prevCharacterY = playerCharacter.getY();


    if (isStage1) {
        // Stage 01 Coins
        coin1.checkCoinCollision(playerCharacter);
        coin2.checkCoinCollision(playerCharacter);
        coin3.checkCoinCollision(playerCharacter);
        coin4.checkCoinCollision(playerCharacter);
        coin5.checkCoinCollision(playerCharacter);
        coin6.checkCoinCollision(playerCharacter);
        coin7.checkCoinCollision(playerCharacter);
        coin8.checkCoinCollision(playerCharacter);
        coin9.checkCoinCollision(playerCharacter);
        coin10.checkCoinCollision(playerCharacter);
        coin11.checkCoinCollision(playerCharacter);
    }

    if (isStage2) {
        // Stage 02 Coins
        coin41.checkCoinCollision(playerCharacter);
        coin42.checkCoinCollision(playerCharacter);
        coin43.checkCoinCollision(playerCharacter);
        coin44.checkCoinCollision(playerCharacter);
        coin45.checkCoinCollision(playerCharacter);
        coin46.checkCoinCollision(playerCharacter);
        coin47.checkCoinCollision(playerCharacter);
        coin48.checkCoinCollision(playerCharacter);
        coin49.checkCoinCollision(playerCharacter);
        coin50.checkCoinCollision(playerCharacter);
        coin51.checkCoinCollision(playerCharacter);
        coin52.checkCoinCollision(playerCharacter);
        coin53.checkCoinCollision(playerCharacter);
        coin54.checkCoinCollision(playerCharacter);
        coin55.checkCoinCollision(playerCharacter);
        coin56.checkCoinCollision(playerCharacter);
        coin57.checkCoinCollision(playerCharacter);
        coin58.checkCoinCollision(playerCharacter);
        coin59.checkCoinCollision(playerCharacter);
    }

    if (isStage3) {
        // Stage 03 Coins
        coin14.checkCoinCollision(playerCharacter);
        coin15.checkCoinCollision(playerCharacter);
        coin16.checkCoinCollision(playerCharacter);
        coin17.checkCoinCollision(playerCharacter);
        coin18.checkCoinCollision(playerCharacter);
        coin19.checkCoinCollision(playerCharacter);
        coin20.checkCoinCollision(playerCharacter);
        coin21.checkCoinCollision(playerCharacter);
        coin22.checkCoinCollision(playerCharacter);
        coin23.checkCoinCollision(playerCharacter);
        coin24.checkCoinCollision(playerCharacter);
        coin25.checkCoinCollision(playerCharacter);
        coin26.checkCoinCollision(playerCharacter);
        coin27.checkCoinCollision(playerCharacter);
        coin28.checkCoinCollision(playerCharacter);
        coin29.checkCoinCollision(playerCharacter);
        coin30.checkCoinCollision(playerCharacter);
        coin31.checkCoinCollision(playerCharacter);
        coin32.checkCoinCollision(playerCharacter);
        coin33.checkCoinCollision(playerCharacter);
        coin34.checkCoinCollision(playerCharacter);
        coin35.checkCoinCollision(playerCharacter);
        coin36.checkCoinCollision(playerCharacter);
        coin37.checkCoinCollision(playerCharacter);
        coin38.checkCoinCollision(playerCharacter);
        coin39.checkCoinCollision(playerCharacter);
        coin40.checkCoinCollision(playerCharacter);
    }

    // Move the character based on the current direction
    if (playerCharacter.getMoveLeftFlag()) {
        playerCharacter.moveLeft();
    }
    if (playerCharacter.getMoveRightFlag()) {
        playerCharacter.moveRight();
    }

    // Debugging output to show character X and Y position
    std::cout << "Character X: " << playerCharacter.getX() << ", Character Y: " << playerCharacter.getY() << std::endl;

    // Check for collision with obstacles and handle accordingly
    bool isObstacleCollision = checkAllObstacleCollisions(playerCharacter);
    if (isObstacleCollision) {
        // Restore the previous character position
        playerCharacter.setX(prevCharacterX);
    }

    // Check for collision with the river, and handle accordingly
    bool isRiverColliding = checkAllRiverCollisions(playerCharacter);
    if (isRiverColliding && !playerCharacter.isCharacterDead()) {
        playerCharacter.setY(playerCharacter.getY() - gravity);
        playerCharacter.isDead = true;
        glutTimerFunc(10, respawnCharacter, 0);
    }

    // Apply gravity if jumping
    if (playerCharacter.getJumping()) {
        // Update the vertical position with projectile motion
        playerCharacter.setY(playerCharacter.getY() + playerCharacter.getCurrentJumpVelocity());

        // Check if the character reaches the ground or an obstacle
        if (checkAllObstacleCollisions(playerCharacter)) {
            // If on top of an obstacle, adjust the vertical position to stay on top
            playerCharacter.setY(prevCharacterY);
            playerCharacter.setJumping(false);
            playerCharacter.setCurrentJumpVelocity(0.0f); // Reset jump velocity
        } else {
            playerCharacter.setCurrentJumpVelocity(playerCharacter.getCurrentJumpVelocity() - gravity);

            if (checkAllRiverCollisions(playerCharacter) && !playerCharacter.isCharacterDead()) {
                playerCharacter.setY(playerCharacter.getY() - gravity);
                playerCharacter.setCharacterDead(true);
                glutTimerFunc(respawnDelay, respawnCharacter, 0);
            } else if (playerCharacter.getY() <= charInitialY) {
                playerCharacter.setY(charInitialY);
                playerCharacter.setJumping(false);
                playerCharacter.setCurrentJumpVelocity(0.0f); // Reset jump velocity
            }
        }
    } else {
        // If not jumping, apply continuous gravity to make the character fall
        // Adjust the gravity value to achieve the desired falling speed
        playerCharacter.setY(playerCharacter.getY() - gravity * 5);

        // Check for collision with obstacles or River below the character
        bool isOnObstacle = checkAllObstacleCollisions(playerCharacter);
        bool isOnRiver = checkAllRiverCollisions(playerCharacter);

        if (isOnObstacle) {
            // If on top of an obstacle, adjust the vertical position to stay on top
            playerCharacter.setY(prevCharacterY);
        }

        // Check if on top of river
        if (isOnRiver) {
            // Character has died, reset its position to the starting position

            playerCharacter.setY(playerCharacter.getY() - 0.5f);
            playerCharacter.isDead = true;
            glutTimerFunc(respawnDelay, respawnCharacter, 0);
            //isJumping = false;
            //currentJumpVelocity = 0.0f;
        }
        // Check if the character reaches the ground level
        if ((!isOnRiver) && playerCharacter.getY() <= charInitialY) {
            playerCharacter.setY(charInitialY); // Snap to the ground level
        }
    }

    glutPostRedisplay(); // Mark the window for a redraw
    glutTimerFunc(16, update, 0); // Call moveCharacter function after 16 milliseconds
}


// Function to add a new obstacle
inline void addObstacle(float xPos, float yPos, float width, float height, float red, float green, float blue) {
    obstacles.emplace_back(xPos, yPos, width, height, red, green, blue);
}


// Function to add a new river
inline void addRiver(float xPos, float yPos, float width, float height, float red, float green, float blue) {
    rivers.emplace_back(xPos, yPos, width, height, red, green, blue);
}

//Function to draw River
inline void drawRiver1() {
    addRiver(150.0f, 0.0f, 100.0f, 75.0f, 0.3f, 0.518f, 0.984f); // River 1
}


//Function to draw obstacles
inline void drawAllObstacleObjects() {
    // Draw the obstacles
    for (const auto &obstacle: obstacles) {
        obstacle.draw();
    }
}


//Function to draw river objects
inline void drawAllRiverObjects() {
    // Draw the rivers
    for (const auto &river: rivers) {
        river.draw();
    }
}


//---------------------------- STAGE 01 --------------------------------------------------------


void drawStage01() {
    isStage1 = true;

    drawAllObstacleObjects(); // If you have obstacles call this function

    addRiver(-700, 0, 698, 70, 0.3f, 0.518f, 0.984f);

    drawCloud(450, 540);

    drawHill(0, 200, 230);
    drawHill(760, 90, 200);

    addObstacle(767, 247, 45, 45, 0.69f, 0.263f, 0.043f);
    drawBorder(767, 247, 767 + 45, 247 + 45, 3.0f);

    addObstacle(955, 247, 45 * 4, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(955, 247, 1135, 292, 45, 45, 3);

    drawCloud(980, 580);

    addObstacle(1341, 151, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(1341, 151, 1341 + 95, 151 + 42, 3);

    addObstacle(1349, 101, 80, 50, 0.59f, 0.863f, 0.039f);
    drawBorder(1349, 101, 1349 + 80, 101 + 50, 3);

    drawCloud(1450, 550);
    drawCloud(1820, 590);

    addObstacle(1822, 201, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(1822, 201, 1822 + 95, 201 + 42, 3);

    addObstacle(1828, 101, 80, 100, 0.59f, 0.863f, 0.039f);
    drawBorder(1828, 101, 1828 + 82, 101 + 100, 3);

    addObstacle(2211, 101, 80, 147, 0.59f, 0.863f, 0.039f);
    drawBorder(2211, 101, 2211 + 82, 101 + 147, 3);

    addObstacle(2205, 248, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(2205, 248, 2205 + 95, 248 + 42, 3);

    drawHill(2300, 100, 200);

    addObstacle(2733, 248, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(2733, 248, 2733 + 95, 248 + 42, 3);

    addObstacle(2738, 101, 80, 147, 0.59f, 0.863f, 0.039f);
    drawBorder(2738, 101, 2738 + 82, 101 + 147, 3);

    drawCloud(2755, 540);
    drawCloud(3285, 590);

    drawHill(3060, 50, 70);

    addRiver(3301, 0, 97, 102, 0.55f, 0.53f, 0.94f);

    addObstacle(3690, 247, 45 * 3, 45, 0.69f, 0.263f, 0.043f);
    drawBorder(3690, 247, 3690 + 45, 247 + 45, 3.0f);
    drawBorder(3690 + 45, 247, 3690 + 45 + 45, 247 + 45, 3.0f); //*** IF POSSIBLE HIT BRICK TO MAKE INVISIBLE
    drawBorder(3690 + 45 + 45, 247, 3690 + 45 + 45 + 45, 247 + 45, 3.0f);

    drawCloud(3712, 540);

    addObstacle(3834, 440, 45 * 8, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(3834, 440, 4194, 485, 45, 45, 3.0f);

    drawCloud(4120, 595);

    addObstacle(4360, 440, 45 * 4, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(4360, 440, 4360 + 45 * 4, 485, 45, 45, 3.0f);

    addObstacle(4503, 247, 45, 45, 0.69f, 0.263f, 0.043f); //***
    drawBorder(4503, 247, 4503 + 45, 247 + 45, 3);

    drawHill(4600, 90, 140);

    addObstacle(4790, 247, 45 * 2, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(4790, 247, 4790 + 45 * 2, 247 + 45, 45, 45, 3.0f);

    drawCloud(5060, 540);
    drawCloud(5584, 586);

    drawHill(5364, 90, 150);

    addObstacle(5652, 247, 45, 45, 0.69f, 0.263f, 0.043f);
    drawBorder(5652, 247, 5652 + 45, 247 + 45, 3);

    addObstacle(5800, 440, 45 * 3, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(5800, 440, 5800 + 45 * 3, 440 + 45, 45, 45, 3.0f);

    drawCloud(6011, 545);

    addObstacle(6135, 440, 45 * 4, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6135, 440, 6135 + 45 * 4, 440 + 45, 45, 45, 3.0f);

    addObstacle(6181, 247, 45 * 2, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6181, 247, 6181 + 45 * 2, 247 + 45, 45, 45, 3.0f);

    addObstacle(6421, 101, 45 * 9, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421, 101, 6421 + 45 * 9, 101 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45, 101 + 45, 45 * 8, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45, 101 + 45, 6421 + 45 * 9, 101 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45, 101 + 45 + 45, 45 * 7, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45, 101 + 45 + 45, 6421 + 45 * 9, 101 + 45 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45, 101 + 45 + 45 + 45, 45 * 6, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45 + 45, 101 + 45 + 45 + 45, 6421 + 45 * 9, 101 + 45 + 45 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45, 45 * 5, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45, 6421 + 45 * 9, 101 + 45 + 45 + 45 + 45 + 45, 45,
                   45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45, 45 * 4, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45, 6421 + 45 * 9,
                   101 + 45 + 45 + 45 + 45 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45, 45 * 3, 45, 0.69f, 0.263f,
                0.043f);
    drawBrickLines(6421 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45, 6421 + 45 * 9,
                   101 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 45 * 2, 45, 0.69f,
                0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 6421 + 45 * 9,
                   101 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 45, 45, 3.0f);

    addObstacle(6421 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 45, 45,
                0.69f, 0.263f, 0.043f);
    drawBrickLines(6421 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 101 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45,
                   6421 + 45 * 9, 101 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 45, 45, 3.0f);

    drawCloud(6427, 590);

    glBegin(GL_LINE_STRIP);
    glLineWidth(50.0f);
    glColor3f(0.616f, 0.992f, 0.094f);
    glVertex2f(7048.5f, 147.0f);
    glVertex2f(7048.5f, 570.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(7048.5f, 570.0f);
    glVertex2f(6998.5f, 570.0f);
    glVertex2f(7048.5f, 520.0f);
    glEnd();

    addObstacle(7026, 101, 45, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(7026, 101, 7026 + 45, 101 + 45, 45, 45, 3.0f);

    drawArchGate(7220, 101, 150, 100, 0, 0, 0);

    drawGround(8000.0f);

    drawAllRiverObjects(); // (MUST BE CALLED AFTER CREATING GROUND If  you have rivers call this function

    coin1.draw();
    coin2.draw();
    coin3.draw();
    coin4.draw();
    coin5.draw();
    coin6.draw();
    coin7.draw();
    coin8.draw();
    coin9.draw();
    coin10.draw();
    coin11.draw();

    playerCharacter.draw();

    drawScoreboard(playerCharacter.getX());
    drawLives(playerCharacter.getX());
}


//---------------------------- STAGE 02 --------------------------------------------------------


void drawStage02() {
    isStage2 = true;

    drawAllObstacleObjects(); // If you have obstacles call this function

    drawCloud(0, 640);
    drawCloud(750, 640);

    // ------------ GROUND --------------
    addObstacle(0, 0, 300, 100, 0.69f, 0.263f, 0.043f);
    drawBrickLines(0, 0, 300, 100, 50, 50, 3);

    addRiver(300, 0, 200, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(500, 0, 100, 150, 0.69f, 0.263f, 0.043f); // 1st block
    drawBorder(500, 0, 500 + 100, 150, 3.0f);
    drawBrickLines(500, 0, 500 + 100, 150, 50, 50, 3);
    addObstacle(450, 150, 200, 50, 0.f, 1.0f, 0.0f);
    drawBorder(450, 150, 450 + 200, 150 + 50, 3.0f);

    addRiver(600, 0, 200, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(800, 0, 300, 250, 0.69f, 0.263f, 0.043f); //2nd block
    drawBorder(800, 0, 800 + 300, 250, 3.0f);
    drawBrickLines(800, 0, 800 + 300, 250, 50, 50, 3);
    addObstacle(750, 250, 400, 50, 0.f, 1.0f, 0.0f);
    drawBorder(750, 250, 750 + 400, 250 + 50, 3.0f);

    addObstacle(900, 300, 150, 150, 0.69f, 0.263f, 0.043f); //2nd block upper
    drawBorder(900, 300, 900 + 150, 300 + 150, 3.0f);
    drawBrickLines(900, 300, 900 + 150, 300 + 150, 50, 50, 3);
    addObstacle(850, 450, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(850, 450, 850 + 250, 450 + 50, 3.0f);

    addRiver(1100, 0, 100, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(1200, 0, 50, 100, 0.69f, 0.263f, 0.043f); //3rd block
    drawBorder(1200, 0, 1200 + 50, 100, 3.0f);
    drawBrickLines(1200, 0, 1200 + 50, 100, 50, 50, 3);
    addObstacle(1150, 100, 150, 50, 0.f, 1.0f, 0.0f);
    drawBorder(1150, 100, 1150 + 150, 100 + 50, 3.0f);

    addRiver(1250, 0, 100, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(1350, 0, 150, 300, 0.69f, 0.263f, 0.043f); //4th block
    drawBorder(1350, 0, 1350 + 150, 300, 3.0f);
    drawBrickLines(1350, 0, 1350 + 150, 300, 50, 50, 3);
    addObstacle(1300, 300, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(1300, 300, 1300 + 250, 300 + 50, 3.0f);

    addRiver(1500, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(1800, 0, 300, 450, 0.69f, 0.263f, 0.043f); //5th block
    drawBorder(1800, 0, 1800 + 300, 450, 3.0f);
    drawBrickLines(1800, 0, 1800 + 300, 450, 50, 50, 3);
    addObstacle(1750, 450, 400, 50, 0.f, 1.0f, 0.0f);
    drawBorder(1750, 450, 1750 + 400, 450 + 50, 3.0f);

    addRiver(2100, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(2400, 0, 150, 100, 0.69f, 0.263f, 0.043f); //6th block
    drawBorder(2400, 0, 2400 + 150, 100, 3.0f);
    drawBrickLines(2400, 0, 2400 + 150, 100, 50, 50, 3);
    addObstacle(2350, 100, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(2350, 100, 2350 + 250, 100 + 50, 3.0f);

    addRiver(2550, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    drawCloud(2700, 550);

    addObstacle(2850, 0, 150, 100, 0.69f, 0.263f, 0.043f); //7th block
    drawBorder(2850, 0, 2850 + 150, 100, 3.0f);
    drawBrickLines(2850, 0, 2850 + 150, 100, 50, 50, 3);
    addObstacle(2800, 100, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(2800, 100, 2800 + 250, 100 + 50, 3.0f);

    addRiver(3000, 0, 200, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(3200, 0, 80, 250, 0.69f, 0.263f, 0.043f); //8th block
    drawBorder(3200, 0, 3200 + 80, 250, 3.0f);
    drawBrickLines(3200, 0, 3200 + 80, 250, 50, 50, 3);
    addObstacle(3150, 250, 180, 50, 0.f, 1.0f, 0.0f);
    drawBorder(3150, 250, 3150 + 180, 250 + 50, 3.0f);

    addRiver(3280, 0, 370, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(3650, 0, 200, 400, 0.69f, 0.263f, 0.043f); //9th block
    drawBorder(3650, 0, 3650 + 200, 400, 3.0f);
    drawBrickLines(3650, 0, 3650 + 200, 400, 50, 50, 3);
    addObstacle(3600, 400, 300, 50, 0.f, 1.0f, 0.0f);
    drawBorder(3600, 400, 3600 + 300, 400 + 50, 3.0f);

    addRiver(3850, 0, 950, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(4200, 350, 200, 50, 0.69f, 0.263f, 0.043f); //floating  block
    drawBorder(4200, 350, 4200 + 200, 350 + 50, 3.0f);
    drawBrickLines(4200, 350, 4200 + 200, 350 + 50, 50, 50, 3);

    drawCloud(4500, 640);

    addObstacle(4800, 0, 150, 200, 0.69f, 0.263f, 0.043f); //10th block
    drawBorder(4800, 0, 4800 + 150, 200, 3.0f);
    drawBrickLines(4800, 0, 4800 + 150, 200, 50, 50, 3);
    addObstacle(4750, 200, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(4750, 200, 4750 + 250, 200 + 50, 3.0f);

    addRiver(4950, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(5250, 0, 350, 400, 0.69f, 0.263f, 0.043f); //11th block
    drawBorder(5250, 0, 5250 + 350, 400, 3.0f);
    drawBrickLines(5250, 0, 5250 + 350, 400, 50, 50, 3);
    addObstacle(5200, 400, 450, 50, 0.f, 1.0f, 0.0f);
    drawBorder(5200, 400, 5200 + 450, 400 + 50, 3.0f);

    addRiver(5600, 0, 250, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(5850, 0, 100, 100, 0.69f, 0.263f, 0.043f); //12th block
    drawBorder(5850, 0, 5850 + 100, 100, 3.0f);
    drawBrickLines(5850, 0, 5850 + 100, 100, 50, 50, 3);
    addObstacle(5800, 100, 200, 50, 0.f, 1.0f, 0.0f);
    drawBorder(5800, 100, 5800 + 200, 100 + 50, 3.0f);

    addRiver(5950, 0, 250, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(6200, 0, 150, 250, 0.69f, 0.263f, 0.043f); //13th block
    drawBorder(6200, 0, 6200 + 150, 250, 3.0f);
    drawBrickLines(6200, 0, 6200 + 150, 250, 50, 50, 3);
    addObstacle(6150, 250, 250, 50, 0.f, 1.0f, 0.0f);
    drawBorder(6150, 250, 6150 + 250, 250 + 50, 3.0f);

    addRiver(6350, 0, 150, 100, 0.55f, 0.53f, 0.94f);

    // ------------ GROUND --------------
    addObstacle(6500, 0, 2000, 100, 0.69f, 0.263f, 0.043f);
    drawBrickLines(6500, 0, 6450 + 2000, 100, 50, 50, 3);

    drawCloud(6500, 640);

    glBegin(GL_LINE_STRIP);
    glLineWidth(50.0f);
    glColor3f(0.616f, 0.992f, 0.094f);
    glVertex2f(7048.5f, 147.0f);
    glVertex2f(7048.5f, 570.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(7048.5f, 570.0f);
    glVertex2f(6998.5f, 570.0f);
    glVertex2f(7048.5f, 520.0f);
    glEnd();

    addObstacle(7026, 101, 45, 45, 0.69f, 0.263f, 0.043f);
    drawBrickLines(7026, 101, 7026 + 45, 101 + 45, 45, 45, 3.0f);

    drawArchGate(7220, 101, 150, 100, 0, 0, 0);

    drawAllRiverObjects();

    coin41.draw();
    coin42.draw();
    coin43.draw();
    coin44.draw();
    coin45.draw();
    coin46.draw();
    coin47.draw();
    coin48.draw();
    coin49.draw();
    coin50.draw();
    coin51.draw();
    coin52.draw();
    coin53.draw();
    coin54.draw();
    coin55.draw();
    coin56.draw();
    coin57.draw();
    coin58.draw();
    coin59.draw();

    playerCharacter.draw();

    drawScoreboard(playerCharacter.getX());
    drawLives(playerCharacter.getX());
}


//---------------------------- STAGE 03 --------------------------------------------------------


inline void drawStage03() {
    isStage3 = true;

    drawAllObstacleObjects(); // If you have obstacles call this function

    addRiver(-700, 0, 698, 70, 0.3f, 0.518f, 0.984f);

    addObstacle(400, 100, 60, 60, 0.22, 0.34, 0.41); // 1st block
    drawBorder(400, 100, 460, 160, 3.5f);

    addObstacle(550, 100, 60, 120, 0.22, 0.34, 0.41); // 2nd block
    drawBorder(550, 100, 610, 220, 3.5f);
    drawBrickLines(550, 100, 610, 220, 60, 60, 4.0f);

    addObstacle(700, 100, 60, 180, 0.22, 0.34, 0.41); // 3rd block
    drawBorder(700, 100, 760, 280, 3.5f);
    drawBrickLines(700, 100, 760, 280, 60, 60, 4.0f);

    addObstacle(850, 100, 60, 240, 0.22, 0.34, 0.41); // 4th block
    drawBorder(850, 100, 910, 340, 3.5f);
    drawBrickLines(850, 100, 910, 340, 60, 60, 4.0f);

    addObstacle(1000, 100, 60, 180, 0.22, 0.34, 0.41); // 5th block
    drawBorder(1000, 100, 1060, 280, 3.5f);
    drawBrickLines(1000, 100, 1060, 280, 60, 60, 4.0f);

    //S shape start
    addObstacle(1150, 265, 40, 160, 0.22, 0.34, 0.41); // 6th block
    drawBorder(1150, 265, 1190, 425, 3.5f);
    drawBrickLines(1150, 265, 1190, 425, 40, 40, 4.0f);

    addObstacle(1150, 265, 120, 40, 0.22, 0.34, 0.41); // 7th block
    drawBorder(1150, 265, 1270, 305, 3.5f);
    drawBrickLines(1150, 265, 1270, 305, 40, 40, 4.0f);

    addObstacle(1270, 265, 40, 160, 0.22, 0.34, 0.41); // 8th block
    drawBorder(1270, 265, 1310, 425, 3.5f);
    drawBrickLines(1270, 265, 1310, 425, 40, 40, 4.0f);

    addObstacle(1270, 385, 160, 40, 0.22, 0.34, 0.41); // 9th block
    drawBorder(1270, 385, 1430, 425, 3.5f);
    drawBrickLines(1270, 385, 1430, 425, 40, 40, 4.0f);

    addObstacle(1390, 265, 40, 160, 0.22, 0.34, 0.41); // 10th block
    drawBorder(1390, 265, 1430, 425, 3.5f);
    drawBrickLines(1390, 265, 1430, 425, 40, 40, 4.0f);

    addObstacle(1390, 265, 120, 40, 0.22, 0.34, 0.41); // 11th block
    drawBorder(1390, 265, 1510, 305, 3.5f);
    drawBrickLines(1390, 265, 1510, 305, 40, 40, 4.0f);

    addObstacle(1510, 265, 40, 160, 0.22, 0.34, 0.41); // 12th block
    drawBorder(1510, 265, 1550, 425, 3.5f);
    drawBrickLines(1510, 265, 1550, 425, 40, 40, 4.0f);
    // S shape end

    addObstacle(1680, 310, 70, 210, 0.22, 0.34, 0.41); // 13th block
    drawBorder(1680, 310, 1750, 520, 3.5f);
    drawBrickLines(1680, 310, 1750, 520, 70, 70, 4.0f);

    addObstacle(1850, 300, 200, 40, 0.22, 0.34, 0.41); // 14th block
    drawBorder(1850, 300, 2050, 340, 3.5f);
    drawBrickLines(1850, 300, 2050, 340, 40, 40, 4.0f);

    addObstacle(2150, 300, 160, 40, 0.22, 0.34, 0.41); // 15th block
    drawBorder(2150, 300, 2310, 340, 3.5f);
    drawBrickLines(2150, 300, 2310, 340, 40, 40, 4.0f);

    addObstacle(2430, 250, 70, 210, 0.22, 0.34, 0.41); // 16th block
    drawBorder(2430, 250, 2500, 460, 3.5f);
    drawBrickLines(2430, 250, 2500, 460, 70, 70, 4.0f);

    addObstacle(2610, 280, 160, 40, 0.22, 0.34, 0.41); // 17th block
    drawBorder(2610, 280, 2770, 320, 3.5f);
    drawBrickLines(2610, 280, 2770, 320, 40, 40, 4.0f);

    addRiver(1065, 0, 1700, 240, 0.55f, 0.53f, 0.94f);

    addObstacle(2900, 100, 124, 248, 0.22, 0.34, 0.41); // 18th block
    drawBorder(2900, 100, 3024, 348, 3.5f);
    drawBrickLines(2900, 100, 3024, 348, 124, 124, 4.0f);

    addObstacle(2870, 348, 184, 45, 0.22, 0.34, 0.41); // 19th block
    drawBorder(2870, 348, 3054, 393, 3.5f);

    addObstacle(3140, 200, 100, 35, 0.59f, 0.863f, 0.039f); //pipe upper
    drawBorder(3140, 200, 3240, 235, 3.5f);

    addObstacle(3145, 100, 90, 100, 0.59f, 0.863f, 0.039f); // pipe lower
    drawBorder(3145, 100, 3235, 200, 3.5f);

    addObstacle(3320, 300, 100, 35, 0.59f, 0.863f, 0.039f); //pipe upper
    drawBorder(3320, 300, 3420, 335, 3.5f);

    addObstacle(3325, 100, 90, 200, 0.59f, 0.863f, 0.039f); // pipe lower
    drawBorder(3325, 100, 3415, 300, 3.5f);

    addObstacle(3500, 200, 100, 35, 0.59f, 0.863f, 0.039f); //pipe upper
    drawBorder(3500, 200, 3600, 235, 3.5f);

    addObstacle(3505, 100, 90, 100, 0.59f, 0.863f, 0.039f); // pipe lower
    drawBorder(3505, 100, 3595, 200, 3.5f);

    addRiver(3605, 0, 200, 102, 0.55f, 0.53f, 0.94f);

    addObstacle(3675, 150, 70, 280, 0.22, 0.34, 0.41); // 20th block
    drawBorder(3675, 150, 3745, 430, 3.5f);
    drawBrickLines(3675, 150, 3745, 430, 70, 70, 4.0f);

    addObstacle(3945, 100, 180, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(3945, 100, 4125, 145, 45, 45, 4.0f);
    addObstacle(3990, 145, 135, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(3990, 145, 4125, 190, 45, 45, 4.0f);
    addObstacle(4035, 190, 90, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(4035, 190, 4125, 235, 45, 45, 4.0f);
    addObstacle(4080, 235, 45, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(4080, 235, 4125, 280, 45, 45, 4.0f);

    addRiver(4165, 0, 680, 102, 0.55f, 0.53f, 0.94f);

    addObstacle(4215, 235, 120, 40, 0.22, 0.34, 0.41); // 21th block
    drawBorder(4215, 235, 4335, 275, 3.5f);
    drawBrickLines(4215, 235, 4335, 275, 40, 40, 4.0f);

    addObstacle(4385, 350, 200, 50, 0.22, 0.34, 0.41); // 22th block
    drawBorder(4385, 350, 4585, 400, 3.5f);
    drawBrickLines(4385, 350, 4585, 400, 50, 50, 4.0f);

    addObstacle(4635, 235, 120, 40, 0.22, 0.34, 0.41); // 23th block
    drawBorder(4635, 235, 4755, 275, 3.5f);
    drawBrickLines(4635, 235, 4755, 275, 40, 40, 4.0f);

    addObstacle(4850, 100, 50, 300, 0.22, 0.34, 0.41); // 24th block
    drawBorder(4850, 100, 4900, 400, 3.5f);
    drawBrickLines(4850, 100, 4900, 400, 50, 50, 4.0f);

    addRiver(4905, 0, 500, 102, 0.55f, 0.53f, 0.94f);

    addObstacle(4960, 250, 135, 45, 0.22, 0.34, 0.41); // 25th block
    drawBorder(4960, 250, 5095, 295, 3.5f);
    drawBrickLines(4960, 250, 5095, 295, 45, 45, 4.0f);

    addObstacle(5095, 250, 45, 225, 0.22, 0.34, 0.41); // 26th block
    drawBorder(5095, 250, 5140, 475, 3.5f);
    drawBrickLines(5095, 250, 5140, 475, 45, 45, 4.0f);

    addObstacle(5220, 250, 45, 225, 0.22, 0.34, 0.41); // 27th block
    drawBorder(5220, 250, 5265, 475, 3.5f);
    drawBrickLines(5220, 250, 5265, 475, 45, 45, 4.0f);

    addObstacle(5265, 250, 135, 45, 0.22, 0.34, 0.41); // 28th block
    drawBorder(5265, 250, 5400, 295, 3.5f);
    drawBrickLines(5265, 250, 5400, 295, 45, 45, 4.0f);

    addObstacle(5650, 250, 100, 35, 0.59f, 0.863f, 0.039f); //pipe upper
    drawBorder(5650, 250, 5750, 285, 3.5f);

    addObstacle(5655, 100, 90, 150, 0.59f, 0.863f, 0.039f); // pipe lower
    drawBorder(5655, 100, 5745, 250, 3.5f);

    addObstacle(5800, 290, 225, 45, 0.22, 0.34, 0.41); // 27th block
    drawBorder(5800, 290, 6025, 335, 3.5f);
    drawBrickLines(5800, 290, 6025, 335, 45, 45, 4.0f);


    addObstacle(6250, 100, 405, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6250, 100, 6655, 145, 45, 45, 4.0f);
    addObstacle(6295, 145, 360, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6295, 145, 6655, 190, 45, 45, 4.0f);
    addObstacle(6340, 190, 315, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6340, 190, 6655, 235, 45, 45, 4.0f);
    addObstacle(6385, 235, 270, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6385, 235, 6655, 280, 45, 45, 4.0f);
    addObstacle(6430, 280, 225, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6430, 280, 6655, 325, 45, 45, 4.0f);
    addObstacle(6475, 325, 180, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6475, 325, 6655, 370, 45, 45, 4.0f);
    addObstacle(6520, 370, 135, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6520, 370, 6655, 415, 45, 45, 4.0f);
    addObstacle(6565, 415, 90, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6565, 415, 6655, 460, 45, 45, 4.0f);
    addObstacle(6610, 460, 45, 45.0f, 0.22, 0.34, 0.41);
    drawBrickLines(6610, 460, 6655, 505, 45, 45, 4.0f);

    addObstacle(100, 670, 8000, 50, 0.22, 0.34, 0.41); // upper ground shape
    drawBorder(100, 670, 8000, 720, 3.5f);
    drawBrickLines(100, 670, 8000, 720, 50, 50, 4.0f);

    addObstacle(100, 470, 50, 300, 0.22, 0.34, 0.41); // 1stup shape
    drawBorder(100, 470, 150, 670, 3.5f);
    drawBrickLines(100, 470, 150, 670, 50, 50, 4.0f);

    addObstacle(100, 100, 50, 150, 0.22, 0.34, 0.41); // 1st low shape
    drawBorder(100, 100, 150, 250, 3.5f);
    drawBrickLines(100, 100, 150, 250, 50, 50, 4.0f);

    glBegin(GL_LINE_STRIP);
    glLineWidth(50.0f);
    glColor3f(0.616f, 0.992f, 0.094f);
    glVertex2f(7048.5f, 147.0f);
    glVertex2f(7048.5f, 570.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(7048.5f, 570.0f);
    glVertex2f(6998.5f, 570.0f);
    glVertex2f(7048.5f, 520.0f);
    glEnd();

    addObstacle(7026, 101, 45, 45, 0.22, 0.34, 0.41);
    drawBrickLines(7026, 101, 7026 + 45, 101 + 45, 45, 45, 3.0f);

    drawArchGate(7220, 101, 150, 100, 0, 0, 0);

    drawGround2(8000.0f);

    drawAllRiverObjects();

    coin14.draw();
    coin15.draw();
    coin16.draw();
    coin17.draw();
    coin18.draw();
    coin19.draw();
    coin20.draw();
    coin21.draw();
    coin22.draw();
    coin23.draw();
    coin24.draw();
    coin25.draw();
    coin26.draw();
    coin27.draw();
    coin28.draw();
    coin29.draw();
    coin30.draw();
    coin31.draw();
    coin32.draw();
    coin33.draw();
    coin34.draw();
    coin35.draw();
    coin36.draw();
    coin37.draw();
    coin38.draw();
    coin39.draw();
    coin40.draw();

    playerCharacter.draw();

    drawScoreboard(playerCharacter.getX());
    drawLives(playerCharacter.getX());
}


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
inline void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


//Exit Function
inline void exit1(int value) {
    exit(0);
    glutTimerFunc(10, exit1, 0);
}


// Function to handle the display
inline void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (lives > 0) {
        if (isStage1) {
            cameraMovement();
            drawStage01();
        } else if (isStage2) {
            cameraMovement();
            drawStage02();
        } else if (isStage3) {
            cameraMovement();
            drawStage03();
        } else {
            displayMenu();
        }
    } else {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(250.0f, 400.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");

        glFlush(); // Render now

        glutTimerFunc(2000, exit1, 0);
    }
    glutSwapBuffers();
}


// // Play Sound In The Background
//  void sound()    {
//      PlaySound("mario.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
//  }


//Function to handle key presses
inline void specialKeyPressed(int key, int x, int y) {
    playerCharacter.specialKeyPressed(key, x, y);
}


//Function to handle key releases
inline void specialKeyReleased(int key, int x, int y) {
    playerCharacter.specialKeyReleased(key, x, y);
}


// Function to set up the OpenGL environment
inline void init() {
    glClearColor(0.55f, 0.53f, 0.94f, 1.0f); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, coordinateX, 0, coordinateY); // Set the coordinate system
}


// Function to handle window resizing
inline void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}


#endif //MAIN_H
