#include <iostream>
#include <fstream>
#include <sstream>
#include "Floresta.hpp"
#include "config.hpp"

using namespace std;

int main(){
    cout << "=== INICIANDO SIMULACAO ===" << endl;

    Floresta floresta(2, 2);

    if(!floresta.carregaArquivo("SRC/input.dat")){
        return 1;
    }

    ofstream clearOutput("output.dat");
    clearOutput.close();

    bool terminouAntes = floresta.simular(MAX_INTERACOES);
    
    if(terminouAntes){
        cout << "Simulacao concluida: nao ha mais arvores em chamas." << endl;
    }
    else {
        cout << "Simulacao terminou apos" << MAX_INTERACOES << "iteracoes." << endl;;
    }
    return 0;
}