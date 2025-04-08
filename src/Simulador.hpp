#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "Floresta.hpp"
#include "config.hpp"

class Simulador{
    public:
    Simulador() = default;
    void propFogo(Floresta& floresta);
    bool existeFogo(const Floresta& floresta);
};

#endif