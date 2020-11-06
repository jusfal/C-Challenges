#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Paddle.h"
#include "Ball.h"
#include "InputState.h"
#include "Text.h"

//Definitions 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
int playerScore = 0;
int aiScore = 0;
bool quit = false;
bool AABBcol(SDL_Rect* rectA, SDL_Rect* rectB);

Ball ball = Ball(400, 240, 32, 32, 5, 5);
Paddle leftPaddle = Paddle(0, 200, 32, 128, 4);
Paddle rightPaddle = Paddle(SCREEN_WIDTH - 32, 200, 32, 128, 4);
InputState inputState;
Text playerScoreText = Text(120, 100, 25, 50);
Text aiScoreText = Text(650, 100, 25, 50);

//Functions
void Load(SDL_Renderer*);
bool HandleInput();
void Update();
void Draw(SDL_Renderer*);
void Close(SDL_Window*, SDL_Renderer*);

//Program
int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//init Window
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3);

	//Load
	Load(renderer);

	while (!quit)
	{
		//Inputs
		quit = HandleInput();

		//Update
		Update();

		//Draw
		Draw(renderer);
	}

	//End 
	Close(window, renderer);

	return 0;
}

void Load(SDL_Renderer* renderer)
{
	playerScoreText.load(renderer, "0");
	aiScoreText.load(renderer, "0");
}

void Update()
{
	ball.update(SCREEN_WIDTH, SCREEN_HEIGHT);
	leftPaddle.update(&inputState, SCREEN_HEIGHT);
	rightPaddle.updateAI(SCREEN_HEIGHT, ball.y);

	//Collisions
	SDL_Rect ballRect = ball.toRect();
	SDL_Rect leftPaddleRect = leftPaddle.toRect();
	SDL_Rect rightPaddleRect = rightPaddle.toRect();
	if (AABBcol(&ballRect, &leftPaddleRect))
	{
		ball.horizontalBounce(leftPaddleRect.x + leftPaddleRect.w);
	}
	if (AABBcol(&ballRect, &rightPaddleRect))
	{
		ball.horizontalBounce(rightPaddleRect.x - ballRect.w);
	}
	//Points
	if (ball.getX() < 0)
	{
		++aiScore;
		ball.setX(SCREEN_WIDTH / 2);
	}
	else if (ball.getX() > SCREEN_WIDTH - ball.getWidth())
	{
		++playerScore;
		ball.setX(SCREEN_WIDTH / 2);
	}

}

bool HandleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym ==  SDLK_z)
			{
				inputState.paddleUp = true;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = true;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_z)
			{
				inputState.paddleUp = false;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = false;
			}
		}
		else if (e.type == SDL_QUIT)
		{
			return true;
		}
	}
	return false;
}

void Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x50, 0xFF);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	playerScoreText.draw(renderer);
	aiScoreText.draw(renderer);
	ball.draw(renderer);
	leftPaddle.draw(renderer);
	rightPaddle.draw(renderer);
	SDL_RenderPresent(renderer);
}

void Close(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool AABBcol(SDL_Rect* rectA, SDL_Rect* rectB)
{
	int xMinA = rectA->x;
	int xMaxA = rectA->x + rectA->w;
	int yMinA = rectA->y;
	int yMaxA = rectA->y + rectA->h;
	int xMinB = rectB->x;
	int xMaxB = rectB->x + rectB->w;
	int yMinB = rectB->y;
	int yMaxB = rectB->y + rectB->h;
	return !(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
}