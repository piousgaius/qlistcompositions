#include <stdio.h>
#include <stdlib.h>
#include <graphics_lib.h>

/* typedef thing */

typedef struct importantCoords
{
  int platTopLeftX;
  int platTopLeftY;
  int platBotRightX;
  int goalTopLeftX;
} importantCoords;

typedef struct coords
{
  int xCoord;
  int yCoord;
} coords;



/* functions */

int menu()
{
  int play = 2;
  /* draw a nice menu or some shit */
  while (play == 2){
    GFX_WaitForEvent();
    GFX_GetKeyPress();
    if (*keypress_ptr == ALLEGRO_KEY_Y){
      play = 1;}
    else if (*keypress_ptr == ALLEGRO_KEY_N){
      play = 0;}}
  return play;
}

void winScreen()
{
  /* display some winscreen */
}

int winCheck(coords ballPos, importantCoords stage)
{
  int win;
  if (ballPos.xCoord >= stage.goalTopLeftX && ballPos.xCoord <= stage.goalTopLeftX + 30){
    win = 1;}
  else {
    win = 0;}
  return win;
}

importantCoords newGame()
{
  importantCoords stage;
  stage.platTopLeftX = GFX_RandNumber(200, 580); /* 580 so there won't be any error two lines down */
  stage.platTopLeftY = GFX_RandNumber(10, 300);
  stage.platBotRightX = GFX_RandNumber(stage.platTopLeftX + 50, 640);
  stage.goalTopLeftX = (stage.platTopLeftX, stage.platBotRightX - 30); /* 30 is size of goal, basically all of these numbers are subject to change depending on looks */
  GFX_DrawFilledRectangle(stage.platTopLeftX, stage.platTopLeftY, stage.platBotRightX, 0, 0 /*BLACK*/); /* platform */
  GFX_DrawFilledRectangle(stage.goalTopLeftX, stage.platTopLeftY + 10, stage.goalTopLeftX + 30, stage.platTopLeftY, 2 /*GREEN*/); /* goal */
  GFX_DrawFilledCircle(50, 20, 20, 5 /*MAGENTA*/); /* (50, 20) is coins centre XY coordinate, coin radius is 20 */
  GFX_UpdateDisplay();
  return stage;
}

coords throw(coords ballPos, importantCoords stage)
{
  int power = /* some power constant */;
  GFX_WaitForEvent();
  int check = GFX_IsEventMouseButton; /* can I combine this line and next? */
  if (check == 1){
    GFX_GetMouseCoordinates();
    int click[2] = {*x_ptr, *y_ptr}; /* check about this */
    /* calculate angle = angle */
    /* check if angle is fucked -- depends on how the angle is being done tbh */
    /* calculate x speed */
    int moving = 1;
    while (moving == 1){
      GFX_DrawFilledCircle(ballPos.xCoord, ballPos.yCoord, 20, 15 /*WHITE*/);
      if (stage.platTopLeftX - ballPos.xCoord <= 20 && ballPos.yCoord < stage.platTopLeftY && ballPos.xCoord < stage.platBotRightX){ /* && ? */
	xSpeed = -xSpeed;
      else if (ballPos.xCoord - stage.platBotRightX <= 20 && ballPos.yCoord < stage.platTopLeftY && ballPos.xCoord > stage.platTopLeftX){
	xSpeed = -xSpeed;
      else if (ballPos.xCoord < 20 || ballPos.xCoord > 620){
       	xSpeed = -xSpeed;
      /* calculate y speed */
      if (ballPos.yCoord >= 380){ /* 20 less than height of window */
	/* y speed = - y speed */
      /* update ballPos.xCoord */
      /* update ballPos.yCoord */
      GFX_DrawFilledCircle(ballPos.xCoord, ballPos.yCoord, 20, 5 /*MAGETA*/);
      GFX_UpdateDisplay();}
      if (ballPos.xCoord >= stage.platTopLeftX && ballPos.xCoord <= stage.platBotRightX && ballPos.yCoord - stage.platTopLeftY <= 20){
	moving = 0;}
      else if (ballPos.yCoord >= 20){
	moving = 0;}
      else {
	/* wait for some amount of time */}}}
}
  
    
/* main function */
    
int main();
{
  /*set up*/
  coords ballPos;
  GFX_InitWindow(640, 400);
  GFX_CreateEventQueue();
  GFX_RegisterMouseEvents();
  GFX_RegisterKeyboardEvents();
  int play = menu();

  /*game bit*/
  while (play == 1){
    int win = 0;
    importantCoords stage =  newGame();
    ballPos.xCoord = 50;
    ballPos.yCoord = 20;
    while (win = 0){
      coords newPos = throw(ballPos, stage);
      ballPos = newPos;
      win = winCheck(ballPos, stage);}
    winScreen();
    GFX_PauseFor(10000);
    play = menu();}
  GFX_CloseWindow();
  return 0;
}
