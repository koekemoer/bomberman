//#include "/goinfre/lkoekemo/.brew/include/SDL/SDL.h"
//#include <SDL/SDL.h>
//#include <OpenGL/GL.h>
#ifndef MAINGAME_HPP
# define MAINGAME_HPP

//#include "Sprite.hpp"

#ifdef __APPLE__
#   include <SDL2/SDL.h>
//#   include <SDL2/SDL.h>
#   include <OpenGL/gl.h>
//#   include <SDL2/SDL_open_gl.h>
//#   include <GL/gl.h>
#else
#   include <SDL2/SDL.h>
#   include <GL/gl.h>
#endif

enum class GameState {PLAY, EXIT};

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

	SDL_Window*	 _window;
    SDL_Surface* _surface;
	int 		 _screenW;
	int 		 _screenH;
    GameState    _state;

	//Sprite _sprite;

};

#endif