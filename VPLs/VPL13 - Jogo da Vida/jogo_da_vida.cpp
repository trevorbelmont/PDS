#include "jogo_da_vida.h"

#include "iostream"

using namespace std;

JogoDaVida::JogoDaVida(int l, int c) {
    (*this).vivas_ = vector<vector<bool>>(l, vector<bool>(c, false));
    v = &vivas_;
    width = colunas();
    height = linhas();
}

bool JogoDaVida::viva(int i, int j) {
    return vivas_[i][j];
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
    int n = 0;
    for (int i = 0; i < 9; i++) {
        if (i == 4) continue;
        int vx = x + ((i / 3) - 1);
        int vy = y + ((i % 3) - 1);

        vx = (vx >= 0) ? vx % height : height + (vx % height);
        vy = (vy >= 0) ? vy % width : width + (vy % width);

        if ((*v)[vx][vy]) {
            n++;
        }
    }
    return n;
}

void JogoDaVida::ExecutarProximaIteracao() {
    vector<vector<bool>> n(height, vector<bool>(width, false));  // vetor n é o vetor da "next" interation
    n = *v;                                                      // n  inicialmente é uma cópia de v, para conservar o estado inicial de v
    // as modificações serão feitas apenas em n até o próximo estado estar pronto, quando v receberá n.

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int adjacentes = NumeroDeVizinhasVivas(i, j);
            if ((*v)[i][j] == true) {
                n[i][j] = (adjacentes > 1 && adjacentes <= 3);
            } else {
                n[i][j] = adjacentes == 3;
            }
        }
    }
    *v = n;
}

void JogoDaVida::Matar(int i, int j) {
    (*this).vivas_[i][j] = false;
}
void JogoDaVida::Reviver(int i, int j) {
    (*this).vivas_[i][j] = true;
}
