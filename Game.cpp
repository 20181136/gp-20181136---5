#define WIDTH (600)
#define HEIGHT (400)

#include "Game.h"


#include "Walker.h"
#include <random>
#include "InputHandler.h"

// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 3까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(10, 50);

Game* Game::s_pInstance = 0;


bool Game::setup()
{
  int mkrd[10];
    
  bool result;

  result = init("Nature of Code", 0, 0, WIDTH, HEIGHT, false);
  
  for (int i = 0; i <= 10; i++) {
    mkrd[i] = dis(gen);
    walker[i] = new Walker(mkrd[i],i*70,50);
  }

  
  return result;
}

void Game::update()
{
   
   for (int i = 0; i < 10; i++)
   { 
     
      SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); 
      walker[i]->update();
      walker[i]->checkEdges();
   }
   
}
      
void Game::render()
{
  SDL_RenderClear(m_pRenderer); 
  walker[10]->rectDraw(m_pRenderer);
  for(int i = 0; i < 10 ; i++)
  {
    
    walker[i]->draw(m_pRenderer);
    walker[i]->applyForce(walker[i]->getGravity());
    //walker[i]->applyForce(walker[i]->getFluid());
  }
  
  SDL_RenderPresent(m_pRenderer); 
}

void Game::clean() 
{
   for (int i = 0; i < 10; i++)
   { 
     delete walker[i];
   }
  
  
  TheInputHandler::Instance()->clean();
  
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);

  m_pWindow = NULL;
  m_pRenderer = NULL;

  SDL_Quit();
}

//==================================================

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) 
{  
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
  {
    return false;
  }

  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL);
  
  if (m_pWindow != NULL ) 
  {
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); 
    SDL_RenderClear(m_pRenderer);
  } 
  else 
  {
    return false; // 윈도우 생설 실패 l
  }
  
  m_bRunning = true;
  
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
  
  
  return true;
}

bool Game::running()
{ 
  return m_bRunning; 
}

void Game::handleEvents() 
{
  TheInputHandler::Instance()->update();
}