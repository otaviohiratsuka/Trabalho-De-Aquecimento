#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <random>
#include <utility>
#include "config.hpp"

using namespace std;

class Floresta {
    private:
    int linhas, colunas;
    vector<vector<int>> grid;

    public: //Construtores
    Floresta();

    void carregarArquivo(const string& nomeArquivo);
    void salvarEstado(const string& nomeArquivo, int itera) const;

    int getEstado(int i, int j) const;
    void setEstado(int i, int j, int estado);

    int getLinhas() const;
    int getColunas() const;

    void propagaFogo();
    bool temArvoresEmChamas() const;
    bool posValida(int i, int j) const;
    void attCelulasAdjacentesComAgua(int i, int j); //Requisito da movimentação do animal
    

    
};
#endif 