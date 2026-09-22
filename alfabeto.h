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
 * Archivo: alfabeto.h
 * descripción: 
 * Definición de la clase Alfabeto que representa un conjunto de símbolos únicos.
 * Incluye constructores, métodos para añadir y eliminar símbolos, y 
 * operadores de entrada/salida.
*/



#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include "simbolo.h"

class Alfabeto {
 public:
  Alfabeto() = default; 
  void Insertar(const Simbolo& s); 
  bool Contiene(const Simbolo& s) const;
  void Imprimir(std::ostream& os) const; 
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& a); 

 private:
  std::set<Simbolo> simbolos_;
};

#endif  // ALFABETO_H
