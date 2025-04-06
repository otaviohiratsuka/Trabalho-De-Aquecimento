#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include "Floresta.hpp"

class Animal{
private:
    int x,y;
    int passos, ciclosPreso, findAgua;
    bool vivo;

    public:
    Animal(int startX, int startY);

    void mover(Floresta& floresta);
    void chegouAgua(Floresta& floresta);
    void checkQueimou(Floresta& floresta);

    int getX() const;
    int getY() const;
    int getPassos() const;
    int getFoundAgua() const;
    bool estaVivo() const;

};
#endif