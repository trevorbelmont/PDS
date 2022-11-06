#include "vetor.h"

#include <string>

Vetor::Vetor(int i, int f) {
    elementos_ = new string[(f - i) + 1];
    inicio_ = i;
}

void Vetor::atribuir(int i, string s) {
    elementos_[i - inicio_] = s;
}

string Vetor::valor(int i) const {
    return *(elementos_  + i-inicio_);
    //elementos_[i - inicio_];
}

Vetor::~Vetor() {
    delete[] elementos_;
}