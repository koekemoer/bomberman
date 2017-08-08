//#include "MainGame.hpp"
#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
    init();
}

SplashScreen::~SplashScreen() {}

void    SplashScreen::init()
{
    images.push_back(IMG_Load("bomber_pic.png"));
}

void    SplashScreen::draw()
{
    SDL_BlitSurface(images[0], NULL, _screenSurface, NULL);
    SDL_UpdateWindowSurface(_window);
    SDL_Delay(1500);
}