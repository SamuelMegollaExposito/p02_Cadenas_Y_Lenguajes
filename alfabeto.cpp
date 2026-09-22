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
 * Archivo: alfabeto.cc
 * descripción: 
 * Implementación de la clase Alfabeto.
*/

#include "alfabeto.h"
#include <iostream>

void Alfabeto::Insertar(const Simbolo& s) {
  simbolos_.insert(s);
}

bool Alfabeto::Contiene(const Simbolo& s) const {
  return simbolos_.find(s) != simbolos_.end();
}

void Alfabeto::Imprimir(std::ostream& os) const {
  os << "{";
  for (auto it = simbolos_.begin(); it != simbolos_.end(); ++it) {
    os << *it;
    if (std::next(it) != simbolos_.end()) {
      os << ", ";
    }
  }
  os << "}";
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& a) {
  a.Imprimir(os);
  return os;
}