#include "Floresta.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using nasmespace std;

Floresta :: Floresta(int n, int m) : linhas (n), colunas(m), grid(n, vector<int>(m, VAZIO)){
}

void Floresta :: inicializarRandom(){
    srand(time(0));
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            grid[i][j] = rand() % 5;
}

void Forest::exibir() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            std::cout << grid[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int Forest::getEstado(int i, int j) const {
    return grid[i][j];
}

void Forest::setEstado(int i, int j, int estado) {
    grid[i][j] = estado;
}

int Forest::getLinhas() const {
    return linhas;
}

int Forest::getColunas() const {
    return colunas;
}

bool Forest::dentroDosLimites(int i, int j) const {
    return i >= 0 && i < linhas && j >= 0 && j < colunas;
}