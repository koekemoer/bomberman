#include "Sprite.hpp"

Sprite::Sprite() {
	_vboID = 0;
}

Sprite::~Sprite() {
	if (_vboID != 0) {
		glDeleteBuffers(1, &_vboID);
	}
}

/*Sprite::Sprite(const Sprite & rhs) {
	_x = rhs._x;
	_y = rhs._y;
	_width = rhs._width;
	_height = rhs._height;
}*/

/*Sprite& Sprite::operator=(const Sprite & rhs) {
	_x = rhs._x;
	_y = rhs._y;
	_width = rhs._width;
	_height = rhs._height;
	return *this;
}*/

void 	Sprite::init(float x, float y, float width, float height) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}

	float 	vertexData[12]; // 6 vertexes * 2 (x & y)

	//first triangle in quad (square = quad = 2 triangles)
	//top right
	vertexData[0] = x + width;
	vertexData[1] = y + height;
	//top left
	vertexData[2] = x;
	vertexData[3] = y + height;
	//bottom left
	vertexData[4] = x;
	vertexData[5] = y;

	//second triangle
	//bottom left
	vertexData[6] = x;
	vertexData[7] = y;
	//bottom right
	vertexData[8] = x + width;
	vertexData[9] = y;
	//top right
	vertexData[10] = x + width;
	vertexData[11] = y + height;

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	//to unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void 	Sprite::draw() {
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glEnableVertexAttribArray(0); // 0th index of the array

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6);	//graphics cards work in triangles

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
