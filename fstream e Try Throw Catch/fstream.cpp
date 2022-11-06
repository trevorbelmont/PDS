#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/* try tenta fazer algo e testa se houve alguma exceção (num if por exemplo)
havendo uma exceção o throw retorna uma variável (string, float, TAD ou etc)
o throw direciona o fluxo de código para o devito catch que tem o msm tipo de
variável retornado pelo throw. OU SEJA: o throw retornando float leva pro catch que recebe float,
o throw que retorna string leva pro catch que recebe string e etc. */

using namespace std;

vector<float> read(string name, vector<float> v) {
    ifstream fin(name);
    if (!fin.is_open()) {
        throw name;  // retorna uma variável caso há erro e lança ela pro catch (mesmo fora da função)
    }
    int size;
    fin >> size;
    v.resize(size);
    for(int i = 0; i <v.size(); i++){
        fin >> v[i];
    }
    return v;

}
void write(string name) {
    ofstream fout(name); //cria e abre arquivo
   // fout.open("arquivoTal.txt"); // abre um certo arquivo caso seja necessário
    fout << 1 << endl;
    fout << 2 << endl;
    fout.close();
}

int main() {
    string nome;
    vector<float> w;
    cin >> nome;

    try {
        w = read(nome, w);  // o throw está dentro desta função.
    } catch (string exception) {
        write(exception);
        w = read(nome, w);
    }

    cout << w.size();    //[w.size()-1];
    ofstream fout;
    fout.open(nome,ofstream::app); //abre arquivo na opção append não sobrescreve e adiciona no final
    fout << "add this";

    fout.close();
}
