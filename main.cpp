
//#include <SDL/SDL.h>
//#include <GL/GL.h>
#include <iostream>
#include "MainGame.hpp"

int     main(int ac, char** av)
{
    if (ac == 1 && av[1] == nullptr)
        ;
    MainGame game;
    game.run();

    //SDL_Quit();
    return (0);
}
