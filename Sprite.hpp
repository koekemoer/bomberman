#ifndef SPRITE_HPP
# define SPRITE_HPP

#include <GL/glew.h>

class Sprite
{
public:
    Sprite();
    ~Sprite();
    //Sprite(const Sprite &rhs);
    //Sprite& operator=(const Sprite &rhs);

    void    init(float x, float y, float width, float height);
    void    draw();

private:
    float     	_x;
    float     	_y;
    float		_width;
	float		_height;
	GLuint		_vboID;	//(v)ertex (b)uffer (o)bject.  GLuint - guaranteed to be 32 bit int
};

#endif
