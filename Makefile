OBJS = *.cpp

NAME = game_tut

CC = clang++ -std=gnu++11

C_FLAGS = -Wall -Werror -Wextra

#SRC = *.cpp

#OBJ = $(SRC:*.cpp=%.o)

#SDL_FLAGS =$(shell sdl-config --cflags)
#SDL_LIBS = $(shell sdl-config --libs)

SDL2_FLAGS	:= $(shell pkg-config --cflags sdl2) #-lm
SDL2_LIBS	:= $(shell pkg-config --libs sdl2)
#GL_FLAGS	= -lGL

GL_FLAGS 	:= $(shell pkg-config --cflags gl)
GL_LIBS		:= $(shell pkg-config --libs gl)

GFX_FLAGS	= $(SDL2_FLAGS) $(GL_FLAGS)

#INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include -I/goinfre/aswanepo/.brew/Cellar/glew/2.0.0/include -I/goinfre/aswanepo/.brew/Cellar/glfw/3.2.1/include/

#LIBRARY_PATHS = -L/usr/local/lib -L/opt/X11/lib -L/goinfre/aswanepo/.brew/Cellar/glew/2.0.0/lib -L/goinfre/aswanepo/.brew/Cellar/glfw/3.2.1/lib/

#SDL_INC = -I/goinfre/lkoekemo/.brew/include
#SDL_LIB = -L/goinfre/lkoekemo/.brew/lib
LINKER_FLAGS = -lSDL2 -lGL -lGLEW #-framework OpenGL -lglew -lglfw -lGL -lglut -lGLEW

all: $(OBJS)
		$(CC) $(OBJS) $(LINKER_FLAGS) -o $(NAME)

clean:
	@rm -f $(NAME)

#fclean: clean
	#@rm -f $(NAME)

#re: fclean all
