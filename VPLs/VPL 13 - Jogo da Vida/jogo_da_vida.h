#pragma once

#include <vector>

struct ExcecaoCelulaInvalida {
    int linha;
    int coluna;

    ExcecaoCelulaInvalida(int l, int c) {
        linha = l;
        coluna = c;
    }
    ExcecaoCelulaInvalida(){
        linha = -1;
        linha = -1;
    }
};

// Implementa o Jogo da Vida de John Conway.
// https://pt.wikipedia.org/wiki/Jogo_da_vida
class JogoDaVida {
   public:
    // Cria um jogo cujo torus tem l linhas e c colunas.
    // Todas as células são inicializadas como mortas.
    JogoDaVida(int l, int c);

    // Retorna o número de linhas do torus.
    int linhas() { return vivas_.size(); };

    // Retorna o número de colunas do torus.
    int colunas() { return vivas_[0].size(); };

    // Retorna o estado da célula [i, j].
    // Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
    bool viva(int i, int j);

    // Alteram o estado célula [i, j].
    // Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
    void Matar(int i, int j);
    void Reviver(int i, int j);

    // Executa a próxima iteração do jogo da vida.
    void ExecutarProximaIteracao();

   private:
    // Conta o número de vizinhas vivas da célula [x, y].
    int NumeroDeVizinhasVivas(int x, int y);

    // Armazena o estado das células.
    std::vector<std::vector<bool>> vivas_;
    std::vector<std::vector<bool>> *v;  // um ponteiro para "vivas_" mais prático de escrever

    int height;  // altura, i, da matriz...    vivas_.size();s]
    int width;   // largura, j, da matriz...   vivas[x].size();
};
