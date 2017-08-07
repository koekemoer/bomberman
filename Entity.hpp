#ifndef ENTITY_HPP
# define ENTITY_HPP

class   Entity {
    public:
        Entity();
        ~Entity();
        //Entity(const Entity & rhs);
        //Entity& operand=(const Entity & rhs);
        
        void    moveLeft();
        void    moveRight();
        void    moveUp();
        void    moveDown();

    private:
        //int     _numLives;   FOR HUMAN
        int     _posX;
        int     _posY;
};


#endif