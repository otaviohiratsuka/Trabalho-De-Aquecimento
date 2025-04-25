#include "Animal.hpp"
#include <algorithm>
#include <iostream>

Animal :: Animal (int x, int y) : posicao(make_pair(x, y)), passos(0), encontrouAgua(0), vivo(true), tempoRepouso(0){
}

PrioridadeMovimento Animal :: avaliarPrioridade(int tipoCelula) const{
    switch (tipoCelula){
    case AGUA:
        return MELHOR;

    case VAZIO:
        return INTERMEDIARIA;

    case ARVORE_SAUDAVEL:
        return INTERMEDIARIA;
    
    case ARVORE_QUEIMADA:
        return PIOR;

    default:
        return PIOR; //incluindo fogo como opção
    }
}

pair<int, int> Animal :: getPosicao() const{
    return posicao;
}

void Animal :: morrer(){
    vivo = false;
}

int Animal :: getPassos() const{
    return passos;
}

bool Animal :: estaVivo() const{
    return vivo;
}

int Animal :: getTempoRepouso() const{
    return tempoRepouso;
}

int Animal :: getEncontrouAgua() const{
    return encontrouAgua;
}

bool Animal::mover(vector<vector<int>> & matriz) {
    if (!vivo) return false;

    int x = posicao.first;
    int y = posicao.second;

    if (matriz[x][y] == ARVORE_EM_CHAMAS) {
        morrer();
        return false;
    }

    // Verifica se há fogo nas redondezas
    const vector<pair<int, int>> direcoes = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    bool fogoAdjacente = false;

    for (const auto& dir : direcoes) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 0 && nx < (int)matriz.size() && ny >= 0 && ny < (int)matriz[0].size()) {
            if (matriz[nx][ny] == ARVORE_EM_CHAMAS) {
                fogoAdjacente = true;
                break;
            }
        }
    }

    // Só repousa se não houver fogo próximo
    if ((matriz[x][y] == VAZIO || matriz[x][y] == SEGURO) && !fogoAdjacente &&
        tempoRepouso < MAX_REPOUSO) {

        tempoRepouso++;
        return true;
    }

    // Se fogo estiver por perto, cancela o repouso e exibe alerta
    if (fogoAdjacente) {
        std::cout << "Animal em perigo! Fogo adjacente detectado!.\n";
    }
    tempoRepouso = 0;

    // Gera opções de movimento
    vector<pair<int, pair<int, int>>> opcoes;
    for (const auto& dir : direcoes) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 0 && nx < (int)matriz.size() && ny >= 0 && ny < (int)matriz[0].size()) {
            int celula = matriz[nx][ny];
            if (celula != ARVORE_EM_CHAMAS) {
                opcoes.push_back(make_pair(avaliarPrioridade(celula), make_pair(nx, ny)));
            }
        }
    }

    // Move para melhor opção
    if (!opcoes.empty()) {
        sort(opcoes.begin(), opcoes.end());
        posicao = opcoes[0].second;
        passos++;

        if (matriz[posicao.first][posicao.second] == AGUA) {
            encontrarAgua(matriz);
        }
        return true;
    }

    if (matriz[x][y] == ARVORE_EM_CHAMAS) {
        morrer();
    }

    return false;
}


void Animal :: encontrarAgua(vector<vector<int>> & matriz){
    int x = posicao.first;
    int y = posicao.second;

    if(matriz[x][y] !=  AGUA) return;

    matriz[x][y] = SEGURO ;
    encontrouAgua++;

    const vector<pair<int, int>> direcoes = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    for (const auto& dir : direcoes){
        int nx = x + dir.first;
        int ny = y + dir.second;

        if(nx >= 0 && nx < (int)matriz.size() && ny >= 0 && ny < (int)matriz[0].size()){
            if(matriz[nx][ny] == ARVORE_EM_CHAMAS || matriz[nx][ny] == ARVORE_QUEIMADA || matriz[nx][ny] == VAZIO){
                matriz[nx][ny] = ARVORE_SAUDAVEL;
            }
        }
    }
}