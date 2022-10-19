/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>  /// Esta es la libraría para expresiones regulares
#include <vector>

int main(int argc, char *argv[]) {
  if (argc == 4) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
  } else {
    std::string option = argv[1];
    if (argc == 2) {
      if ((option == "-h") || (option == "--help")) {
        std::cout << "Ayuda de ejecución del programa >>> " << std::endl;
        std::cout << "./p04_code_analyzer [Fichero_de_Entrada] [Fichero_de_Salida]" << std::endl;
        exit(1); /// Salida del programa con error de tipo 1.
      } else {
        std::cout << "ERROR >>> La opción introducida, no es válida." << std::endl;
        std::cout << "La opción introducida ha sido " << option << std::endl;
        std::cout << "Para más información introduzca la opción -h o --help" << std::endl;
        exit(1);
      }
    } else {
      std::cout << "El programa ha sido ejecutado de manera erronea." << std::endl;
      std::cout << "Para más inforamción introduzca la opción -h o --help" << std::endl;
      exit(1);
    }
  }
  return 0;
};