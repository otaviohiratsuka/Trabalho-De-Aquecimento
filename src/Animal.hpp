#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include "config.hpp"
#include <utility>
#include <vector>

using namespace std;

class Animal{
    
    private:
    pair<int, int> posicao;
    int passos;
    int encontrouAgua;
    bool vivo;
    int tempoRepouso;

    PrioridadeMovimento avaliarPrioridade(int tipoCelula) const;

    public:
    Animal(int x, int y);

    bool mover(vector<vector<int>> & matriz);
    void morrer();

    pair<int, int> getPosicao() const;
    int getPassos() const;
    int getEncontrouAgua() const;
    bool estaVivo() const;
    int getTempoRepouso() const;

    void encontrarAgua(vector<vector<int>> & matriz);
    



};
#endif