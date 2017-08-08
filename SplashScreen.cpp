//#include "MainGame.hpp"
#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
    init();
}

SplashScreen::~SplashScreen() { IMG_Quit(); }

void    SplashScreen::init()
{
    images.push_back(IMG_Load("bomber_pic.png"));
}

void    SplashScreen::draw()
{
    IMG_Init(IMG_INIT_PNG);

    renderer = SDL_CreateRenderer(_window, -1, 0);
    imgSurface = IMG_Load(images[0]);
    texture = SDL_CreateTextureFromSurface(renderer,imgSurface);

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    //SDL_BlitSurface(images[0], NULL, _screenSurface, NULL);
    SDL_UpdateWindowSurface(_window);
    SDL_Delay(1500);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(imgSurface);
    SDL_DestroyRenderer(renderer);
}