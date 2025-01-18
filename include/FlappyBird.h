#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <string>
#include "Character.h"
#include "menu.h"
#define max_pipes 5

// Game parameters
inline float star_rotate = 0.0;
inline int window_width = 800;
inline int window_height = 600;
inline float bird_x = 200, bird_y = 300;
inline Character mario (0,0);
inline float bird_velocity = 0, bird_gravity = -0.3, bird_lift = 5.0;
inline bool is_jumping = false;
struct Pipe {
    int x;
    int gap_position;
    bool passed;
};

inline Pipe pipes[max_pipes]; // Now max_pipes is a constant expression
inline int pipe_gap = 200;
inline int pipe_width = 80;
inline float pipe_velocity = -2.0;

// Game state
inline bool game_over = false;
inline int num_pipes = 0;
inline int scoreFlappy = 0;

inline bool show_text = false;
inline std::string display_text;
inline int text_timer = 0;

// Function to draw the bird
inline void draw_bird() {
    glPushMatrix();
    glTranslatef(bird_x, bird_y, 0);
    mario.draw();
    glPopMatrix();
}

inline void updateStar(int value) {
    star_rotate += 2.5; // Increment the angle for smooth rotation
    if (star_rotate > 360) {
        star_rotate -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateStar, 0); // Call update every 16 milliseconds (~60 FPS)
}

inline void drawStar()
{
    glPushMatrix();
    glLineWidth(3);
    glRotatef(star_rotate, 0, 0, 1.0); // Rotate around the z-axis
    glColor3f(0.878, 0.337, 0.129);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.3, -0.3);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.4, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.3, 0.3);
    glEnd();
    glPopMatrix();
    glLineWidth(1);
}

// Function to draw pipes
inline void draw_pipes() {
    glColor3f(0.137, 0.812, 0.239);
    for (int i = 0; i < num_pipes; i++) {
        glPushMatrix();
        glTranslatef(pipes[i].x, pipes[i].gap_position + pipe_gap / 2, 0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(pipe_width, 0);
        glVertex2f(pipe_width, window_height - pipes[i].gap_position - pipe_gap / 2);
        glVertex2f(0, window_height - pipes[i].gap_position - pipe_gap / 2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(pipes[i].x, pipes[i].gap_position - pipe_gap / 2, 0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(pipe_width, 0);
        glVertex2f(pipe_width, -pipes[i].gap_position + pipe_gap / 2);
        glVertex2f(0, -pipes[i].gap_position + pipe_gap / 2);
        glEnd();
        glPopMatrix();
    }
}

// Function to draw the scoreFlappy
inline void draw_score() {
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(10, window_height - 30);
    std::string score_text = "Score: " + std::to_string(scoreFlappy);
    for (const char c : score_text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

// Function to draw text at the bottom
inline void draw_text() {
    if (show_text) {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(10, 10);
        for (const char c : display_text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

inline std::vector<std::string> mischievous_messages = {
    "Just 5 more points, and you'll unlock the secret level! (Oops, I lied.)",
    "One more try, and you'll be crowned the champion! (Or not.)",
    "You're so close! (Well, not really, but keep going!)",
    "Just one more attempt, and you'll see magic happen! (Spoiler: No magic.)",
    "You're totally winning this... in an alternate universe.",
    "Almost there! (Almost nowhere, actually.)",
    "Just 3 more points, and you'll beat the impossible! (I made that up.)",
    "You're crushing it! (Actually, it's crushing you.)",
    "Keep going, you're almost a legend! (A legend in my storybook of lies.)",
    "Believe in yourself, and miracles will happen! (I promise nothing.)",
    "You're unstoppable! (Unless you stop, which is highly likely.)",
    "So close! Just one more score! (Sorry, false alarm.)",
    "You’re doing great! (At making me laugh.)",
    "You’re amazing! (At being gullible!)",
    "Keep going, you'll definitely win! (In my dreams.)",
    "You’ve got this! (You don’t, but it’s fun to watch.)",
    "The treasure is near! (It’s a participation trophy, though.)",
    "You’re on fire! (That’s the game breaking you.)",
    "Almost broke your record! (Your record of failure, that is.)",
    "Keep playing, and you’ll win… eventually. (Define 'eventually.')",
    "Success is around the corner! (A very sharp corner.)",
    "Believe in the process! (It’s a process of losing.)",
    "You're so close! (So close to rage-quitting.)",
    "Every failure brings you closer to success! (But not this time.)",
    "If frustration were a skill, you'd be a grandmaster.",
    "I’ve seen toddlers with better reflexes.",
    "Your controller is probably more talented than you.",
    "It’s okay; not everyone was born to win. Just you.",
    "Keep going! The leaderboard needs someone at the bottom.",
    "Remember, it’s not the game; it’s you.",
    "Retry button feeling warm yet?",
    "You make mediocrity look effortless.",
    "Don’t worry, even losers have a fan club. (It’s empty.)",
    "Practice makes perfect. You must need a lot of practice.",
    "A true sigma embraces failure—it builds character.",
    "You lose today, but you win the war. (Eventually.)",
    "The grind never stops—except for you, apparently.",
    "No one remembers second place. You're way safer than that.",
    "Mastery takes time. You've got time, right?",
    "Don’t let the game define you. You’re already defined.",
    "The struggle is the path. Yours just looks longer.",
    "Winning is a mindset. Losing is your reality.",
    "Only the strong survive. You’re testing the limits.",
    "Keep climbing; there’s no summit for greatness.",
    "Winners don’t complain—they win. So what are you doing?",
    "Hustlers don’t quit. Why are you hesitating?",
    "This game doesn’t beat you. You beat yourself.",
    "Success is a decision. Losing is your choice.",
    "Every second you spend losing is time wasted.",
    "You want to be a top G? Play like it.",
    "Life’s a game; you’re playing on easy mode and still losing.",
    "Nobody remembers who almost made it.",
    "Your struggle is your weakness showing itself.",
    "This game separates the wolves from the sheep. Guess which you are?",
    "Just a little more effort, and you’ll achieve something… small.",
    "Every jump is a step toward enlightenment. (Or insanity.)",
    "You’re not bad; you’re just not good either.",
    "Every tap is a lesson. (Mostly in how to fail.)",
    "The world isn’t watching, but I am—and it’s hilarious.",
    "What doesn’t kill you makes you… angrier.",
    "The struggle is real. Your skill isn’t.",
    "You’re halfway to greatness! (Halfway to losing, too.)",
    "Every fail is another step toward the Hall of Shame.",
    "Greatness takes time. You’re on lifetime mode.",
    "Retrying is a sign of hope—or denial.",
    "You’re not bad at the game; the game is bad at you.",
    "Your potential is limitless. Your skills, not so much.",
    "One more loss and you’ll unlock a participation badge.",
    "Winning isn’t everything. But for you, it’s nothing.",
    "This is why we can’t have nice things.",
    "The game isn’t hard; you’re just soft.",
    "Your patience is legendary. Your performance? Not so much.",
    "The game isn’t rigged; you are.",
    "You’ve discovered a new skill: consistency in failure.",
    "Every time you fail, you’re learning. (But are you, though?)",
    "You’re unstoppable! (Mostly because you keep failing.)",
    "Every tap is a step closer to victory! (Or another loss.)",
    "Dream big, play small.",
    "Your effort is inspiring. Your results, not so much.",
    "Success is a journey. You’re still in the parking lot.",
    "Keep trying; I’m enjoying the show.",
    "The leaderboard is waiting… for someone else.",
    "Don’t stop now! (Seriously, don’t stop. I’m bored.)",
    "Progress is slow, but you’re slower.",
    "You’re not failing; you’re just exploring creative ways to lose.",
    "Keep going, champ. Someone has to be last.",
    "If this were a talent show, you’d be the comedic relief.",
    "You're giving the retry button a workout.",
    "You miss 100% of the shots you take. Wait, that’s not right.",
    "Success isn’t for everyone. You’re proving that.",
    "Every fail is a story—mostly of embarrassment.",
    "Some call it persistence; others call it stubbornness.",
    "You’re redefining what it means to lose.",
    "Your dedication is admirable. Your results? Not so much.",
    "A true warrior doesn’t quit. You just keep losing.",
    "Your persistence is inspiring. Your skill, not so much.",
    "Failure is a stepping stone. You’re building a staircase.",
    "You’re forging your legacy… in the Hall of Lame.",
    "This game is your Everest. You’re still in base camp.",
    "Legends are made, not born. But not everyone is a legend.",
    "If effort alone won games, you’d be a champion.",
    "Your grind is unmatched. So is your ability to lose.",
    "There’s no shame in losing—just in losing this badly.",
    "Greatness is calling. You’re not picking up.",
    "You're creating history! (In the fail logs.)",
    "Just one more try and you'll be famous! (In the blooper reels.)",
    "You’re unstoppable! (Like a car with no brakes—straight to failure.)",
    "You’re so close! (Close to giving up.)",
    "Your gameplay is… unique. Let’s call it that.",
    "You’ve unlocked a new achievement: Determined Loser.",
    "You’re rewriting the definition of persistence.",
    "Legends fail too… but not this much.",
    "You’re an inspiration. (To never give up, no matter how bad you are.)",
    "Keep going, hero. (Villains need someone to laugh at.)"
};

// Function to update the text display based on score
inline void updateText(const int score) {
    static int last_score = 0;
    if (score != last_score) {
        if (score % 5 == 0 && rand() % 2 == 0) { // Show a message every 5 points with a 50% chance
            show_text = true;
            display_text = mischievous_messages[rand() % mischievous_messages.size()];
        } else {
            show_text = false;
        }
        last_score = score;
    }
}

// Function to update the game state
inline void updateFlappy(int value) {
    if (!game_over) {
        if (is_jumping) {
            bird_velocity = bird_lift;
            is_jumping = false;
        } else {
            bird_velocity += bird_gravity;
        }
        bird_y += bird_velocity;

        if (bird_y <= 0) {
            bird_y = 0;
            bird_velocity = 0;
        } else if (bird_y >= window_height) {
            bird_y = window_height;
            bird_velocity = 0;
        }

        for (int i = 0; i < num_pipes; i++) {
            pipes[i].x += pipe_velocity;
            if (!pipes[i].passed && pipes[i].x + pipe_width < bird_x) {
                scoreFlappy++;
                pipes[i].passed = true;
                updateText(scoreFlappy); // Call updateText with the current score
            }
        }

        if (num_pipes == 0 || pipes[num_pipes - 1].x < window_width - 300) {
            pipes[num_pipes].x = window_width;
            pipes[num_pipes].gap_position = rand() % (window_height - pipe_gap) + pipe_gap / 2;
            pipes[num_pipes].passed = false;
            num_pipes++;
        }

        if (num_pipes > 0 && pipes[0].x + pipe_width < 0) {
            for (int i = 1; i < num_pipes; i++) {
                pipes[i - 1] = pipes[i];
            }
            num_pipes--;
        }

        for (int i = 0; i < num_pipes; i++) {
            if (bird_x + 10 > pipes[i].x && bird_x - 10 < pipes[i].x + pipe_width) {
                if (bird_y - 10 < pipes[i].gap_position - pipe_gap / 2 || bird_y + 10 > pipes[i].gap_position + pipe_gap / 2) {
                    game_over = true;
                    break;
                }
            }
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateFlappy, 0);
}

// Function to displayFlappy the game
inline void displayFlappy() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw gradient background
    glBegin(GL_QUADS);
    glColor3f(0.122, 0.122, 0.114); // Top-left color
    glVertex2f(0, window_height);
    glColor3f(0.122, 0.122, 0.114); // Top-right color
    glVertex2f(window_width, window_height);
    glColor3f(0.388, 0.388, 0.38); // Bottom-right color
    glVertex2f(window_width, 0);
    glColor3f(0.388, 0.388, 0.38); // Bottom-left color
    glVertex2f(0, 0);
    glEnd();

    if (game_over) {
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2f(window_width / 2 - 50, window_height / 2);
        const auto message = "GAME OVER";
        for (int i = 0; message[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
        }
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(window_width / 2 - 80, window_height / 2 - 40);
        const auto restart_msg = "Press ENTER to Restart";
        for (int i = 0; restart_msg[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, restart_msg[i]);
        }
        glRasterPos2f(window_width / 2 - 80, window_height / 2 - 80);
        const auto main_menu_msg = "Press M for Main Menu";
        for (int i = 0; main_menu_msg[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, main_menu_msg[i]);
        }
        glRasterPos2f(window_width / 2 - 50, window_height / 2 - 120);
        std::string score_text = "Score: " + std::to_string(scoreFlappy);
        for (const char c : score_text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else {
        draw_bird();
        draw_pipes();
        draw_score();
        drawStar(); // Draw stars on the screen
        draw_text();  // Draw text at the bottom
    }

    glFlush();
    glutSwapBuffers();
}

// Function to handle keyboard input
inline void keyboardFlappy(const unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }

    if (key == 13) {
        if (game_over) {
            game_over = false;
            bird_x = 200;
            bird_y = 300;
            bird_velocity = 0;
            scoreFlappy = 0;
            num_pipes = 0;

            for (auto &[x, gap_position, passed] : pipes) {
                x = 0;
                gap_position = 0;
                passed = false;
            }

            glutDisplayFunc(displayFlappy);
            glutPostRedisplay();
        }
    }

    if (key == 'm' || key == 'M') {
        if (game_over) {
            glutDisplayFunc(displayMenu); // Ensure displayMenu is defined in Menu.h
            glutPostRedisplay();
        }
    }
}

// Function to handle special key input (up arrow for jumping, right arrow for advancing pipes)
inline void special_keyboardFlappy(const int key, int x, int y) {
    if (key == GLUT_KEY_UP && !game_over) {
        is_jumping = true;
    }
    if (key == GLUT_KEY_RIGHT && !game_over) {
        for (int i = 0; i < num_pipes; i++) {
            pipes[i].x -= 100; // Advance the pipes to the left
        }
    }
}

// Function to initialize the game
inline void initFlappy() {
    glClearColor(0.239, 0.584, 0.639, 1.0);
    glOrtho(0, window_width, 0, window_height, -1, 1);
}

// Function to start the game
inline void startFlappyGame() {
    srand(time(nullptr));


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Flappy Bird in Space");

    initFlappy();

    glutDisplayFunc(displayFlappy);
    glutKeyboardFunc(keyboardFlappy);
    glutSpecialFunc(special_keyboardFlappy);
    glutTimerFunc(25, updateFlappy, 0);
    glutTimerFunc(16, updateStar, 0); // Start the star update timer
    glutTimerFunc(1000, updateText, 0); // Start the text update timer
    glutReshapeFunc([](int w, int h) { glutReshapeWindow(window_width, window_height); }); // Disable window resizing
    glutMainLoop();
}

#endif // FLAPPYBIRD_H