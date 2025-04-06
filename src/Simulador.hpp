#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "Floresta.hpp"

class Simulador{
    public:
    void propFogo(Floresta& floresta);
    bool existeFogo(const Floresta& floresta);
};

#endif