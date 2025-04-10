#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "Floresta.hpp"
#include "Animal.hpp"
#include "config.hpp"
#include <string>

using namespace std;

class Simulador{
    private:
    Floresta floresta;
    Animal* animal;
    int intera;

    public:
    Simulador();
    ~Simulador();
    void carregarEntrada(const string& arquivo);
    void executar(const string& arquivoSaida);
};

#endif