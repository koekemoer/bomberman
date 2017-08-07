#include "Entity.hpp"

Entity::Entity() {
    _posX = 0;
    _posY = 0;
    //_numLives = 3;
}

Entity::~Entity() {

}

/*Entity::Entity(const Entity & rhs) {
    _posX = rhs._posX
    _posY = rhs._posY
}*/

/*Entity& Entity::operator=(const Entity & rhs) {
    
}*/

void    Entity::moveLeft() {
    _posX -= 4;
}

void    Entity::moveRight() {
    _posX += 4;
}

void    Entity::moveUp(); {
    _posY -= 4;
}

void    Entity::moveDown() {
    _posY += 4;
}