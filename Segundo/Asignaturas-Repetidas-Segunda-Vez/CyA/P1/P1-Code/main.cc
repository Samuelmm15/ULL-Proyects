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
#include <algorithm>
#include "Symbol.h"
#include "Symbol.cc" /// Se incluyen los ficheros ".cc" porque el linker da problemas
#include "Alphabet.h"
#include "Alphabet.cc"
#include "Chain.h"
#include "Chain.cc"
#include "MenuOptions.h"
#include "MenuOptions.cc"

void Menu(std::string option, std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain) { /// This is the function that contains the Menu of the program
  MenuOptions Options;
  if (option == "Longitud") {
    Options.ChainsLong(outputFileName, flag, newAlphabet, newChain);
  } else if (option == "Inversa") {
    Options.InverseChains(outputFileName, flag, newChain);
  } else if (option == "Prefijos") {
    Options.PrefixesChains(outputFileName, flag, newChain);
  } else if (option == "Sufijos") {
    Options.SufixesChains(outputFileName, flag, newChain);
  } else if (option == "Subcadenas") {
    Options.Substrings(outputFileName, flag, newChain);
  } else {
    std::cout << "ERROR >> Se ha producido un error al introducir la opción de ejecución del programa" << std::endl;
    std::cout << "Para la correcta ejecución del programa introduzca alguna de las siguientes opciones: " << std::endl;
    std::cout << "Longitud || Inversa || Prefijos || Sufijos || Subcadenas" << std::endl;
    std::cout << "Tener en cuenta que la opción debe de ser introducida de la manera anterior" << std::endl;
  }
};

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

    int flag = 0;
    for (int i = 0; i < file_Content.size(); i++) {
      Alphabet newAlphabet;
      Chain newChain;
      newAlphabet.setSymbolToAlphabet(file_Content[i]);
      newAlphabet.printAlphabet();
      newChain.addChain(file_Content[i], newAlphabet);
      newChain.getChain(0);
      Menu(option, output_File_Name, flag, newAlphabet, newChain); /// En este punto dependiendo de la operación solicitada se accede a algún punto de 
      flag = 1;
    }
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
