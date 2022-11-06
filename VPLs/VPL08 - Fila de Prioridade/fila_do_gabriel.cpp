#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;



void FilaDePrioridade::AdicionarDOMARCOS(Pessoa p) {
    if (lista.empty()) {
        lista.push_front(p);
    } else {
        for (auto it = lista.begin(); it != lista.end(); it++) {
            if (it->prioridade < p.prioridade) {
                lista.insert(it, p);
                return;
            }
        }
    }
}

void FilaDePrioridade::Adicionar(Pessoa p) {
  list<Pessoa>::iterator it = lista_.begin();

  while(it != lista_.end()){
    if(it->prioridade < p.prioridade){
      break;
    }else{
      it++;
    }
  }

  lista_.insert(it, p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  list<Pessoa>::iterator inicio = lista_.begin();
  string nome = inicio->nome;
  lista_.erase(inicio);
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  list<Pessoa>::iterator it = lista_.begin();
  
  while(it != lista_.end()){
    if(it->nome == nome){
      lista_.erase(it);
      break;
    }else{
      it++;
    }
  }
}

int FilaDePrioridade::tamanho() {
  return lista.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;

  for(Pessoa p : lista_){
    v.push_back(p.nome);
  }

  return v; 
}

