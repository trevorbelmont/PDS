#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

using namespace std;

void FilaDePrioridade::Adicionar(Pessoa p) {
    list<Pessoa>::iterator it = lista.begin();

    if (lista.empty()) {
        lista.push_front(p);
        return;
    } else {
        while (it != lista.end()) {
            if (it->prioridade < p.prioridade) {
                break;
            } else {
                it++;
            }
        }
    }

    lista.insert(it, p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
    string nome = (*lista.begin()).nome;
     lista.pop_front();
    return nome;
}

void FilaDePrioridade::Remover(string nome) {
    for (list<Pessoa>::iterator it = lista.begin(); it != lista.end(); it++) {
        if (it->nome == nome) {
            lista.erase(it);
            break;
        }
    }
}

int FilaDePrioridade::tamanho() {
    int i = 0;
    for (list<Pessoa>::iterator it = lista.begin(); it != lista.end(); it++) {
        i++;
    }
    return i;
}

vector<string> FilaDePrioridade::listar() {
    vector<string> v;
     for (list<Pessoa>::iterator it = lista.begin(); it != lista.end(); it++) {
    //for (Pessoa ppl : lista) {
        v.push_back(it->nome);
    }
    return v;
}