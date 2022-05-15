// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
    this->real_ = 0;
    this->imag_ = 0;
}

Complexo::Complexo(double a, double b) {
    this->real_ = a;
    this->imag_ = b;
}

double Complexo::real() {
  return this->real_;
}

double Complexo::imag() {
  return this->imag_;
}

bool Complexo::igual(Complexo x) {
  return this->real_ == x.real() && this->imag_ == x.imag();
}

void Complexo::Atribuir(Complexo x) {
    this->real_ = x.real();
    this->imag_ = x.imag();
}

double Complexo::modulo() {
  return sqrt( pow(this->real_,2) + pow(this->imag_,2));
}

Complexo Complexo::conjugado() {
  Complexo c new Complexo{this->real_, (-1 * this->imag_)};
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c new Complexo{ ( -1 * this->real_), (-1 * this->imag_)};
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  return d;
}
