#ifndef STAGE_COMPONENTS_H
#define STAGE_COMPONENTS_H

#include <cmath>

#include "GlobalVariables.h"

// Function to draw a hill
inline void drawHill(float x, float hillHeight, float hillWidth) {
    glPushMatrix();
    glTranslatef(x, 101.0f, 0.0f);

    const int numPoints = 100;
    const float step = 2.0f * hillWidth / numPoints;

    // Draw the black border around the hill
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= numPoints; ++i) {
        float t = static_cast<float>(i) / numPoints;
        float angle = t * 3.14159f;
        float yOffset = hillHeight * std::sin(angle);

        // Use black color for the border
        glColor3f(0.0f, 0.0f, 0.0f);

        // Outer border vertices
        glVertex2f(i * step, -yOffset - 3.0f);
        glVertex2f(i * step, yOffset + 3.0f);
    }
    glEnd();

    // Draw the inner hill
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= numPoints; ++i) {
        float t = static_cast<float>(i) / numPoints;
        float angle = t * 3.14159f;
        float yOffset = hillHeight * std::sin(angle);

        // Use green color for the hill
        glColor3f(0.5f, 0.7f, 0.3f);

        // Inner hill vertices (adjusted for the border)
        glVertex2f(i * step, -yOffset);
        glVertex2f(i * step, yOffset);
    }
    glEnd();

    glPopMatrix();
}

// Function to draw a cloud
inline void drawCloud(float x, float y) {
    const int numSegments = 20; // Number of segments for the cloud circle
    const float cloudRadius = 30.0f; // Radius of the cloud circle

    glColor3ub(255, 255, 255); // White color for clouds

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the cloud
    for (int j = 0; j <= numSegments; ++j) {
        float angle = j * (360.0f / numSegments);
        float cloudX = x + cloudRadius * cos(angle * PI / 180.0);
        float cloudY = y + cloudRadius * sin(angle * PI / 180.0);
        glVertex2f(cloudX, cloudY);
    }
    glEnd();

    // Draw more circles to create the cloud shape
    const float additionalRadius1 = 50.0f;
    const float additionalRadius2 = 40.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 60, y); // Center of the second circle
    for (int j = 0; j <= numSegments; ++j) {
        float angle = j * (360.0f / numSegments);
        float cloudX = x + 60 + additionalRadius1 * cos(angle * PI / 180.0);
        float cloudY = y + additionalRadius1 * sin(angle * PI / 180.0);
        glVertex2f(cloudX, cloudY);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 120, y); // Center of the third circle
    for (int j = 0; j <= numSegments; ++j) {
        float angle = j * (360.0f / numSegments);
        float cloudX = x + 120 + additionalRadius2 * cos(angle * PI / 180.0);
        float cloudY = y + additionalRadius2 * sin(angle * PI / 180.0);
        glVertex2f(cloudX, cloudY);
    }
    glEnd();
}

// Function to draw the ground (bricks and lines)
inline void drawGround(float maxXPosition) {
    glPushMatrix(); // Save the current matrix state
    glTranslatef(0.0f, 0.0f, 0.0f); // Adjust the translation if needed

    // Draw the bricks (assuming each brick has a width of 50 units)
    glColor3f(0.545f, 0.271f, 0.075f); // Brown color for bricks
    for (float x = 0.0f; x <= maxXPosition; x += 50.0f) {
        glBegin(GL_QUADS);
        glVertex2f(x, 0.0f);
        glVertex2f(x + 50.0f, 0.0f);
        glVertex2f(x + 50.0f, 100.0f);
        glVertex2f(x, 100.0f);
        glEnd();
    }

    // Draw the lines between bricks along x-axis
    glLineWidth(3.0f); // Increase the line width to make it bolder
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines
    glBegin(GL_LINES);
    for (float x = 0.0f; x <= maxXPosition; x += 50.0f) {
        glVertex2f(x, 0.0f);
        glVertex2f(x, 100.0f);
    }
    glEnd();

    // Draw the lines between bricks along y-axis
    glBegin(GL_LINES);
    for (float y = 0.0f; y <= 100.0f; y += 50.0f) {
        glVertex2f(0.0f, y);
        glVertex2f(maxXPosition, y);
    }
    glEnd();

    glPopMatrix(); // Restore the previous matrix state
}

// Function to draw the ground with a different color
inline void drawGround2(float maxXPosition) {
    glPushMatrix(); // Save the current matrix state
    glTranslatef(0.0f, 0.0f, 0.0f); // Adjust the translation if needed

    // Draw the bricks (assuming each brick has a width of 50 units)
    glColor3f(0.115f, 0.16f, 0.20f); // Different color for bricks
    for (float x = 0.0f; x <= maxXPosition; x += 50.0f) {
        glBegin(GL_QUADS);
        glVertex2f(x, 0.0f);
        glVertex2f(x + 50.0f, 0.0f);
        glVertex2f(x + 50.0f, 100.0f);
        glVertex2f(x, 100.0f);
        glEnd();
    }

    // Draw the lines between bricks along x-axis
    glLineWidth(3.0f); // Increase the line width to make it bolder
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines
    glBegin(GL_LINES);
    for (float x = 0.0f; x <= maxXPosition; x += 50.0f) {
        glVertex2f(x, 0.0f);
        glVertex2f(x, 100.0f);
    }
    glEnd();

    // Draw the lines between bricks along y-axis
    glBegin(GL_LINES);
    for (float y = 0.0f; y <= 100.0f; y += 50.0f) {
        glVertex2f(0.0f, y);
        glVertex2f(maxXPosition, y);
    }
    glEnd();

    glPopMatrix(); // Restore the previous matrix state
}

// Function to draw a border around an object
inline void drawBorder(float x1, float y1, float x2, float y2, float borderWidth) {
    glLineWidth(borderWidth); // Set the desired line width for the border
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the border
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw lines between bricks
inline void drawBrickLines(float minX, float minY, float maxX, float maxY, float brickWidth, float brickHeight, float lineWidth) {
    glPushMatrix(); // Save the current matrix state
    glTranslatef(0.0f, 0.0f, 0.0f); // Adjust the translation if needed

    // Draw the lines between bricks along x-axis
    glLineWidth(lineWidth); // Set the desired line width
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines
    glBegin(GL_LINES);
    for (float x = minX; x <= maxX; x += brickWidth) {
        glVertex2f(x, minY);
        glVertex2f(x, maxY);
    }
    glEnd();

    // Draw the lines between bricks along y-axis
    glBegin(GL_LINES);
    for (float y = minY; y <= maxY; y += brickHeight) {
        glVertex2f(minX, y);
        glVertex2f(maxX, y);
    }
    glEnd();

    glPopMatrix(); // Restore the previous matrix state
}

// Function to draw an arch gate
inline void drawArchGate(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b); // Set the color for the gate

    // Draw the gate using rectangles and a filled arch
    glBegin(GL_QUADS);
    // Draw the main gate structure
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    // Draw the filled arch above the gate
    float centerX = x + width / 2.0f;
    float centerY = y + height;
    float radius = width / 2.0f;

    const int numSegments = 100;
    const float angleStep = 3.14159f / numSegments;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center vertex of the fan

    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleStep;
        float x1 = centerX + radius * std::cos(angle);
        float y1 = centerY + radius * std::sin(angle);
        glVertex2f(x1, y1);
    }

    glEnd();
}

#endif // STAGE_COMPONENTS_H