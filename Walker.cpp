#define WIDTH (600)
#define HEIGHT (400)

#include "Walker.h"


Walker::Walker(float m, int x, int y) {
	mass = m;
	location.setX(x);
	location.setY(y);
	location = Vector2D(x, y);
  rect.x = 0;
  rect.y = 250;
  rect.w = 600;
  rect.h = 150;
}
void Walker::applyForce(Vector2D &force) {
	acceleration += (force / mass);
}
void Walker::update() {
  getFluid();
	velocity += acceleration;
	location += velocity;
  
	acceleration * 0;
}

void Walker::draw(SDL_Renderer *renderer) {  
	filledCircleColor(
		renderer, location.getX(), location.getY(), mass, 0x66333333);
}

void Walker::checkEdges() {
	if (location.getX() > WIDTH) {
		location.setX(WIDTH);
		velocity.setX(velocity.getX() * (-1));
	} else if (location.getX() < 0) {
		velocity.setX(velocity.getX() * (-1));
		location.setX(0);
	}

	if (location.getY() > HEIGHT) {
		velocity.setY(velocity.getY() * (-1));
		location.setY(HEIGHT);
	}
}

void Walker::rectDraw(SDL_Renderer* renderer)
{
  
  SDL_SetRenderDrawColor( renderer, 255, 0, 255, 120 );
  SDL_RenderFillRect( renderer, &rect );
}

Vector2D& Walker::getFluid()
{
  
  if(location.getY() > rect.y || check == true)
  {
    check = false;
    velocity *= 0.5;
    return velocity;
  }
  else 
  {
    return empty;
  }
}
Vector2D& Walker::getGravity()
{
  return gravity;
}