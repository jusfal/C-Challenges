#pragma once
#include <SDL.h>
#include "InputState.h"

class Paddle
{
public:
	Paddle(int pX, int pY, int w, int h, int pSpeedY);

	SDL_Rect toRect();

	void draw(SDL_Renderer* renderer);
	void update(InputState* state, int screenHeight);

	void updateAI(int screenHeight, int ballY);
	void moveUp(int screenHeight);
	void moveDown(int screenHeight);

	~Paddle();


private:
	int height;
	int width;
	int x;
	int y;
	int speedY;
};

