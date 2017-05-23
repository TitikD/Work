//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    double velocityX = drand48();
    double velocityY = 2;
    bool start = false;
    
    waitForClick();
    start = true;
    printf("Game was started\n");
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        GEvent mouse = getNextEvent(MOUSE_EVENT);
        if (mouse != NULL)
        {
            if (getEventType(mouse) == MOUSE_MOVED)
            {
                setLocation(paddle, getX(mouse) - 30, HEIGHT-10);
            }
        }      
        if(getX(ball) <= 0 || getX(ball) + RADIUS*2 >= WIDTH)
        {
            printf("Bounce\n");
            velocityX = - velocityX;
            
        }else
        if(getY(ball) <= 0 )
        {
            printf("Bounce\n");
            velocityY = - velocityY;
            
        }else
        if(getY(ball) + RADIUS*2 >= HEIGHT)
        {
            printf("Oops\n");
            lives -= 1;
            waitForClick();
            setLocation(ball, WIDTH/2, HEIGHT/2);
        }
        GObject object = detectCollision (window, ball);
 
        if (object == paddle)
        {
            velocityY = -velocityY;
        }
         if (object != NULL)
        {
            // if object (brick) hit (not the paddle or scoreboard)
            if (strcmp(getType(object), "GRect") == 0 && object != paddle && object != label)
            {
                removeGWindow(window, object);
                velocityY = -velocityY;
                points = points + 1;
                updateScoreboard (window, label, points);
            }
        }
        move(ball, velocityX, velocityY);        
        pause(20);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int x = 10, y = 30;
	for(int i = 0; ROWS > i; i++)
	{
	    for(int j = 0; COLS > j; j++)
	    {
	       GRect bricks = newGRect(x,y, 30, 8);
	        setColor(bricks, "black");
	        setFilled(bricks, true);
	        add(window, bricks);
	        x = x + WIDTH/10-1;
	    }
	    x = 10;
	    y = y + 18;
	}
	printf("Bricks was created\n");
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2,HEIGHT/2,RADIUS * 2,RADIUS * 2);
    setColor(ball, "black");
	setFilled(ball, false);
	add(window, ball);
	printf("Ball was created\n");
    return ball; 
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(WIDTH/2,HEIGHT-10, 60, 8);
	setColor(paddle,"red");
	setFilled(paddle,true);
	add(window, paddle);
	printf("Paddle was created\n");
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel (" ");
    add (window, label);
    setLocation(label, 100, 100);
    setFont(label, "ComicSans");
    printf("Lable was created\n");
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
