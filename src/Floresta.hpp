#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <random>
#include <utility>
#include "config.hpp"

//using nasmespace std;

class Floresta {
    private:
    int linhas, colunas;
    std :: vector<std :: vector<int>> grid;

    public: //Construtores
    Floresta();
    Floresta(int n, int m);

    int getEstado(int i, int j) const;
    void getEstado(int i, int j, int estado);

    bool posValida(int i, int j) const;
    std::vector<std::pair<int, int>> vizinhosOrtogonais(int i, int j) const;

    bool temArvoresEmChamas() const;

    void exibir() const;    
    void setEstado(int i, int j, int estado);
    int getLinhas() const {return linhas;};
    int getColunas() const {return colunas;};

    std::vector<std::vector<int>>& getGrid();

    void attCelulasAdjacentesComAgua(int i, int j); //Requisito da movimentação do animal
    void carregarArquivo(const std::string& nomeArquivo);

    
};
#endif 