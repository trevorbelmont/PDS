#include "fila.h"

#include <string>

using namespace std;

Fila::Fila() {
    primeiro_ = ultimo_ = nullptr;
}

string Fila::primeiro() {
    return (*primeiro_).chave;
}
string Fila::ultimo() {
    return ultimo_->chave;
}

bool Fila::vazia() {
    return (primeiro_ == nullptr && ultimo_ == nullptr);
}

void Fila::Inserir(string k) {
    No* nodo;
    nodo = new No;
    nodo->chave = k;
    nodo->proximo = nullptr;

    if (ultimo_ == nullptr) {
        primeiro_ = nodo;
        ultimo_ = nodo;
    } else {
        ultimo_->proximo = nodo;
        ultimo_ = nodo;
    }
}

int Fila::tamanho() {
    int i = 0;
    for (No* it = primeiro_; it != nullptr; it = it->proximo) {
        i++;
    }
    return i;
}

void Fila::Remover() {
    if (primeiro_ != ultimo_ && primeiro_ != nullptr) {
        No* temp = primeiro_->proximo;
        delete primeiro_;
        primeiro_ = temp;
    }
    else{
        delete primeiro_;
        primeiro_ = ultimo_ = nullptr;
    }
}

Fila::~Fila() {
    for (int i = 0; i < tamanho() - 1; i++) {
        Remover();
    }
    delete primeiro_;
    primeiro_ = ultimo_ = nullptr;
}