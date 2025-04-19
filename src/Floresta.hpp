#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <string>
#include <iostream>
#include "config.hpp"

using namespace std;

class Floresta {
    private:
    vector<vector<int>> matriz;
    vector<vector<int>> tempoFogo;
    bool temFogo() const;

    public:
    Floresta();
    bool carregaArquivo(const string& arquivo);
    void salvaArquivo(const string& arquivo, int interacao) const;
    void propagaFogo();
    bool simular(int maxInteracao);
    void mostrarEstadoTerminal(int iteracao) const;
};
#endif 