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
#include "Symbol.cc" /// Se incluyen los ficheros ".cc" porque el linker da problemas
#include "Alphabet.h"
#include "Alphabet.cc"
#include "Chain.h"
#include "Chain.cc"

void ChainsLong(std::string outputFileName, Alphabet newAlphabet, Chain newChain) {
  std::fstream outputFile;
  outputFile.open(outputFileName, std::ios_base::out); /// SI NO DEJA AÑADIR NUEVAS LÍNEAS AL FICHERO Y SE REINICIA PROBAR A PONER LA VARIABLE DEL FICHERO EN EL MAIN Y PASARLO A LA FUNCIÓN PARA QUE PUEDA AÑADIR NUEVAS LÍNEAS Y NO TENER QUE ABRIR CADA VEZ EL FICHERO
  if (!outputFile.is_open()) {
    std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
  } else {
    outputFile << newChain.getChain(0).size() << std::endl;
  }
};

int Menu(std::string option, std::string outputFileName, Alphabet newAlphabet, Chain newChain) { /// This is the function that contains the Menu of the program
  if (option == "Longitud") {
    ChainsLong(outputFileName, newAlphabet, newChain);
  } else if (option == "Inversa") {

  } else if (option == "Prefijos") {

  } else if (option == "Sufijos") {

  } else if (option == "Subcadenas") {

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

    for (int i = 0; i < file_Content.size(); i++) {
      Alphabet newAlphabet;
      Chain newChain;
      newAlphabet.setSymbolToAlphabet(file_Content[i]);
      newAlphabet.printAlphabet();
      newChain.addChain(file_Content[i], newAlphabet);
      newChain.getChain(0);
      Menu(option, output_File_Name, newAlphabet, newChain); /// En este punto dependiendo de la operación solicitada se accede a algún punto de 
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
