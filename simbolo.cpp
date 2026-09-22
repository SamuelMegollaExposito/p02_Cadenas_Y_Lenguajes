/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Autor: Samuel Megolla Expósito
 * Correo: alu0101567198@ull.edu.es
 * Fecha: 22/09/2026
 * Archivo: simbolo.h
 * descripción: 
 * Implementacion de la clase simbolo
*/

#include "simbolo.h"

Simbolo::Simbolo(char valor) : valor_(valor) {}

char Simbolo::GetValor() const {
  return valor_;
}

bool Simbolo::operator<(const Simbolo& otro) const {
  return valor_ < otro.valor_;
}

bool Simbolo::operator==(const Simbolo& otro) const {
  return valor_ == otro.valor_;
}

std::ostream& operator<<(std::ostream& os, const Simbolo& s) {
  os << s.valor_;
  return os;
}

std::istream& operator>>(std::istream& is, Simbolo& s) {
  char c;
  if (is >> c) {
    s.valor_ = c;
  }
  return is;
}
