#include "MainGame.hpp"
#include <iostream>

void 	fatalError(std::string errorStr)
{
	std::cout << errorStr << std::endl;
	std::cout << "Press Any key to quit" << std::endl;
	int	tmp;
	std::cin >> tmp;
	SDL_Quit();
}

MainGame::MainGame()
{
	_window = nullptr;
	_screenSurface = nullptr;
	sprite = SDL_LoadBMP("sprite.bmp");
	_bmbrman.x = 0;
	//_bmbrman._posX = 0;
	_bmbrman.y = 0;
	//_bmbrman._posY = 0;
	_screenW = 1024;
	_screenH = 768;
	_state = GameState::PLAY;
	#ifndef __APPLE__
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	#endif
}

MainGame::~MainGame() {
	SDL_Quit();
}

// main game
void	MainGame::run() {
	initSystems();

	gameLoop();
}

void	MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	//SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	_window = SDL_CreateWindow("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenW, _screenH, SDL_WINDOW_OPENGL);
	
	if (_window == nullptr) {
		fatalError("SDL Window could not be created");
	}

	SDL_GLContext gl_context = SDL_GL_CreateContext(_window);
	if (gl_context == nullptr) {
		fatalError("SDL_GL could not be created");
	}

	_screenSurface = SDL_GetWindowSurface(_window);

	int	colorkey;
	colorkey = SDL_MapRGB(_screenSurface->format, 255, 0, 255);
    SDL_SetColorKey(sprite, SDL_TRUE, colorkey);

	//not needed, but for when hardware doesnt' exactly support certain stuff
	/*glewExperimental = true;
	GLenum error = glewInit();
	if (error != GL_OK) {
	  fatalError("could not init GLEW");
  	}*/

	//instead of having one window that draws and clears, have 2 windows essentially - much smoother
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void 	MainGame::gameLoop() {
	while (_state != GameState::EXIT)
	//while (SDL_PollEvent(&evnt))
	{
		/*switch (_state)
		{
			case GameState::PLAY:
			{

				break;
			}
			case GameState::SHOWSPLASH:
			{

				break;
			}
		}*/
		//SplashScreen *screen = new SplashScreen;
		//splash->draw();
		processInput();
		drawGame();
	}
}

void 	MainGame::processInput() {
	// Keeps track of user input
	SDL_Event 	evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_state = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				//std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
			case SDL_KEYDOWN:
				SDL_FillRect(_screenSurface,NULL,0x000000);
				switch (evnt.key.keysym.sym)
				{
					case SDLK_r:
						glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
						std::cout << "R pressed" << std::endl;
						break;
					case SDLK_g:
						glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
						std::cout << "G pressed" << std::endl;
						break;
					case SDLK_b:
						glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
						std::cout << "B pressed" << std::endl;
						break;
					case SDLK_q:
						_state = GameState::EXIT;
						break;
					case SDLK_UP:
						_bmbrman.y -= 2;
						//_bmbrman.moveUp();
						break;
					case SDLK_DOWN:
						_bmbrman.y += 2;
						//_bmbrman.moveDown();
						break;
					case SDLK_RIGHT:
						_bmbrman.x += 2;
						//_bmbrman.moveRight();
						break;
					case SDLK_LEFT:
						_bmbrman.x -= 2;
						//_bmbrman.moveLeft();
						break;
				}
				break;
		}
		SDL_BlitSurface(sprite, NULL, _screenSurface, &_bmbrman);
	}
}

void 	MainGame::drawGame() {
	//glClearDepth(1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//_sprite.draw();
	//Swap buffer and draw everything to screen
	//SDL_GL_SwapWindow(_window);
	//Get Window Surface
	//_surface = SDL_GetWindowSurface(_window);
	//Fill Surface White
	//SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF));
	//Update Surface
	SDL_UpdateWindowSurface(_window);
}

int		MainGame::getScreenW() { return this->_screenW; }

int		MainGame::getScreenH() { return this->_screenH; }