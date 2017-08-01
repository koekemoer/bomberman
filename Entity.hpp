#ifndef ENTITY_HPP
# define ENTITY_HPP

#ifdef __APPLE__
#   include <SDL2/SDL.h>
#   include <OpenGL/gl.h>
#else
#   include <SDL2/SDL.h>
#   include <GL/gl.h>
#endif

class   Entity {
    public:
        Entity();
        ~Entity();
        Entity(const Entity & rhs);
        Entity& operand=(const Entity & rhs);

    private:
        int     _posX;
        int     _posY;
};


#endif