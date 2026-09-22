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
 * Definición de la clase Cadena que representa una secuencia de símbolos de un alfabeto.
 * Incluye constructores, métodos para manipular la cadena, operadores de comparación y 
 * operadores de entrada/salida.
*/



#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include <string>
#include "simbolo.h"
#include "lenguaje.h"

class Lenguaje; // Declaracion adelantada para evitar dependencias circulares

class Cadena {
 public:
  Cadena() = default; 
  explicit Cadena(const std::string& str); 

  size_t GetLongitud() const; 
  Cadena Inversa() const;  
  Lenguaje Prefijos() const;  
  Lenguaje Sufijos() const;
  const std::vector<Simbolo>& GetSimbolos() const;
  
  bool operator<(const Cadena& otra) const;
  bool operator==(const Cadena& otra) const;


  friend std::ostream& operator<<(std::ostream& os, const Cadena& c);
  friend std::istream& operator>>(std::istream& is, Cadena& c);


 private:
  std::vector<Simbolo> datos_; 
};

#endif  // CADENA_H
