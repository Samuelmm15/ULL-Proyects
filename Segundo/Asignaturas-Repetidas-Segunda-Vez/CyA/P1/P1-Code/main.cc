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

void ChainsLong(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << newChain.getChain(0).size() << std::endl;
    }
    outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << newChain.getChain(0).size() << std::endl;
    }
    outputFile.close();
  }
};

void InverseChains(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    std::string auxiliary;
    for (int i = newChain.getChain(0).size() - 1; i >= 0; i--) {
      auxiliary.push_back(newChain.getChain(0).at(i));
    }
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << auxiliary << std::endl;
    }
    outputFile.close();
  } else {
    std::string auxiliary;
    for (int i = newChain.getChain(0).size() - 1; i >= 0; i--) {
      auxiliary.push_back(newChain.getChain(0).at(i));
    }
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << auxiliary << std::endl;
    }
    outputFile.close();
  }
};

void PrefixesChains(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      int i = 1;
      int j = 0;
      std::string auxiliary;
      outputFile << "& ";
      outputFile << newChain.getChain(0).at(j) << " ";
      while (i != newChain.getChain(0).size()) {
        if (j < i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          j++;
        } else if (j == i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          outputFile << auxiliary << " ";
          auxiliary.clear();
          j = 0;
          i++;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      int i = 1;
      int j = 0;
      std::string auxiliary;
      outputFile << "& ";
      outputFile << newChain.getChain(0).at(j) << " ";
      while (i != newChain.getChain(0).size()) {
        if (j < i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          j++;
        } else if (j == i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          outputFile << auxiliary << " ";
          auxiliary.clear();
          j = 0;
          i++;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  }
};

int Menu(std::string option, std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain) { /// This is the function that contains the Menu of the program
  if (option == "Longitud") {
    ChainsLong(outputFileName, flag, newAlphabet, newChain);
  } else if (option == "Inversa") {
    InverseChains(outputFileName, flag, newChain);
  } else if (option == "Prefijos") {
    PrefixesChains(outputFileName, flag, newChain);
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
