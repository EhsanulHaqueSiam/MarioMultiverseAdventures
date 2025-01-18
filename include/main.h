#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>

#include "Character.h"
#include "Coin.h"
#include "FlappyBird.h"
#include "Obstacle.h"
#include "River.h"
#include "RiverGame.h"
#include "StageComponents.h"

inline Character playerCharacter;

inline std::vector<Obstacle> obstacles;
inline std::vector<River> rivers;

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

inline void cameraMovement() {
    // Calculate the camera's position to center the stage around the character
    const float cameraX = -(playerCharacter.getX() - windowFinalX / 2);
    constexpr float cameraY = 0.0f; // Keep a fixed Y position for the camera
    constexpr float cameraZ = 0.0f; // Set a suitable Z position for the camera (you can adjust this based on your scene)

    // Apply the translation transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(cameraX, cameraY, cameraZ);
}


// Function to check collision with all the obstacles and the river
inline bool checkAllObstacleCollisions(const Character &playerCharacter) {
    for (const auto &obstacle: obstacles) {
        if (obstacle.checkCollision(playerCharacter)) {
            return true;
        }
    }
    return false; // No collision
}


// Function to check collision with all the river
inline bool checkAllRiverCollisions(const Character &playerCharacter) {
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
inline void drawScoreboard(const int characterX) {
    const int scoreboardX = characterX - windowFinalX / 2;
    constexpr int scoreboardY = 10; // Adjust this as needed

    // Draw the scoreboard at the calculated position
    renderText("Score: " + std::to_string(score), scoreboardX, scoreboardY, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
}


//Function to show Lives
inline void drawLives(const int characterX) {
    const int livesX = characterX - windowFinalX / 2;
    constexpr int livesY = 40; // Adjust this as needed


    renderText("Lives: " + std::to_string(lives), livesX, livesY, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
}


//Update function
inline void update(int value) {
    // Store the current character position for collision checking
    const float prevCharacterX = playerCharacter.getX();
    const float prevCharacterY = playerCharacter.getY();

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
    if (checkAllObstacleCollisions(playerCharacter)) {
        // Restore the previous character position
        playerCharacter.setX(prevCharacterX);
    }

    // Check for collision with the river, and handle accordingly
    if (const bool isRiverColliding = checkAllRiverCollisions(playerCharacter); isRiverColliding && !playerCharacter.isCharacterDead()) {
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
        const bool isOnObstacle = checkAllObstacleCollisions(playerCharacter);
        const bool isOnRiver = checkAllRiverCollisions(playerCharacter);

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


//---------------------------- STAGE 02 --------------------------------------------------------


inline void drawStage02() {
    isStage2 = true;



    drawCloud(0, 640);
    drawCloud(750, 640);

    // ------------ GROUND --------------
    drawHill(0, 200, 230); //1st hill
    drawHill(600, 300, 200); //2nd hill
    drawHill(240, 300, 350); //3rd hill
    drawHill(900, 300, 600); //4rh hill
    drawHill(1800, 400, 500); //6th hill
    drawHill(1600, 600, 300); //5th hill
    drawHill(2200, 500, 900); //7th hill
    drawHill(3000, 450, 700); //8th hill

    // If you have obstacles call this function
    drawAllObstacleObjects();

    addObstacle(0, 0, 75, 100, 0.69f, 0.263f, 0.043f); //1st piller block
    drawBorder(0, 0, 75, 100, 3.0f);
    drawBrickLines(0, 0, 75, 100, 50, 50, 3);

    addRiver(75, 0, 6500, 100, 0.55f, 0.53f, 0.94f); //1st river

    addObstacle(175, 0, 100, 125, 0.69f, 0.263f, 0.043f); // 2nd piller block
    drawBorder(175, 0, 175 + 100, 125, 3.0f);
    drawBrickLines(175, 0, 175 + 100, 125, 50, 50, 3);

    addRiver(275, 0, 150, 100, 0.55f, 0.53f, 0.94f); //2nd river

    addObstacle(425, 0, 100, 150, 0.69f, 0.263f, 0.043f); // 3rd piller block
    drawBorder(425, 0, 425 + 100, 150, 3.0f);
    drawBrickLines(425, 0, 425 + 100, 150, 50, 50, 3);

    addObstacle(375, 150, 200, 50, 0.f, 1.0f, 0.0f); //1st green block
    drawBorder(375, 150, 375 + 200, 150 + 50, 3.0f);

    addObstacle(375, 150, 200, 50, 0.f, 1.0f, 0.0f); //2nd green block
    drawBorder(375, 150, 375 + 200, 150 + 50, 3.0f);

    addRiver(525, 0, 300, 100, 0.55f, 0.53f, 0.94f); //3rd river

    addObstacle(500, 300, 75, 50, 0.f, 1.0f, 0.0f); //2nd green block
    drawBorder(500, 300, 500 + 75, 300 + 50, 3.0f);

    addObstacle(650, 500, 75, 50, 0.f, 1.0f, 0.0f); //3rd green block
    drawBorder(650, 500, 650 + 75, 500 + 50, 3.0f);

    addObstacle(825, 0, 100, 250, 0.69f, 0.263f, 0.043f); //4th piller block
    drawBorder(825, 0, 825 + 100, 250, 3.0f);
    drawBrickLines(825, 0, 825 + 100, 250, 50, 50, 3);

    addObstacle(750, 250, 250, 50, 0.f, 1.0f, 0.0f); //4 green block
    drawBorder(750, 250, 750 + 250, 250 + 50, 3.0f);

    addRiver(925, 0, 1075, 100, 0.55f, 0.53f, 0.94f); //4 river

    addObstacle(1200, 400, 100, 50, 0.f, 1.0f, 0.0f); //5 green block
    drawBorder(1200, 400, 1200 + 100, 400 + 50, 3.0f);

    addObstacle(1500, 600, 100, 50, 0.f, 1.0f, 0.0f); //6 green block
    drawBorder(1500, 600, 1500 + 100, 600 + 50, 3.0f);

    addObstacle(2000, 0, 100, 150, 0.69f, 0.263f, 0.043f); //5th piller block
    drawBorder(2000, 0, 2000 + 100, 150, 3.0f);
    drawBrickLines(2000, 0, 2000 + 100, 150, 50, 50, 3);

    addRiver(2100, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(2350, 0, 50, 300, 0.69f, 0.263f, 0.043f); //6th block
    drawBorder(2350, 0, 2350 + 50, 300, 3.0f);
    drawBrickLines(2350, 0, 2350 + 50, 300, 50, 50, 3);

    addObstacle(2300, 300, 150, 50, 0.f, 1.0f, 0.0f); //6th block
    drawBorder(2300, 300, 2300 + 150, 300 + 50, 3.0f);

    addRiver(2400, 0, 450, 100, 0.55f, 0.53f, 0.94f);

    drawCloud(2700, 550);


    addObstacle(2800, 100, 250, 50,0.66f, 0.66f, 0.66f);
    drawBorder(2800, 100, 2800 + 250, 100 + 50, 3.0f);
    drawBrickLines(2800, 100, 2800 + 250, 100 + 50, 50, 50, 3);

    addObstacle(3150, 250, 150, 50, 0.66f, 0.66f, 0.66f);
    drawBorder(3150, 250, 3150 + 150, 250 + 50, 3.0f);
    drawBrickLines(3150, 250 , 3150 + 150, 250 + 50, 50, 50, 3);

    addRiver(3280, 0, 370, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(3500, 300, 50, 200, 0.66f, 0.66f, 0.66f);
    drawBorder(3500, 300, 3500 + 50, 300 + 200, 3.0f);
    drawBrickLines(3500, 300 , 3500 + 50, 300 + 200, 50, 50, 3);

    addObstacle(3650, 150, 50, 50, 0.66f, 0.66f, 0.66f);
    drawBorder(3650, 150, 3650 + 50, 150 + 50, 3.0f);
    drawBrickLines(3650, 150, 3650 + 50, 150 + 50, 50, 50, 3);

    addObstacle(3750, 200, 50, 50, 0.66f, 0.66f, 0.66f);
    drawBorder(3750, 200, 3750 + 50, 200 + 50, 3.0f);
    drawBrickLines(3750, 200, 3750 + 50, 200 + 50, 50, 50, 3);

    addObstacle(4000, 400, 50, 50, 0.66f, 0.66f, 0.66f);
    drawBorder(4000, 400,  4000+ 50, 400 + 50, 3.0f);
    drawBrickLines(4000, 400, 4000 + 50, 400 + 50, 50, 50, 3);

    // addRiver(3850, 0, 950, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(4200, 350, 50, 50, 0.66f, 0.66f, 0.66f); //floating  block
    drawBorder(4200, 350, 4200 + 50, 350 + 50, 3.0f);
    drawBrickLines(4200, 350, 4200 + 50, 350 + 50, 50, 50, 3);

    addObstacle(4400, 100, 50, 50, 0.66f, 0.66f, 0.66f); //floating  block
    drawBorder(4400, 100, 4400 + 50, 100 + 50, 3.0f);
    drawBrickLines(4400, 100, 4400 + 50, 100 + 50, 50, 50, 3);

    drawCloud(4500, 640);

    addObstacle(4600, 300, 50, 50, 0.66f, 0.66f, 0.66f); //floating  block
    drawBorder(4600, 300, 4600 + 50, 300 + 50, 3.0f);
    drawBrickLines(4600, 300, 4600 + 50, 300 + 50, 50, 50, 3);

    drawCloud(5000, 700);

    addObstacle(4800, 300, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(4800, 300, 4800 + 95, 300 + 42, 3);
    addObstacle(4805, 0, 85, 300, 0.59f, 0.863f, 0.039f);
    drawBorder(4805, 0, 4805 + 85, 300, 3);


    addRiver(4950, 0, 300, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(5000, 500, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(5000, 500, 5000 + 95, 500 + 42, 3);
    addObstacle(5005, 0, 85, 500, 0.59f, 0.863f, 0.039f);
    drawBorder(5005, 0, 5005 + 85,  500, 3);

    addRiver(5600, 0, 250, 0, 0.55f, 0.53f, 0.94f);

    addObstacle(5300, 600, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(5300, 600, 5300 + 95, 600 + 42, 3);
    addObstacle(5305, 0, 85, 600, 0.59f, 0.863f, 0.039f);
    drawBorder(5305, 0, 5305 + 85,  600, 3);

    addObstacle(5600, 200, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(5600, 200, 5600 + 95, 200 + 42, 3);
    addObstacle(5605, 0, 85, 200, 0.59f, 0.863f, 0.039f);
    drawBorder(5605, 0, 5605 + 85,  200, 3);

    addRiver(5950, 0, 250, 100, 0.55f, 0.53f, 0.94f);

    addObstacle(5800, 400, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(5800, 400, 5800 + 95, 400 + 42, 3);
    addObstacle(5805, 0, 85, 400, 0.59f, 0.863f, 0.039f);
    drawBorder(5805, 0, 5805 + 85,  400, 3);

    addObstacle(5900, 600, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(5900, 600, 5900 + 95, 600 + 42, 3);
    addObstacle(5905, 0, 85, 600, 0.59f, 0.863f, 0.039f);
    drawBorder(5905, 0, 5905 + 85,  600, 3);

    addObstacle(6100, 350, 95, 42, 0.59f, 0.863f, 0.039f);
    drawBorder(6100, 350, 6100 + 95, 350 + 42, 3);
    addObstacle(6105, 0, 85, 350, 0.59f, 0.863f, 0.039f);
    drawBorder(6105, 0, 6105 + 85,  350, 3);

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

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
inline void renderBitmapString(const float x, const float y, const float z, void *font, const char *string) {
    glRasterPos3f(x, y, z);
    for (const char *c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


//Exit Function
inline void exit1(int value) {
    glutTimerFunc(10, exit1, 0);
    exit(0);
}



// Function to handle the display
inline void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (lives > 0) {
        if (isStage1) {
            glutHideWindow();
            startRiverGame();
            glutShowWindow();
        } else if (isStage2) {
            cameraMovement();
            drawStage02();
        } else if (isStage3) {
            glutHideWindow();
            startFlappyGame();
            glutShowWindow();
        } else {
            glutShowWindow();
            displayMenu();
        }
    } else {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(250.0f, 400.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, R"(GAME OVER)");

        glFlush(); // Render now

        glutTimerFunc(2000, exit1, 0);
    }
    glutSwapBuffers();
}

//Function to handle key presses
inline void specialKeyPressed(const int key, const int x, const int y) {
    playerCharacter.specialKeyPressed(key, x, y);
}


//Function to handle key releases
inline void specialKeyReleased(const int key, const int x, const int y) {
    playerCharacter.specialKeyReleased(key, x, y);
}


// Function to set up the OpenGL environment
inline void init() {
    glClearColor(0.239f, 0.584f, 0.639f, 1.0f); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, coordinateX, 0, coordinateY); // Set the coordinate system
}


// Function to handle window resizing
inline void reshape(const int width, const int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}


#endif //MAIN_H
