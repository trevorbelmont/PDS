#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s.size() << endl;

    int a, e, i, o, u;
    a = e = i = o = u = 0;

    for (int j = 0; j <= s.size(); j++) {
        char c = s[j];
        
        if (c == 'a') {
            a++;
            continue;
        }
        if (c == 'e') {
            e++;
            continue;
        }
        if (c == 'i') {
            i++;
            continue;
        }
        if (c == 'o') {
            o++;
            continue;
        }
        if (c == 'u') {
            u++;
        }
    }

    if (a > 0) {
        cout << "a " << a << endl;
    }
    if (e > 0) {
        cout << "e " << e << endl;
    }
    if (i > 0) {
        cout << "i " << i << endl;
    }
    if (o > 0) {
        cout << "o " << o << endl;
    }
    if (u > 0) {
        cout << "u " << u << endl;
    }

    return 0;
}