#pragma once

#include "usr/include/SDL2/SDL.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
#include "usr/include/SDL2/SDL_image.h"

#include <vector>

class Walker;
class Vector2D;

class Game {
private:
    Game() {}
    static Game* s_pInstance; // 정적 멤버변수 
public:
    static Game* Instance() {
   	  if (s_pInstance == 0) {
        s_pInstance = new Game();
        return s_pInstance;
    	}
    	return s_pInstance;
    }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }

public:
    ~Game() {}

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);
    bool setup();
    void render();
    void update(); 
    bool running();
    void handleEvents();
    void clean();
    void quit() { m_bRunning = false; }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    Walker* walker[10];
    Walker* rectWalker;

};

typedef Game TheGame;