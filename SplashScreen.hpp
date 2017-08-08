#ifndef SPLASHSCREEN_HPP
# define SPLASHSCREEN_HPP

#include "MainGame.hpp"
#include "bomberman.hpp"

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
    
        SDL_Renderer    *renderer;
        SDL_Surface     *imgSurface;
        SDL_Texture     *texture;

        void    init();

};

#endif