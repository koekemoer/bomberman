OBJS = main.cpp MainGame.cpp SplashScreen.cpp

NAME = game_tut

CC = clang++ -std=gnu++11

C_FLAGS = -Wall -Werror -Wextra

GFX_FLAGS	= $(SDL2_FLAGS) $(GL_FLAGS)
GFX_LIBS	= $(SDL2_LIBS) $(GL_LIBS)

#APPLE_FLAGS = -framework OpenGL -framework SDL2#-framework OpenGL -lglew -lglfw -lGL -lglut -lGLEW
APPLE_FLAGS = -framework OpenGL -framework SDL2 -framework SDL2_image -framework SDL_image
LINUX_FLAGS = -lGL -lSDL2 -lSDL2_image -lSDL_image

OS := $(shell uname)
ifeq ($(OS),Darwin)
	COMPILE := $(CC) $(C_FLAGS) $(OBJS) $(APPLE_FLAGS) -o $(NAME)
else
	COMPILE := $(CC) $(C_FLAGS) $(OBJS) $(LINUX_FLAGS) -o $(NAME)
endif

all: $(OBJS)
		$(COMPILE)

clean:
	@rm -f $(NAME)