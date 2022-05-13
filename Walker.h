#pragma once

#include "usr/include/SDL2/SDL.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
#include "Vector2D.h"
class Walker 
{
  int _x, _y;
  float mass = 1;  
  Vector2D velocity = Vector2D(0,0);
  Vector2D acceleration = Vector2D(0,0);
  Vector2D location = Vector2D(30,30);
  Vector2D wind = Vector2D(0.01,0);
  Vector2D gravity = Vector2D(0,0.1*mass);
  Vector2D fluid = Vector2D(0,-0.07*mass);
  Vector2D empty = Vector2D(0,0);
  SDL_Rect rect;
  bool check = true;
public:
  Walker(float m, int x, int y);
  void draw(SDL_Renderer* renderer);
  void update();
  void applyForce(Vector2D& force);
  void checkEdges();
  void rectDraw(SDL_Renderer* renderer);
  Vector2D& getFluid();
  Vector2D& getGravity();
};