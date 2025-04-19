#include "Floresta.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Floresta :: Floresta(){
    matriz.resize(TAM_COLUNAS, vector<int>(TAM_LINHAS, VAZIO));
    tempoFogo.resize(TAM_COLUNAS, vector<int>(TAM_LINHAS, 0));
}

bool Floresta :: carregaArquivo(const string& arquivo){
    ifstream input(arquivo);
    if(!input.is_open()){
        cerr <<"Erro ao abrir o arquivo." << endl;
        return false;
    }
    
    for (int i = 0; i < TAM_COLUNAS; i++){
        for (int j = 0; j < TAM_LINHAS; j++){
            if(!(input >> matriz[i][j])){
                cerr << "Erro ao ler dados do arquivo." << endl;
                return false;
            }
        }
    }
    return true;
}

void Floresta :: salvaArquivo(const string& arquivo, int iteracao) const {
    ofstream output(arquivo, ios::app);
    if (!output.is_open()){
        cerr << "Erro ao abrir o arquivo de saida." << endl;
        return;
    }
    
    output << "Iteracao: " << iteracao << endl;
    for(const auto& linha : matriz){
        for(int celula : linha){
            output << celula << " ";
        }
        output << endl;
    }
    output << endl;
}

bool Floresta :: temFogo() const {
    for(const auto& linha : matriz){
        for(int celula : linha){
            if (celula == ARVORE_EM_CHAMAS) return true;
        }
    }
    return false;
}

void Floresta :: propagaFogo(){
    auto novaMatriz = matriz;

    for (int i = 0; i < TAM_COLUNAS; i++){
        for (int j = 0; j < TAM_LINHAS; j++){
            if (matriz[i][j] == ARVORE_EM_CHAMAS){
                tempoFogo[i][j]++;

                if (tempoFogo[i][j] >= DURACAO_FOGO){
                    novaMatriz[i][j] = ARVORE_QUEIMADA;
                    tempoFogo[i][j] = 0;
                }

                //1. acima
                if(i > 0 && matriz[i-1][j] == ARVORE_SAUDAVEL){
                    novaMatriz[i-1][j] = ARVORE_EM_CHAMAS;
                    tempoFogo[i-1][j] = 1;
                }
                //2. abaixo
                if(i < TAM_COLUNAS-1 && matriz[i+1][j] == ARVORE_SAUDAVEL){
                    novaMatriz[i+1][j] = ARVORE_EM_CHAMAS;
                    tempoFogo[i+1][j] = 1;
                }
                //3. esquerda
                if(j > 0 && matriz[i][j-1] == ARVORE_SAUDAVEL){
                    novaMatriz[i][j-1] = ARVORE_EM_CHAMAS;
                    tempoFogo[i][j-1] = 1;
                }
                //4. direta
                if(j < TAM_COLUNAS-1 && matriz[i][j+1] == ARVORE_SAUDAVEL){
                    novaMatriz[i][j+1] = ARVORE_EM_CHAMAS;
                    tempoFogo[i][j+1] = 1;
                }
            }  
        }    
    }
    matriz = novaMatriz;
}

bool Floresta :: simular(int maxIteracoes){
    for (int iter = 0; iter < maxIteracoes; ++iter){
        salvaArquivo("output.dat", iter);
        propagaFogo();

        if (!temFogo()) {
            salvaArquivo("output.dat", iter+1);
            return true;
        }
    }
    return false; 
}

/*void mostrarEstadoTerminal(int iteracao) const{
    cout << "\n--- Iteração " << iteracao << " ---\n";
    for (const auto& linha : matriz) {
        for (int celula : linha) {
            std::cout << celula << " ";
        }
        std::cout << std::endl;
    }
}*/