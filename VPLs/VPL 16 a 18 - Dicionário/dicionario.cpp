#include "dicionario.h"

#include <list>

using std::list;

Dicionario::Dicionario() {
    (*this).elementos_ = list<Elemento>();
}

int Dicionario::tamanho() {
    return (*this).elementos_.size();
}

bool Dicionario::pertence(string chave) {
    list<Elemento>::iterator it = elementos_.begin();

    for (it = elementos_.begin(); it != elementos_.end(); it++) {
        if ((*it).chave == chave) {
            return true;
        }
    }
    return false;
}

string Dicionario::menor() {
    if ((*this).tamanho() == 0) {
        Exception_Empty e;
        throw e;
    }
    string menor = elementos_.front().chave;

    for (list<Elemento>::iterator it = elementos_.begin(); it != elementos_.end(); it++) {
        if ((*it).chave < menor) {
            menor = (*it).chave;
        }
    }
    return menor;
}

string Dicionario::valor(string key) {
    bool touched = false;
    string s;
    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it->chave == key) {
            s = it->valor;
            touched = true;
        }
    }
    if (!touched) {
        Exception_NotFound e{key};
        throw e;
    }
    return s;
}
void Dicionario::Inserir(string chave, string valor) {
    if((*this).pertence(chave)){
        Exception_Repeated e;
        e.chave = chave;
        throw e;
    }
    elementos_.push_back(Elemento{chave, valor});
}

void Dicionario::Remover(string chave) {
    bool touched;

    for (list<Elemento>::iterator i = elementos_.begin(); i != elementos_.end(); i++) {
        if (i->chave == chave) {
            elementos_.erase(i);
            touched = false;
            return;
        }
    }
    if (!touched) {
        Exception_NotFound e{chave};
        throw e;
    }
}

void Dicionario::Alterar(string chave, string valor) {
    bool touched = false;

    for (list<Elemento>::iterator i = elementos_.begin(); i != elementos_.end(); i++) {
        if (i->chave == chave) {
            (*i).valor = valor;
            touched = false;
            return;
        }
    }
    if (!touched) {
        Exception_NotFound e{chave};
        throw e;
    }
}

Dicionario::~Dicionario() {
    elementos_.clear();
}
