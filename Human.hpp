#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Entity.hpp"

class Human : public Entity
{
    public:
        Human();
        ~Human();

    private:
        int     _numLives;
}

#endif