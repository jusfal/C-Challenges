#include <SDL.h>


class Ball
{
public:
	Ball(int pX, int pY, int w, int h,int speedX,int speedY);
	Ball();
	~Ball();

	SDL_Rect toRect();

	void draw(SDL_Renderer * renderer);
	void update(int screenWidth, int screenHeight);

	void setX(int newX);
	int getX() const;

	int getWidth() const;

	void horizontalBounce(int xReplace);
	void verticalBounce(int yReplace);

	int x;
	int y;
	int speedX;

private:
	int width;
	int height;
	int speedY;
};

