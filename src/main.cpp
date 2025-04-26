#include <iostream>
#include <fstream>
#include <sstream>
#include "Floresta.hpp"
#include "Animal.hpp"
#include "config.hpp"

using namespace std;

int main(){
    cout << "=== INICIANDO SIMULACAO ===" << endl;

    Floresta floresta(1, 1);

    if(!floresta.carregaArquivo("input.dat")){
        return 1;
    }

    ofstream clearOutput("output.dat");
    clearOutput.close();

    bool terminouAntes = floresta.simular(MAX_INTERACOES);
    
    if(terminouAntes){
        cout << "Simulacao concluida: nao ha mais arvores em chamas." << endl;
    }
    else {
        cout << "Total de iteracoes: " << floresta.getContIteracao() +1 << endl;
    }
    return 0;
}