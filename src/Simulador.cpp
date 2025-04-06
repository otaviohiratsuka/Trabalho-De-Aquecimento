#include "Simulador.hpp"

using namespace std;

void Simulador :: propFogo(Floresta& floresta){
    int n =  floresta.getLinhas();
    int m = floresta.getColunas();

    vector<vector<int>> nvEstado = floresta;

    for (int i = 0, i < n; i++){
        for (int j = 0; j < m; j++){
            if(floresta.getEstado(i, j) == ARVORE_EM_CHAMAS){
                nvEstado[i][j] = ARVORE_QUEIMADA;

                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};

                for (int d = 0; d < 4; ++d){
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (floresta.dentroDosLimites(ni, nj) && floresta,getEstado(ni, nj) == ARVORE_SAUDAVEL) nvEstado[ni][nj] = ARVORE_EM_CHAMAS;
                }
            }
        }
    }

    //atualiza estado floresta
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; ++j)
            floresta.setEstado(i, j, novoEstado[i][j]);
}

bool Simulador :: existeFogo(const Floresta& floresta){
    for (int i = 0; i < floresta.getLinhas(); ++i)
        for (int j = 0; j < floresta.getColunas(); ++j)
            if (floresta.getEstado(i, j) == ARVORE_EM_CHAMAS)
                return true;
    return false;
}