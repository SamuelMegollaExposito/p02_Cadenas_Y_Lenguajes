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
 * Archivo: cadena.cpp
 * descripción: 
 * Implementacion de la clase cadena.
*/


#include "cadena.h"
#include "lenguaje.h"
#include <iostream>

Cadena::Cadena(const std::string& str) {
  for (char c : str) {
    datos_.push_back(Simbolo(c));
  }
}

size_t Cadena::GetLongitud() const {
  return datos_.size();
}

Cadena Cadena::Inversa() const {
  Cadena inversa;
  for (auto it = datos_.rbegin(); it != datos_.rend(); ++it) { 
    inversa.datos_.push_back(*it);
  }
  return inversa;
}

Lenguaje Cadena::Prefijos() const {
  Lenguaje prefijos;
  Cadena actual;
  prefijos.Insertar(Cadena(""));  
  for (const auto& simbolo : datos_) {
    actual.datos_.push_back(simbolo);
    prefijos.Insertar(actual);
  }
  return prefijos;
}

Lenguaje Cadena::Sufijos() const {
  Lenguaje sufijos;
  sufijos.Insertar(Cadena(""));  
  for (size_t i = 0; i < datos_.size(); ++i) {
    Cadena sufijo;
    for (size_t j = i; j < datos_.size(); ++j) {
      sufijo.datos_.push_back(datos_[j]);
    }
    sufijos.Insertar(sufijo);
  }
  return sufijos;
}

const std::vector<Simbolo>& Cadena::GetSimbolos() const {
  return datos_;
}

std::ostream& operator<<(std::ostream& os, const Cadena& c) {
  if (c.datos_.empty()) {
    os << "&";
  } else {
    for (const auto& simbolo : c.datos_) {
      os << simbolo;
    }
  }
  return os;
}

std::istream& operator>>(std::istream& is, Cadena& c) {
  std::string str;
  if (is >> str) {
    c = Cadena(str);
  }
  return is;
}

bool Cadena::operator<(const Cadena& otra) const {
  if (datos_.size() != otra.datos_.size()) {
    return datos_.size() < otra.datos_.size();
  }
  return datos_ < otra.datos_;
}

bool Cadena::operator==(const Cadena& otra) const {
  return datos_ == otra.datos_;
}
