/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
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
 * @brief This function implements the Menu of the different options of the program.
 * 
 * @param language1 This is the first language to operate.
 * @param language2 This is the second language to operate.
 * @param option The operation of the program.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Menu(Language language1, std::string option, std::string outputFileName, bool printFlag) {
  // Language languageResult;
  // if ((option == "Concatenacion") || (option == "Concatenación")) {
  //   languageResult.LanguageConcatenation(language1, language2, outputFileName, printFlag);
  // } else if ((option == "Union") || (option == "Unión")) {
  //   languageResult.LanguageUnion(language1, language2, outputFileName, printFlag);
  // } else if ((option == "Interseccion" || (option == "Intersección"))) {
  //   languageResult.LanguageInterseccion(language1, language2, outputFileName, printFlag);
  // } else if (option == "Diferencia") {
  //   languageResult.LanguageSubtract(language1, language2, outputFileName, printFlag);
  // } else if (option == "Inversa") { /// un único lenguaje
  //   languageResult.LanguageInverse(language1, outputFileName, printFlag);
  // } else if (option == "Potencia") { /// un único lenguaje
  //   languageResult.LanguagePotency(language1, outputFileName, printFlag);
  // }
};

/// ARREGLAR LA COMPROBACIÓN DE QUE SI INTRODUCIMOS LA OPCIÓN -H SE EJECUTE LA AYUDA DEL PROGRAMA

/**
 * @brief This is the main function of the program.
 * 
 * @param argc is the size of the line to execute the program.
 * @param argv is the differents elements of the line to execute the program.
 * @return int 
 */
int main(int argc, char *argv[]) {
  if (argc == 2) {
    std::string inputFileName = argv[1];

    FileOperations fileOperation;
    std::vector<std::string> fileContent = fileOperation.ReadFile(inputFileName);
    
    bool printFlag = true;
    int printCounter = 1;
    bool errorFlag = false;
    for (int i = 0; i < fileContent.size(); i++) {
      // std::vector<std::string> dividedAlphabet = fileOperation.AlphabetDivision(fileContent[i]);
      std::vector<std::string> dividedChains = fileOperation.ChainDivision(fileContent[i]);

      /// OBTENCIÓN DE LOS ALFABETOS A PARTIR DE LAS CADENAS DE LOS LENGUAJES
      std::vector<std::string> dividedAlphabet;
      std::string auxiliaryDivition;
      bool comprobationFlag = false;
      for (int i = 0; i < dividedChains.size(); i++) {
        auxiliaryDivition = dividedChains[i];
        for (int j = 0; j < auxiliaryDivition.size(); j++) {
          if (dividedAlphabet.size() == 0) {
            std::string auxiliary;
            auxiliary = auxiliaryDivition[j];
            dividedAlphabet.push_back(auxiliary);
          } else {
            std::string auxiliary;
            auxiliary = auxiliaryDivition[j];
            for (int k = 0; k < dividedAlphabet.size(); k++) {
              if (dividedAlphabet[k] == auxiliary) {
                comprobationFlag = true;
              }
            }
            if (comprobationFlag == false) {
              dividedAlphabet.push_back(auxiliary);
            }
          }
        }
      }
      
      for (int j = 0; j < dividedChains.size(); j++) {
        std::cout << dividedChains[j] << std::endl;
      }

      Alphabet newAlphabet;
      newAlphabet.setSymbolsToAlphabet(dividedAlphabet);
      Chain newChain;
      std::vector<Chain> chainsGroup;
      for (int j = 0; j < dividedChains.size(); j++) {
        if (newAlphabet.AlphabetComprobation(dividedChains[j]) == true) {
          newChain.AddChain(dividedChains[j], newAlphabet);
          chainsGroup.push_back(newChain);
          newChain.~Chain();
        } else {
          std::cout << "ERROR >> La cadena " << dividedChains[j] << " no pertenece al alfabeto del lenguaje del [primer] fichero de entrada." << std::endl;
          errorFlag = true;
        }
      }

      Language language1;
      language1.IntroduceChainsGroup(chainsGroup);
      std::cout << "Lenguaje y alfabeto fichero 1>>" << std::endl;
      newAlphabet.PrintAlphabet();
      language1.LanguagePrint();
      std::cout << std::endl;
      if (errorFlag == false) {
        // Menu(language1, option, outputFileName, printFlag);
        printCounter++;
      }
      if (printCounter == 1) {
        printFlag = true;
      } else {
        printFlag = false;
      }
      errorFlag = false;
    }
  } else {
    if (argc == 1) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      std::cout << "Para más información: ./p03_calculator [ -h || --help ]" << std::endl;
      exit(1);
    }
    std::string option = argv[1];
    if ((argc == 2) && (option != "--help") && (option != "-h")) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      std::cout << "Para más información: ./p03_calculator [ -h || --help ]" << std::endl;
      exit(1);
    }
    if ((option == "-h") || (option == "--help")) {
      std::cout << "AYUDA >>" << std::endl;
      std::cout << "./p03_calculator filein.txt" << std::endl;
    } else {
      std::cout << "ERROR >> El programa ha sido ejecutado de manera incorrecta." << std::endl;
      std::cout << "Introduzca la opción -h o --help para comprobar la correcta ejecución del programa." << std::endl;
    }
    exit(1); /// Exit with error code
  }
  return 0;
};
