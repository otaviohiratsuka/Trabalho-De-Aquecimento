#include "Animal.hpp"
#include "Floresta.hpp"
#include <utility>
#include <vector>

Animal :: Animal(){
}

Animal :: Animal(int startX, int startY) : x(startX), y(startY), passos(0), ciclosPreso(0), findAgua(0), vivo(true){
}

bool Animal :: estaVivo() const{
    return vivo && ciclosPreso < 3;
}

int Animal :: getX() const { return x; }
int Animal :: getY() const { return y; }
int Animal :: getPassos() const { return passos; }
int Animal :: getFoundAgua() const { return findAgua; }

void Animal :: chegouAgua (Floresta& floresta){
    findAgua++;
    floresta.setEstado(x, y, 0);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (floresta.posValida(nx, ny)) {  //posValida, seria dentroDosLimites, mas não era declarado em nenhuma classe 
            floresta.setEstado(nx, ny, 1);
        }
    }
}

void Animal ::mover(Floresta& floresta){
    int melhorX = x, melhorY= y, melhorValor = floresta.getEstado(x,y);
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; d++){
        int nx =  x + dx[d], ny = y + dy[d];
        if (floresta.posValida(nx,ny)){
            int estado = floresta.getEstado(nx,ny);
            if (estado == 4){
                melhorX = nx; melhorY = ny; melhorValor = 4;
                break;
            }
            else if ((estado == 0 || estado == 1) && melhorValor != 4){
                melhorX = nx; melhorY = ny; melhorValor = estado;
            }  
        }
    }   
    if (melhorX != x || melhorY != y){
        x = melhorX; y = melhorY;
        ciclosPreso = 0;
        passos++;

        if (melhorValor == 4){
            chegouAgua(floresta);
        }
    }
    else{
        ciclosPreso++;
    }
}

void Animal :: checkQueimou(Floresta& floresta){
    if(floresta.getEstado(x,y) == 2 ){
        vivo = false; // animal morto
    }
}
