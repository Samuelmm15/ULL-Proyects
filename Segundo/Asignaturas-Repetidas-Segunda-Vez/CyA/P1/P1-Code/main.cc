/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Symbol.h"
#include "Chain.h"
#include "Alphabet.h"

// int Menu(std::string option) { /// This is the function that contains the Menu of the program
//   if (option == "Longitud") {

//   } else if (option == "Inversa") {

//   } else if (option == "Prefijos") {

//   } else if (option == "Sufijos") {

//   } else if (option == "Subcadenas") {

//   } else {
//     std::cout << "ERROR >> Se ha producido un error al introducir la opción de ejecución del programa" << std::endl;
//     std::cout << "Para la correcta ejecución del programa introduzca alguna de las siguientes opciones: " << std::endl;
//     std::cout << "Longitud || Inversa || Prefijos || Sufijos || Subcadenas" << std::endl;
//     std::cout << "Tener en cuenta que la opción debe de ser introducida de la manera anterior" << std::endl;
//   }
// };

int main(int argc, char *argv[]) {
  if (argc == 4) {
    std::string input_File_Name = argv[1]; /// Estas líneas son necesarias para trabajar con cadenas
    std::string output_File_Name = argv[2];
    std::string option = argv[3];

    std::ifstream input_File;
    input_File.open(input_File_Name, std::ios::in);
    if (input_File.fail()) {
      std::cout << "ERROR >> Fallo en la apertura del fichero de entrada" << std::endl;
      exit(1);
    }
    std::string line;
    std::vector<std::string> file_Content; /// Almacenaje por líneas del fichero
    if (input_File.is_open()) {
      while (getline(input_File, line)) {
        file_Content.push_back(line);
      }
      input_File.close();
    }

    // std::cout << file_Content[0][5] << std::endl;
    std::vector<std::string> alphabet;
    std::string auxiliary;
    for (int i = 0; i < file_Content.size(); i++) {
      for (int j = 0; j < file_Content[i].size(); j++) {
        if ((file_Content[i][j] != ' ') && (file_Content[i][j] != '\n')) {
          auxiliary.push_back(file_Content[i][j]);
        } else {
          if (file_Content[i][j] != '\n') {
            alphabet.push_back(auxiliary);
            auxiliary.clear();
          }
          auxiliary.clear();
        }
      }
    }

    for (int i = 0; i < alphabet.size(); i++) {
      std::cout << alphabet[i] << '\n';
    }
    // Menu(option); /// En este punto dependiendo de la operación solicitada se accede a algún punto de 
  } else {
    std::string option = argv[1];
    if ((option == "-h") || (option == "--help")) {
      std::cout << "AYUDA >>" << std::endl;
      std::cout << "./p01_strings filein.txt fileout.txt [option]" << std::endl;
    } else {
      std::cout << "ERROR >> El programa ha sido ejecutado de manera incorrecta." << std::endl;
      std::cout << std::endl;
      std::cout << "Introduzca la opción -h o --help para comprobar la correcta ejecución del programa." << std::endl;
    }
    exit(1); /// Exit with error code
  }
};
