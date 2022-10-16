/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the main function of the program.
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
 * @brief This is the main function of the program.
 * 
 * @param argc is the size of the line to execute the program.
 * @param argv is the differents elements of the line to execute the program.
 * @return int 
 */
int main(int argc, char *argv[]) {
  if (argc == 1) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      std::cout << "Para más información: ./p03_calculator [ -h || --help ]" << std::endl;
      exit(1);
  }

  std::string option = argv[1];
  if ((argc == 2) && (option != "-h") && (option != "--help")) { /// If the introduced option is different of --help or -h.
    std::string inputFileName = argv[1];

    FileOperations fileOperation;
    std::vector<std::string> fileContent = fileOperation.ReadFile(inputFileName);
    
    bool printFlag = true;
    int printCounter = 1;
    bool errorFlag = false;
    std::vector<Language> languageVector; /// To store the different Languages included at the introduced file.
    std::vector<int> operationFileLines;
    for (int i = 0; i < fileContent.size(); i++) {
      std::vector<std::string> dividedChains = fileOperation.ChainDivision(fileContent[i]);

      if (dividedChains[0] != "-1") { /// To obtain the alphabet of the Language.
        std::vector<std::string> dividedAlphabet;
        std::string auxiliaryDivition;
        bool comprobationFlag = false;
        for (int j = 0; j < dividedChains.size(); j++) {
          auxiliaryDivition = dividedChains[j];
          for (int k = 0; k < auxiliaryDivition.size(); k++) {
            if ((dividedAlphabet.size() == 0)) {
              std::string auxiliary;
              auxiliary = auxiliaryDivition[k];
              if (auxiliary != "&") {
                dividedAlphabet.push_back(auxiliary);
              }
            } else {
              std::string auxiliary;
              auxiliary = auxiliaryDivition[k];
              if (auxiliary != "&") {
                for (int l = 0; l < dividedAlphabet.size(); l++) {
                  if (dividedAlphabet[l] == auxiliary) {
                    comprobationFlag = true;
                  }
                }
                if (comprobationFlag == false) {
                  dividedAlphabet.push_back(auxiliary);
                }
                comprobationFlag = false;
              }
            }
          }
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

        Language auxiliaryLanguage;
        auxiliaryLanguage.IntroduceChainsGroup(chainsGroup);
        languageVector.push_back(auxiliaryLanguage);
        std::cout << "Lenguaje y alfabeto de la línea " << i << " >>" << std::endl;
        newAlphabet.PrintAlphabet();
        auxiliaryLanguage.LanguagePrint();
        std::cout << std::endl;
        if (errorFlag == false) {
          printCounter++;
        }
        if (printCounter == 1) {
          printFlag = true;
        } else {
          printFlag = false;
        }
        errorFlag = false;
      } else {
        operationFileLines.push_back(i); /// This vector contains the position of the lines that has the operation code.
      }
    }
    
    int auxiliaryPosition = 0;
    Language languageResult;
    for (int j = 0; j < operationFileLines.size(); j++) {
      auxiliaryPosition = operationFileLines[j];
      languageResult.ReversePolishNotation(fileContent[auxiliaryPosition], languageVector);
    }
  } else {
    std::string option = argv[1];
    if ((option == "-h") || (option == "--help")) {
      std::cout << "AYUDA >>" << std::endl;
      std::cout << "Un ejemplo de correcta ejecución del programa es: " << std::endl;
      std::cout << "./p03_calculator filein.txt" << std::endl;
    } else {
      std::cout << "ERROR >> El programa ha sido ejecutado de manera incorrecta." << std::endl;
      std::cout << "Introduzca la opción -h o --help para comprobar la correcta ejecución del programa." << std::endl;
    }
    exit(1); /// Exit with error code
  }
  return 0;
};
