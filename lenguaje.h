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
 * Archivo: lenguaje.h
 * descripción: 
 * Definición de la clase Lenguaje que representa un conjunto de cadenas únicas.
 * Incluye constructores, métodos para añadir cadenas, operadores de comparación y 
 * operadores de entrada/salida.
*/


#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <set>
#include "cadena.h"

class Cadena;  

class Lenguaje {
 public:
  Lenguaje() = default;
  void Insertar(const Cadena& c);
  void Imprimir(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& l);

 private:
  std::set<Cadena> cadenas_;
};

#endif  // LENGUAJE_H
