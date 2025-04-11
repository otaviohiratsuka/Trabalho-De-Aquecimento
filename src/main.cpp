#include <iostream>
#include "Simulador.hpp"


using namespace std;
int main(){
    Simulador sim;

    sim.carregarEntrada("input.dat");

    sim.carregarEntrada("output.dat");

    cout << "Simulação finalizada. Resultado salvos em output.dat" << endl;
    
}
