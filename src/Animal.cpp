#include "Animal.hpp"
#include <algorithm>

Animal :: Animal (int x, int y) : posicao(make_pair(x, y)), passos(0), encontrouAgua(0), vivo(true){
}

PrioridadeMovimento Animal :: avaliarPrioridade(int tipoCelula) const{
    switch (tipoCelula){
    case AGUA:
        return MELHOR;

    case VAZIO:

    case ARVORE_SAUDAVEL:
        return INTERMEDIARIA;
    
    case ARVORE_QUEIMADA:
        return PIOR;

    default:
        return PIOR; //incluindo fogo como opção
    }
}

bool Animal :: mover(const vector<vector<int>> & matriz) {
    if(!vivo) return false;

    int x = posicao.first;
    int y = posicao.second;

    vector<pair<PrioridadeMovimento, pair<int, int>>> opcoes;
    const pair<int, int> direcoes[] = {make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};

    for (size_t i = 0; i < 4; i++){
        int dx = direcoes[i].first;
        int dy = direcoes[i].second;
        int nx = x + dx;
        int ny = y + dy;

        if(nx >= 0 && nx < (int)matriz.size() && ny >= 0 && ny < (int)matriz[0].size()){
            int celula = matriz[nx][ny];
            if(celula != ARVORE_EM_CHAMAS){
                opcoes.push_back(make_pair(avaliarPrioridade(celula), make_pair(nx, ny)));
            }
        }
    }
    
    //Função de comparação para ordenar
    struct{
        bool operator()(const pair<PrioridadeMovimento, pair<int, int>> & a, const pair<PrioridadeMovimento, pair<int, int>> & b) const {
            return a.first < b.first;
        }
    }
    comparador;

    sort(opcoes.begin(), opcoes.end(), comparador);

    if (!opcoes.empty()){
        int novoX = opcoes[0].second.first;
        int novoY = opcoes[0].second.second;
        posicao.first = novoX;
        posicao.second = novoY;
        passos++;

        if (opcoes[0].first == MELHOR){
            encontrouAgua++;
            return true;
        }
        return true;
    }

    if (matriz[x][y] == ARVORE_EM_CHAMAS){
        vivo = false;
    }
    return false;
}

void Animal :: encontrarAgua(vector<vector<int>> & matriz){
    int x = posicao.first;
    int y = posicao.second;
    matriz[x][y] = VAZIO;

    const pair<int, int> direcoes[] = {make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};

    for (size_t i = 0; i < 4; i++){
        int dx = direcoes[i].first;
        int dy = direcoes[i].second;
        int nx = x + dx;
        int ny = y + dy;

        if(nx >= 0 && nx < (int)matriz.size() && ny >= 0 && ny < (int)matriz[0].size()){
            if(matriz[nx][ny] == ARVORE_EM_CHAMAS){
                matriz[nx][ny] = ARVORE_SAUDAVEL;
            }
        }
    }
}
