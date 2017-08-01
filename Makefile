OBJS = main.cpp MainGame.cpp

NAME = game_tut

CC = clang++ -std=gnu++11

C_FLAGS = -Wall -Werror -Wextra

#SRC = *.cpp

#OBJ = $(SRC:*.cpp=%.o)

#SDL_FLAGS =$(shell sdl-config --cflags)
#SDL_LIBS = $(shell sdl-config --libs)

#SDL2_FLAGS	:= $(shell pkg-config --cflags sdl2) #-lm
#SDL2_LIBS	:= $(shell pkg-config --libs sdl2)
#GL_FLAGS	= -lGL

#GL_FLAGS 	:= $(shell pkg-config --cflags gl)
#GL_LIBS		:= $(shell pkg-config --libs gl)

GFX_FLAGS	= $(SDL2_FLAGS) $(GL_FLAGS)
GFX_LIBS	= $(SDL2_LIBS) $(GL_LIBS)

#INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include -I/goinfre/aswanepo/.brew/Cellar/glew/2.0.0/include -I/goinfre/aswanepo/.brew/Cellar/glfw/3.2.1/include/

#LIBRARY_PATHS = -L/usr/local/lib -L/opt/X11/lib -L/goinfre/aswanepo/.brew/Cellar/glew/2.0.0/lib -L/goinfre/aswanepo/.brew/Cellar/glfw/3.2.1/lib/

#SDL_INC = -I/goinfre/lkoekemo/.brew/include
#SDL_LIB = -L/goinfre/lkoekemo/.brew/lib

#APPLE_FLAGS = -framework OpenGL -framework SDL2#-framework OpenGL -lglew -lglfw -lGL -lglut -lGLEW
APPLE_FLAGS = -framework OpenGL -framework SDL2
LINUX_FLAGS = -lGL -lSDL2
#ifeq ($(OS),Apple)
    # ARNO: COMPILE := $(CC) $(SRC) -o $(NAME) -I $(INCLUDES) -L $(FTDIR) -lft $(MAC_GL_FLAGS) $(SDL_FLAGS)
	#COMPILE := $(CC) $(OBJS) -o $(NAME) $(LINKER_FLAGS)
#else
    #c++ $(LDFLAGS) -o $@ $^ $(LIBS)
    #COMPILE := $(CC) $(CXXFLAGS) $(SRC) -o $(NAME) -I $(INCLUDES) -L $(LIBS)
	#COMPILE := $(CC) $(OBJS) $(LINKER_FLAGS) -o $(NAME)
    #COMPILE := $(CC) $(C_FLAGS) $(GL_FLAGS) $(SDL_FLAGS) -I $(INCLUDES) $(SRC) -o $(NAME) -L $(FTDIR) -lft 
#endif
OS := $(shell uname)
ifeq ($(OS),Darwin)
	COMPILE := $(CC) $(C_FLAGS) $(OBJS) $(APPLE_FLAGS) -o $(NAME)
else
	COMPILE := $(CC) $(C_FLAGS) $(OBJS) $(LINUX_FLAGS) -o $(NAME)
endif

#all: $(OBJS)
		#$(CC) $(C_FLAGS) $(OBJS) $(APPLE_FLAGS) -o $(NAME)

all: $(OBJS)
		$(COMPILE)

clean:
	@rm -f $(NAME)