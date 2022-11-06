#include "vetor.h"

#include <string>

Vetor::Vetor(int i, int f) {
    if (f - i < 0) {
        IntervaloVazio e;
        e.fim = f;
        e.inicio = i;
        throw(e);
    }
    elementos_ = new string[(f - i) + 1];
    inicializado = new bool[(f - i) + 1];
    inicio_ = i;
    fim_ = f;
}

void Vetor::atribuir(int i, string s) {
    if (i > fim_ || i < inicio_) {
        IndiceInvalido e;
        e.inicio = inicio_;
        e.fim = fim_;
        e.indice = i;
        throw(e);
    }
    elementos_[i - inicio_] = s;
    inicializado[i - inicio_] = true;
}

string Vetor::valor(int i) const {
    if (i > fim_ || i < inicio_) {
        IndiceInvalido e;
        e.inicio = inicio_;
        e.fim = fim_;
        e.indice = i;
        throw(e);
    }
    if (!inicializado[i - inicio_]) {
        IndiceNaoInicializado e;
        e.indice = i;
        throw(e);
    }

    return *(elementos_ + i - inicio_);
    // elementos_[i - inicio_];
}

Vetor::~Vetor() {
    delete[] elementos_;
}