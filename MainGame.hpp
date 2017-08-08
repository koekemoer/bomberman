//#include "/goinfre/lkoekemo/.brew/include/SDL/SDL.h"
//#include <SDL/SDL.h>
//#include <OpenGL/GL.h>
#ifndef MAINGAME_HPP
# define MAINGAME_HPP

#include "Entity.hpp"
#include "bomberman.hpp"
#include "SplashScreen.hpp"

enum class GameState {UNINITIALIZED, SHOWSPLASH, PLAY, PAUSE, EXIT};

class   MainGame
{
public:
    MainGame();
    ~MainGame();

    void	run();

private:
    void    gameLoop();
    void    processInput();
    void	initSystems();
    void    drawGame();

	//SDL_Window*	    _window;
    //SDL_Surface*    _screenSurface;
    
    SDL_Surface*	sprite;
    SDL_Rect        _bmbrman;
    //Entity          _bmbrman;

    //SDL_Renderer*   _renderer;
	int 		    _screenW;
	int 		    _screenH;
    GameState       _state;

protected:
    SDL_Window*	    _window;
    SDL_Surface*    _screenSurface;

};

#endif
