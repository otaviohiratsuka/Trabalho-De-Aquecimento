#include "Floresta.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//using nasmespace std;

Floresta :: Floresta(int n, int m) : linhas (n), colunas(m), grid(n, std::vector<int>(m, VAZIO)){
}

void Floresta :: inicializarRandom(){
    srand(time(0));
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            grid[i][j] = rand() % 5;
}

void Floresta :: exibir() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            std::cout << grid[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int Floresta :: getEstado(int i, int j) const {
    return grid[i][j];
}

void Floresta :: setEstado(int i, int j, int estado) {
    grid[i][j] = estado;
}

int Floresta :: getLinhas() const {
    return linhas;
}

int Floresta :: getColunas() const {
    return colunas;
}

bool Floresta :: dentroDosLimites(int i, int j) const {
    return i >= 0 && i < linhas && j >= 0 && j < colunas;
}