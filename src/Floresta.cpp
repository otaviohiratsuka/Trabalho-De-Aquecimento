#include "Floresta.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>

using namespace std;

Floresta :: Floresta() : linhas(0), colunas(0){
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

void Floresta :: salvarEstado(const string& nomeArquivo, int itera) const{
    ofstream arquivo(nomeArquivo, ios :: app);
    if(!arquivo.is_open()){
        cerr << "Erro ao salvar no arquivo: " << nomeArquivo << "\n";
        return;
    }

    arquivo << "Iteração" << itera << "\n";
    for (const auto& linha : grid){
        for (int celula : linha)
            arquivo << celula << " ";
        arquivo << "\n";
    }
    arquivo << "\n";
    arquivo.close();
}

void Floresta :: setEstado(int i, int j, int estado){
    if(posValida(i, j))
    grid[i][j] = estado;
}

int Floresta :: getLinhas() const{
    return linhas;
}

int Floresta :: getColunas() const{
    return colunas;
}

bool Floresta :: posValida(int i, int j) const{
    return i >= 0 && i < linhas && j >= 0 && j < colunas;
}

bool Floresta :: temArvoresEmChamas() const{
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            if (grid[i][j] == ARVORE_EM_CHAMAS)
                return true;
    return false;
}

void Floresta :: propagaFogo(){
    vector<vector<int>> novaMatriz = grid;

    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (grid[i][j] == ARVORE_SAUDAVEL){

              ///verifica vizinhos em chamas
            vector<pair<int, int>> direcoes = {
                {-1,0},{1,0},{0,-1},{0,1}
};

                for(const auto& par : direcoes){
                    int di = par.first;
                    int dj = par.second;

                    int ni = i + di;
                    int nj = j + dj;
                    if (posValida(ni, nj) && grid[ni][nj] == ARVORE_EM_CHAMAS){
                        novaMatriz[i][j] = ARVORE_EM_CHAMAS;
                        break;
                    }                   
                } 
            }

            else if(grid[i][j] == ARVORE_EM_CHAMAS){
                novaMatriz[i][j] = ARVORE_QUEIMADA;
            }
            
        }
        
    }

    grid = novaMatriz;
}

int Floresta :: getEstado(int i, int j) const{
    return grid[i][j];
}

void Floresta :: setEstado(int i, int j, int estado){
    if (posValida(i, j)){
        grid[i][j] = estado;
    }
}

//molha as celulas vizinhas com agua(quando animal chega na agua)
void Floresta::attCelulasAdjacentesComAgua(int i, int j){
    vector<pair<int,int>> direcoes;

    direcoes.push_back(make_pair(-1,0)); //cima
    direcoes.push_back(make_pair(1,0)); //baixo
    direcoes.push_back(make_pair(0,-1)); //esquerda
    direcoes.push_back(make_pair(0,1)); //direita

    for(const pair<int,int>& direcao : direcoes){
        int ni = i + direcao.first;
        int nj = j + direcao.second;

        if (posValida(ni, nj) && grid[ni][nj] == ARVORE_SAUDAVEL){
            grid[ni][nj] = VAZIO;
        }     
    }
}

