#include <iostream>

using namespace std;

// 1 a 3
int main() {
    int a = 10;
    int* ptr = nullptr;
    int b[10];

    for (int i = 0; i < 10; i++) {
        b[i] = 9 - i;
    }
    // 4 e 5
    cout << &a << endl;
    cout << a << endl;
    // 6 e 7
    cout << &ptr << endl;
    cout << ptr << endl;
    // 8 a 10
    cout << &b << endl;
    cout << &b[0] << endl;
    cout << b[0] << endl;
    // 11 a 14
    ptr = &a;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << (&a == ptr) << endl;
    // 15 a 20
    *ptr = 5;
    cout << a << endl;
    ptr = b;
    cout << ptr << endl;
    cout << *ptr << endl;
    // 20 a 22
    ptr = &b[0];
    cout << ptr << endl;
    cout << *ptr << endl;
    // 23 e 24
    for (int i = 0; i < 10; i++) {
        cout << b[i];
        if (i < 10 - 1) cout << ' ';
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << *(b + i);
        if (i < 10 - 1) cout << ' ';
    }
    cout << endl;
}
