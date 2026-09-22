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
 * Definición de la clase Simbolo.
 * Contiene la definición de la clase Simbolo, que representa un símbolo
 * individual en un alfabeto. Incluye constructores, operadores de comparación
 * y operadores de entrada/salida.
*/


#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo {
 public:
  Simbolo(char valor = '&'); 
  char GetValor() const; 
  bool operator<(const Simbolo& otro) const; 
  bool operator==(const Simbolo& otro) const; 

  friend std::ostream& operator<<(std::ostream& os, const Simbolo& s); 
  friend std::istream& operator>>(std::istream& is, Simbolo& s);

 private:
  char valor_;
};

#endif  // SIMBOLO_H