#include "racional.h"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void Racional::Normalizar() {
    int mdc;
    mdc = __gcd(numerador_, denominador_);

    numerador_ /= mdc;
    denominador_ /= mdc;

    if (denominador_ < 0) {
        denominador_ = -denominador_;
        numerador_ = -numerador_;
    }
}

Racional::Racional() {
    denominador_ = 1;
    numerador_ = 0;
}

Racional::Racional(int n) {
    denominador_ = 1;
    numerador_ = n;
}

Racional::Racional(int n, int d) {
    denominador_ = d;
    numerador_ = n;
    (*this).Normalizar();
}

int Racional::numerador() const {
    return numerador_;
}

int Racional::denominador() const {
    return denominador_;
}

Racional Racional::simetrico() const {
    return Racional(numerador_ * (-1), denominador_);
}
Racional Racional::operator-() const {
    return (*this).simetrico();
}

Racional Racional::somar(Racional k) const {
    Racional temp;
    temp.denominador_ = (*this).denominador_ * k.denominador_;

    temp.numerador_ = (temp.denominador_ / (*this).denominador_) * (*this).numerador_ +
                      (temp.denominador_ / k.denominador_) * k.numerador_;
    temp.Normalizar();
    return Racional(temp);
}

Racional Racional::operator+(Racional k) const {
    return (*this).somar(k);
}
Racional Racional::subtrair(Racional k) const {
    Racional temp;
    temp.denominador_ = (*this).denominador_ * k.denominador_;

    temp.numerador_ = (temp.denominador_ / (*this).denominador_) * (*this).numerador_ - (temp.denominador_ / k.denominador_) * k.numerador_;

    temp.Normalizar();
    return Racional(temp);
    ;
}
Racional Racional::operator-(Racional k) const {
    return (*this).subtrair(k);
}

Racional Racional::multiplicar(Racional k) const {
    Racional temp(numerador_ * k.numerador_, denominador_ * k.denominador_);
    temp.Normalizar();
    return temp;
}
Racional Racional::operator*(Racional k) const {
    return (*this).multiplicar(k);
}

Racional Racional::dividir(Racional k) const {
    Racional temp(numerador_ * k.denominador_, denominador_ * k.numerador_);
    temp.Normalizar();
    return temp;
}
Racional Racional::operator/(Racional k) const {
    return (*this).dividir(k);
}

Racional::operator float() const {
    return (float)numerador_ / (float)denominador_;
}

Racional::operator string() const {
    string s;
    s = to_string(numerador_) + "/" + to_string(denominador_);
    return s;
}

// -----------CLASSES "AMIGAS" ------------- //
istream& operator>>(istream& in, Racional& r) {
    int n, d;
    in >> n;
    in >> d;

    r = Racional(n, d);
    return in;
}
ostream& operator<<(ostream& out, Racional r) {
    out << static_cast<string>(r);  // faz cast ímplicito ou explícito, caso tenha sido implmentado.
    // out << (string)r    seria idêntico uma vez que o cast de racional para string já está implementado
    // poderia ser feito:   r.numerador() << "/" << r.denominador();  //porém o cast de string já foi implementado
    return out;
}