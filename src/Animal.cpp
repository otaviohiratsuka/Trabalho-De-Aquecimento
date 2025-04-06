#include "Animal.hpp"

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

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (floresta.dentroDosLimites(nx, ny)) {
            floresta.setEstado(nx, ny, 1);
        }
    }
}