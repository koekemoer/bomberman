#ifndef SPLASHSCREEN_HPP
# define SPLASHSCREEN_HPP

#include "bomberman.hpp"
//#include <SDL2/SDL2_image.h>
#include "MainGame.hpp"

#include <vector>

class SplashScreen: public MainGame
{
    public:
        SplashScreen();
        ~SplashScreen();
        //void    show();
        
        void    draw();

    private:
        std::vector<SDL_Surface*> images;

        void    init();

};

#endif