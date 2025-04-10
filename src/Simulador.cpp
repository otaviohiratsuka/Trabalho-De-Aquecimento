#include "Simulador.hpp"
#include "config.hpp"
#include <iostream>

using namespace std;

Simulador :: Simulador() : animal(nullptr), intera(0){
}

Simulador :: ~Simulador(){
    delete animal;
}

void Simulador :: executar (const string& arquivoSaida){
    for (intera = 1; intera <= MAX_INTERACOES && floresta.temArvoresEmChamas(); intera++) {
        /* code */
    }
    
}