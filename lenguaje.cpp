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
 * Archivo: lenguaje.cpp
 * descripción: 
 * Implementacion de la clase lenguaje.
*/

#include "lenguaje.h"
#include "cadena.h"
#include <iostream>

void Lenguaje::Insertar(const Cadena& c) {
  cadenas_.insert(c);
}

void Lenguaje::Imprimir(std::ostream& os) const {
  os << "{";
  for (auto it = cadenas_.begin(); it != cadenas_.end(); ++it) {
    os << *it;
    if (std::next(it) != cadenas_.end()) {
      os << " , ";   
    }
  }
  os << "}";
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {
  l.Imprimir(os);
  return os;
}

