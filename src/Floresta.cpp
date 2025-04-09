#include "Floresta.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Floresta :: Floresta(int n, int m) : linhas (n), colunas(m){
    grid.resize(n, vector<int>(m, VAZIO));
}

int Floresta :: getEstado(int i, int j) const{
    return grid[i][j];
}

void Floresta :: setEstado(int i, int j, int estado){
    if (posValida(i, j)){
        grid[i][j] = estado;
    }
}

bool Floresta :: posValida(int i, int j) const{
    return i >= 0 && i < linhas && j >= 0 && j < colunas; 
}

vector<pair<int, int>> Floresta :: vizinhosOrtogonais (int i, int j) const{
    vector<pair<int, int>> vizinhos;

    if(posValida(i-1, j)) vizinhos.push_back({i-1, j});
    if(posValida(i+1, j)) vizinhos.push_back({i+1, j});
    if(posValida(i, j-1)) vizinhos.push_back({i, j-1});
    if(posValida(i, j+1)) vizinhos.push_back({i, j+1});

    return vizinhos;
}

bool Floresta :: temArvoresEmChamas() const{
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            if (grid[i][j] == ARVORE_EM_CHAMAS)
                return true;
    return false;
}

void Floresta :: exibir() const{
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>>& Floresta :: getGrid() {
    return grid;
}

//molha as celulas vizinhas com agua(quando animal chega na agua)
void Floresta::attCelulasAdjacentesComAgua(int i, int j){
    auto vizinhos = vizinhosOrtogonais(i, j);

    for(const auto& par : vizinhos){
        int vi = par.first;
        int vj = par.second;

        if (grid[vi][vj] == ARVORE_SAUDAVEL){
            grid[vi][vj] = VAZIO;
        }
    }
}

void Floresta :: carregarArquivo(const string& nomeArquivo){
    ifstream arquivo(nomeArquivo);

    if(!arquivo.is_open()){
        cerr << "erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            int valor;
            arquivo >> valor;
            if (posValida(i, j)){
                grid[i][j] = valor;
            }
        }
    }
    arquivo.close();
}