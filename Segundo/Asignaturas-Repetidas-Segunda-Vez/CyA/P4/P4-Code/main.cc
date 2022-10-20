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
#include <string>
#include <vector>

#include "FileOperations.h"


int main(int argc, char *argv[]) {
  if (argc == 3) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    /// comprobación de si el primer fichero de entrada acaba en .cc con expresión regular
    std::regex fileInComprobation(".+.cc$");
    std::smatch matches;
    if (std::regex_match(inputFile, matches, fileInComprobation) == true) {
      std::cout << std::endl;
      std::cout << "El fichero de  ha sido introducido de manera correcta." << std::endl;
    } else {
      std::cout << std::endl;
      std::cout << "ERROR >>> " << std::endl;
      std::cout << "El fichero ha siso introducido de manera incorrecta" << std::endl;
      std::cout << "La extensión correcta del fichero de comprobación es .cc" << std::endl;
      exit(1); /// Salida del programa con error de tipo 1.
    }

    /// comprobación de si el segundo fichero de entrada acaba en .txt para comprobar si está correcto
    std::regex fileOutComprobation(".+.txt$");
    std::smatch matches2;
    if (std::regex_match(outputFile, matches2, fileOutComprobation) == true) {
      std::cout << std::endl;
      std::cout << "El fichero de salida ha sido introducido de manera correcta." << std::endl;
    } else {
      std::cout << std::endl;
      std::cout << "ERROR >>> " << std::endl;
      std::cout << "El fichero ha siso introducido de manera incorrecta" << std::endl;
      std::cout << "La extensión correcta del fichero de comprobación es .txt" << std::endl;
      exit(1);
    }

    /// Lectura del fichero de entrada para poder obtener las líneas del fichero
    std::vector<std::string> linesVector;
    FileOperations fileOperations;
    linesVector = fileOperations.ReadFile(inputFile);

    for (int i = 0; i < linesVector.size(); i++) {
      std::cout << linesVector[i] << std::endl;
    }

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