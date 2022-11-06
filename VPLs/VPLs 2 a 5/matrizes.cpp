#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> read(int l, int c) {
    vector<vector<int>> v(l, vector<int>(c));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    return v;
}

void imprime(vector<vector<int>> m) {
    int c = m[0].size();
    int l = m.size();

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j];
            if (j < c - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

vector<vector<int>> produto(vector<vector<int>> a, vector<vector<int>> b) {
    int l = a.size();
    int c = b[0].size();
    vector<vector<int>> m (l, vector<int>(c));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < b.size(); k++) {
                m[i][j] += a[i][k] * b[k][j];
               // cout << m[i][j] << endl;
            }
        }
    }
    return m;
}

int main() {
    int n, mn, m;
    cin >> n >> mn >> m;

    vector<vector<int>> a(n, vector<int>(mn));
    vector<vector<int>> b(mn, vector<int>(m));

    a = read(n, mn);
    b = read(mn, m);

    imprime(produto(a,b));
}