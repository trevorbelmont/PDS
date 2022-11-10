// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

using namespace std;

Complexo::Complexo() {
    real_ = r = imag_ = theta = 0;
}

Complexo::Complexo(double a, double b) {
    double r0 = sqrt(pow(a, 2) + pow(b, 2));
    double theta0 = atan(b/a);//pow(tan(b / a), -1);

    //  x = r0 * sin(theta0);
    //  y = r0 * cos(theta0);

    r = r0;
    theta = theta0;

    real_ = a;
    imag_ = b;
}

double Complexo::real() {
    real_ = abs(r) * cos(theta);
    imag_ = abs(r) * sin(theta);
    return real_;
}

double Complexo::imag() {
    real_ = abs(r) * cos(theta);
    imag_ = abs(r) * sin(theta);
    return imag_;
}

bool Complexo::igual(Complexo x) {
    if (real() == x.real_ && (*this).imag() == x.imag_) {
        return true;
    } else {
        return false;
    }
}

void Complexo::Atribuir(Complexo x) {
    (*this) = x;
}

double Complexo::modulo() {
    double d = sqrt(pow(real(), 2) + pow(imag(), 2));

    return d;
}

Complexo Complexo::conjugado() {
    Complexo c;
    c = (*this);
    c.theta = -c.theta;
    c.imag_ = -c.imag_;
    return c;
}

Complexo Complexo::simetrico() {
    Complexo c;
    double r0 = sqrt(pow(real_, 2) + pow(imag_, 2));
    double theta0 = pow(tan(imag_ / real_), -1);

    c.r = -r;
    c.theta = theta;

    return c;
}

Complexo Complexo::inverso() {
    Complexo i;
    i.r = 1 / r;
    i.theta = -theta;
    return i;
}

Complexo Complexo::somar(Complexo y) {
    double sReal = real_ + y.real_;
    double sImag = imag_ + y.imag_;

    Complexo s(sReal, sImag);

    return s;
}

Complexo Complexo::subtrair(Complexo y) {
    double sReal = real_ - y.real_;
    double sImag = imag_ - y.imag_;

    Complexo s(sReal, sImag);

    return s;
}

Complexo Complexo::multiplicar(Complexo y) {
    double newR = r * y.r;
    double newTheta = theta + y.theta;

    Complexo p(newR, newTheta);
    return p;
}

Complexo Complexo::dividir(Complexo y) {
    double newR = r * y.r;
    double newTheta = theta + y.theta;

    Complexo d(newR, newTheta);
    return d;
}
