#include "jogo_da_vida.h"

#include <cmath>

#include "iostream"

using std::floor;
using std::vector;

JogoDaVida::JogoDaVida(int l, int c) {
    (*this).vivas_ = vector<vector<bool>>(l, vector<bool>(c, false));
    v = &vivas_;
    width = colunas();
    height = linhas();
}

bool JogoDaVida::viva(int i, int j) {
    // if i ou j não está no intervalo [0,width) ou [0,height), lança a exceção
    if (floor((i / (float)height)) || floor((float)j / width)) {  // se o índice / pelo tamanho do vetor é diferente de zero
        // a divisão inteira dos índices com size do vetor deve sempre retornar 0.
        // retorna um valor diferente de zero configura vazamento de memória. Neste caso uma exceção é lancada
        ExcecaoCelulaInvalida e(i, j);
        throw e;
    }
    return vivas_[i][j];
}


int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
    // if i ou j não está no intervalo [0,width) ou [0,height), lança a exceção
    if (floor(x / (float)height) || floor(y / (float)width)) {  // se o índice / pelo tamanho do vetor é diferente de zero
        ExcecaoCelulaInvalida e(x, y);
        throw e;
    }
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
    // if i ou j não está no intervalo [0,width) ou [0,height), lança a exceção
    if (floor((i / (float)height)) || floor((float)j / width)) {
        ExcecaoCelulaInvalida e(i, j);
        throw e;
    }
    (*this).vivas_[i][j] = false;
}
void JogoDaVida::Reviver(int i, int j) {
    // if i ou j não está no intervalo [0,width) ou [0,height), lança a exceção
    if (floor((i / (float)height)) || floor((float)j / width)) {
        ExcecaoCelulaInvalida e;
        e.coluna = j;
        e.linha = i;
        throw e;
    }
    (*this).vivas_[i][j] = true;
}
