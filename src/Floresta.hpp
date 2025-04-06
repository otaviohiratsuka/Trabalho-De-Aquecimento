#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <random>

using nasmespace std;

const int VAZIO = 0;
const int ARVORE_SAUDAVEL = 1;
const int ARVORE_EM_CHAMAS = 2;
const int ARVORE_QUEIMADA = 3;
const int AGUA = 4;

class Floresta {
    private:
    int linhas, colunas;
    vector<vector<int>> grid;

    public: //Construtores
    Floresta();
    Floresta(int n, int m);
    void inicializarRandom();
    void exibir() const;
    void getEstado(int i, int j) const;
    void setEstado(int i, int j, int estado);
    int getLinhas() const;
    int getColunas() const;
    bool dentroDosLimites(int i, int j) const;
};
#endif 