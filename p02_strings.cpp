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
 * Archivo: p02_strings.cpp
 * descripción: 
 * Programa principal que gestiona la entrada y salida de datos para operaciones con cadenas y lenguajes.
 * Permite al usuario especificar un archivo de entrada, un archivo de salida y una operación a realizar
*/

#include <iostream>
#include <fstream>
#include <string>
#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

void ImprimirAyuda() {
  std::cout << "Modo de empleo: ./p02_strings fichero_entrada.txt fichero_salida.txt opcode\n"
            << "Opcodes disponibles:\n"
            << "1: Alfabeto\n"
            << "2: Longitud\n"
            << "3: Inversa\n"
            << "4: Prefijos\n"
            << "5: Sufijos\n"
            << "6: Validacion\n";

}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "Modo de empleo: ./p02_strings fichero_entrada.txt fichero_salida.txt opcode\n";
    std::cerr << "Pruebe './p02_strings--help' para más información.\n";
    return 1;
  }

  if (std::string(argv[1]) == "--help") {
    ImprimirAyuda();
    return 0;
  }

  if (argc != 4) {
    std::cerr << "Error: número incorrecto de parámetros.Pruebe './p02_cadenas --help' para más información.\n";
    ImprimirAyuda();
    return 1;
  }

  std::string fichero_entrada = argv[1];
  std::string fichero_salida = argv[2];
  int opcode = std::stoi(argv[3]);

  std::ifstream entrada(fichero_entrada);
  if (!entrada.is_open()) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada.\n";
    return 1;
  }

  std::ofstream salida(fichero_salida);
  if (!salida.is_open()) {
    std::cerr << "Error: no se pudo abrir el fichero de salida.\n";
    return 1;
  }

  
  std::string cadena_str, alfabeto_str;
  while (entrada >> cadena_str >> alfabeto_str) {
    Cadena cadena(cadena_str);
    Alfabeto alfabeto;

    for (char c : alfabeto_str) {
      alfabeto.Insertar(Simbolo(c));
    }

  switch (opcode) {
        case 1:
          salida << cadena_str << ": " << alfabeto; 
          break;
        case 2:
          salida << cadena.GetLongitud();
          break;
        case 3:
          salida << cadena_str << " -> " << cadena.Inversa(); 
          break;
        case 4:
          salida << cadena.Prefijos();
          break;
        case 5:
          salida << cadena.Sufijos();
          break;
        case 6: { 
          bool es_valida = true;
          for (const auto& simbolo : cadena.GetSimbolos()) {
            if (!alfabeto.Contiene(simbolo)) {
              es_valida = false;
              break; 
            }
          }
          
          if (es_valida) {
            salida << "OK";
          } else {
            salida << "ERROR";
          }
          break;
        }
        default:
          std::cerr << "Error: opcode no válido.\n";
          ImprimirAyuda();
          return 1;
      }

      salida << "\n";
    }

  entrada.close();
  salida.close();
  return 0;
}
