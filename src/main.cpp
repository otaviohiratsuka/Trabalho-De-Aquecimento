#include <iostream>
#include <fstream>
#include "Floresta.hpp"
#include "config.hpp"

using namespace std;

/*void mostrarArquivoNoTerminal(const string& nomeArquivo){
    ifstream arquivo(nomeArquivo);
    if(arquivo.is_open()){
        string linha;
        cout << "\n Conteudo de " << nomeArquivo << " ===\n";
        while (getline(arquivo, linha)){
            cout << linha << endl;
        }
        cout << "======================\n";
    }
    else {
        cerr << "Erro ao abrir " << nomeArquivo << " para leitura. \n";
    }
}*/

int main(){
    Floresta floresta(2, 2);

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
        cout << "Simulacao terminou apos" << MAX_INTERACOES << "iteracoes." << endl;;
    }
    return 0;
}