#include "Simulador.hpp"
#include "config.hpp"
#include <iostream>

using namespace std;

Simulador :: Simulador() : animal(nullptr), intera(0){
}

Simulador :: ~Simulador(){
    delete animal;
}


void Simulador :: carregarEntrada(const std::string& nomeArquivo) {
    floresta.carregarArquivo(nomeArquivo);

    // Encontra a posição inicial do animal (a primeira célula VAZIO encontrada)
    for (int i = 0; i < floresta.getLinhas(); ++i) {
        for (int j = 0; j < floresta.getColunas(); ++j) {
            if (floresta.getEstado(i, j) == VAZIO) {
                animal = Animal(i, j);
                return;
            }
        }
    }
}




/*void Simulador :: executar (const string& arquivoSaida){
    for (intera = 1; intera <= MAX_INTERACOES && floresta.temArvoresEmChamas(); intera++) {
        
    }
    
}*/