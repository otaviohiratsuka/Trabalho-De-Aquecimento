#include "Floresta.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Floresta :: Floresta(int animalX, int animalY) : animal(animalX, animalY){
    matriz.resize(TAM_LINHAS, vector<int>(TAM_COLUNAS, VAZIO));
    tempoFogo.resize(TAM_LINHAS, vector<int>(TAM_COLUNAS, 0));
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
    if (!output.is_open()) return;
    
    output << "=== Iteracao: " << iteracao << "===\n";
    auto pos =  animal.getPosicao();

    for(int i = 0; i < TAM_LINHAS; i++){
        for(int j = 0; j < TAM_COLUNAS; j++){
            if(i == pos.first && j == pos.second && animal.estaVivo()){
                output << "5 " ;
            }
            else{
                output << matriz [i][j] << " ";
            }
        }
        output << "\n" ;        
    }
        output << "\n[Estatisticas]\n";
        output << "passos:  " << animal.getPassos() << "\n";
        output << " | agua: " << animal.getEncontrouAgua() << "\n";
        output << " | repouso: " << animal.getTempoRepouso() << "/" << MAX_REPOUSO << "\n";
        output << "\n\n";
    }

bool Floresta :: temFogo() const {
    for(const auto& linha : matriz){
        if(find (linha.begin(), linha.end(), ARVORE_EM_CHAMAS) != linha.end()){
            return true;
        }
    }
    return false;
}

void Floresta :: propagaFogo(){
    auto novaMatriz = matriz;

    for (int i = 0; i < TAM_LINHAS; i++){
        for (int j = 0; j < TAM_COLUNAS; j++){
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
                if(i < TAM_LINHAS-1 && matriz[i+1][j] == ARVORE_SAUDAVEL){
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
        cout << "\n=== ITERACAO " << iter << " ===" << endl;

        mostrarEstadoTerminal();

        if(animal.estaVivo() && !animal.mover(matriz)){
        cerr << "\nANIMAL CAPTURADO PELO FOGO \n";
        return false;
        }
        
        propagaFogo();
        salvaArquivo("output.dat", iter);
        

        if (!temFogo()) {
            cout << "\nFOGO EXTINTO \n";
            mostrarEstadoTerminal();
            return true;
        }
    }
    return false; 
}

const Animal& Floresta :: getAnimal() const{
    return animal;
}

void Floresta :: mostrarEstadoTerminal() const{
    auto posAnimal = animal.getPosicao();

    cout << "\n=== ESTADO DA FLORESTA ===\n"; 
    for(int i = 0; i < TAM_LINHAS; i++){
        for (int j = 0; j < TAM_COLUNAS; j++){
            if(i == posAnimal.first && j == posAnimal.second && animal.estaVivo()){
                cout << "5 " ;
            }
            else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "\n[ESTATISTICAS]\n";
    cout << "Posicao do animal: (" << posAnimal.first << "," << posAnimal.second << ")\n";
    cout << "Passos dados: " << animal.getPassos() << "\n";
    cout << "Fontes de agua encontradas: " << animal.getEncontrouAgua() << "\n";
    cout << "Tempo de repouso: " << animal.getTempoRepouso() << "/" << MAX_REPOUSO << "\n";
    cout << "Status: " << (animal.estaVivo() ? "1 (VIVO)" : "0 (MORTO)") << "\n\n";

}