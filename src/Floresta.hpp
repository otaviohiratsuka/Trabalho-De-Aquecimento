#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <string>
#include <iostream>
#include "config.hpp"
#include "Animal.hpp"

using namespace std;

class Floresta {
    private:
    vector<vector<int>> matriz;
    Animal animal;
    vector<vector<int>> tempoFogo;
    bool temFogo() const;
    void propagaFogo();
    bool ventoAtivado = false;


    public:
    Floresta(int animalX, int animalY);

    void ativarVento();
    void mostrarEstadoTerminal() const;
    bool carregaArquivo(const string& arquivo);
    void salvaArquivo(const string& arquivo, int interacao) const;
    bool simular(int maxInteracao);

    const Animal& getAnimal() const;
};
#endif 