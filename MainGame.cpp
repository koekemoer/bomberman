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
	std::cout << "CONSTRUCTOR1" << std::endl;
	_window = nullptr;
	std::cout << "CONSTRUCTOR2" << std::endl;
	_surface = nullptr;
	std::cout << "CONSTRUCTOR3" << std::endl;
	_screenW = 1024;
	std::cout << "CONSTRUCTOR4" << std::endl;
	_screenH = 768;
	std::cout << "CONSTRUCTOR5" << std::endl;
	_state = GameState::PLAY;
	std::cout << "CONSTRUCTOR6" << std::endl;
	//DOESNT WORK ON MAC
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	std::cout << "CONSTRUCTOR7" << std::endl;
}

MainGame::~MainGame() {
	SDL_Quit();
}

// main game
void	MainGame::run() {
	initSystems();

	//_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

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
	{
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
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
			case SDL_KEYDOWN:
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
				}
				break;
		}

	}
}

void 	MainGame::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//_sprite.draw();
	//Swap buffer and draw everything to screen
	SDL_GL_SwapWindow(_window);

	//Get Window Surface
	/*_surface = SDL_GetWindowSurface(_window);
	//Fill Surface White
	SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF));
	//Update Surface
	SDL_UpdateWindowSurface(_window);*/
}