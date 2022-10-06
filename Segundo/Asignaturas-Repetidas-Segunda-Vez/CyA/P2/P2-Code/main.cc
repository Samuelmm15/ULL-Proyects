/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
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
#include "Alphabet.h"
#include "Chain.h"
#include "Language.h"
#include "FileOperations.h"

/**
 * @brief This is the main function of the program.
 * 
 * @param argc is the size of the line to execute the program.
 * @param argv is the differents elements of the line to execute the program.
 * @return int 
 */
int main(int argc, char *argv[]) {
  if (argc == 4) {
    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    std::string option = argv[3];

    /// EN ESTE PUNTO SE DEBE DE PRODUCIR LA LECTURA DEL FICHERO
    FileOperations fileOperation(inputFileName);
    std::vector<std::string> fileContent = fileOperation.ReadFile();
    
    /// TRATAMIENTO DEL CONTENIDO DEL FICHERO PARA PODER OBTENER LOS DISTINTOS ELEMENTOS
    for (int i = 0; i < fileContent.size(); i++) {
      std::vector<std::string> dividedAlphabet = fileOperation.AlphabetDivision(fileContent[i]); /// FALTA RECORRER TODAS LAS LÍNEAS DEL FICHERO
      std::vector<std::string> dividedChains = fileOperation.ChainDivision(fileContent[i]);

      Alphabet newAlphabet;
      newAlphabet.setSymbolsToAlphabet(dividedAlphabet); /// Obtención de alfabetos funciona de manera correcta
      newAlphabet.PrintAlphabet();
      Chain newChain;
      std::vector<Chain> chainsGroup;
      for (int j = 0; j < dividedChains.size(); j++) {
        newChain.AddChain(dividedChains[j], newAlphabet);
        chainsGroup.push_back(newChain);
        newChain.~Chain();
      }
      for (int k = 0; k < chainsGroup.size(); k++) { /// En este punto se tienen las cadenas de los distintos lenguajes del fichero
        std::cout << chainsGroup[k].getChain() << " ";
      }
      std::cout << std::endl;

      /// SE METE DICHO GRUPO DE CADENAS EN EL LENGUAJE
      Language newLanguage(chainsGroup);
      newLanguage.LanguagePrint();
    }

  } else {
    std::string option = argv[1];
    if ((argc = 1) && (option != "--help")) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      exit(1);
    }
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
  return 0;
};
