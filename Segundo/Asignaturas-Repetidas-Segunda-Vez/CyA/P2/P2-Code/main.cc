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

/// ANOTACIÓN IMPORTANTE FALTA COMPROBAR SI LAS CADENAS PERTENECEN DE MANERA CORRECTA AL ALFABETO

void Menu(Language language1, Language language2, std::string option, std::string outputFileName, bool printFlag) {
  Language languageResult;
  if ((option == "Concatenacion") || (option == "Concatenación")) {
    languageResult.LanguageConcatenation(language1, language2, outputFileName, printFlag);
  } else if ((option == "Union") || (option == "Unión")) {
    languageResult.LanguageUnion(language1, language2, outputFileName, printFlag);
  } else if ((option == "Interseccion" || (option == "Intersección"))) {
    languageResult.LanguageInterseccion(language1, language2, outputFileName, printFlag);
  } else if (option == "Diferencia") {
    languageResult.LanguageSubtract(language1, language2, outputFileName, printFlag);
  } else if (option == "Inversa") { /// un único lenguaje
    languageResult.LanguageInverse(language1, outputFileName, printFlag);
  } else if (option == "Potencia") { /// un único lenguaje
    languageResult.LanguagePotency(language1, outputFileName, printFlag);
  }
};

/**
 * @brief This is the main function of the program.
 * 
 * @param argc is the size of the line to execute the program.
 * @param argv is the differents elements of the line to execute the program.
 * @return int 
 */
int main(int argc, char *argv[]) {
  if (argc == 5) {
    std::string inputFileName = argv[1];
    std::string inputFileName2 = argv[2];
    std::string outputFileName = argv[3];
    std::string option = argv[4];

    /// EN ESTE PUNTO SE DEBE DE PRODUCIR LA LECTURA DEL FICHERO
    FileOperations fileOperation;
    FileOperations fileOperation2;
    std::vector<std::string> fileContent = fileOperation.ReadFile(inputFileName);
    std::vector<std::string> fileContent2 = fileOperation2.ReadFile(inputFileName2);
    
    bool printFlag = true;
    int printCounter = 1;
    bool errorFlag = false;
    /// TRATAMIENTO DEL CONTENIDO DEL FICHERO PARA PODER OBTENER LOS DISTINTOS ELEMENTOS
    for (int i = 0; i < fileContent.size(); i++) {
      std::vector<std::string> dividedAlphabet = fileOperation.AlphabetDivision(fileContent[i]); /// FALTA RECORRER TODAS LAS LÍNEAS DEL FICHERO
      std::vector<std::string> dividedChains = fileOperation.ChainDivision(fileContent[i]);

      Alphabet newAlphabet;
      newAlphabet.setSymbolsToAlphabet(dividedAlphabet); /// Obtención de alfabetos funciona de manera correcta
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

      /// En el caso de que se vaya a hacer uso del segundo fichero
      std::vector<Chain> chainsGroup2;
      Alphabet newAlphabet2;
      if ((option == "Concatenacion") || (option == "Concatenación") || (option == "Union") || (option == "Unión")
        || (option == "Interseccion" || (option == "Intersección")) || (option == "Diferencia")) {    
        std::vector<std::string> dividedAlphabet2 = fileOperation2.AlphabetDivision(fileContent2[i]); /// No se hace uso de otro bucle debido a que este fichero debe de ser del mismo tamaño que el primero para poder realizar las operaciones
        std::vector<std::string> dividedChains2 = fileOperation2.ChainDivision(fileContent2[i]);

        newAlphabet2.setSymbolsToAlphabet(dividedAlphabet2); /// Obtención de alfabetos funciona de manera correcta
        Chain newChain2;
        for (int j = 0; j < dividedChains2.size(); j++) {
          if (newAlphabet2.AlphabetComprobation(dividedChains2[j]) == true) {
            newChain2.AddChain(dividedChains2[j], newAlphabet2);
            chainsGroup2.push_back(newChain2);
            newChain2.~Chain();
          } else {
            std::cout << "ERROR >> La cadena " << dividedChains2[j] << " no pertenece al alfabeto del lenguaje del [segundo] fichero de entrada." << std::endl;
            errorFlag = true;
          }
        }
      }
      /// SE METE DICHO GRUPO DE CADENAS EN EL LENGUAJE
      Language language1;
      language1.IntroduceChainsGroup(chainsGroup);
      std::cout << "Primer lenguaje >>" << std::endl;
      newAlphabet.PrintAlphabet();
      language1.LanguagePrint(); /// Se realiza la impresión para comprobar como va todo
      Language language2;
      if ((option == "Concatenacion") || (option == "Concatenación") || (option == "Union") || (option == "Unión")
        || (option == "Interseccion" || (option == "Intersección")) || (option == "Diferencia")) {
      language2.IntroduceChainsGroup(chainsGroup2);
      std::cout << "Segundo lenguaje >>" << std::endl;
      newAlphabet2.PrintAlphabet();
      language2.LanguagePrint();
      }
      std::cout << std::endl;
      if (errorFlag == false) {
        Menu(language1, language2, option, outputFileName, printFlag);
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
    // std::cout << "accede" << std::endl;
    if (argc == 1) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      std::cout << "Para más información: ./p02_languages [ -h || --help ]" << std::endl;
      exit(1);
    }
    std::string option = argv[1];
    if ((argc == 2) && (option != "--help") && (option != "-h")) {
      std::cout << "ERROR >>> Introduzca las opciones necesarias para la correcta ejecución del programa" << std::endl;
      std::cout << "Para más información: ./p02_languages [ -h || --help ]" << std::endl;
      exit(1);
    }
    if ((option == "-h") || (option == "--help")) {
      std::cout << "AYUDA >>" << std::endl;
      std::cout << "./p02_languages filein.txt filein2.txt fileout.txt [opción]" << std::endl;
      std::cout << "Las opciones válidas son: [ Concatenacion || Union || Interseccion || Diferencia || Inversa || Potencia ]" << std::endl;
    } else {
      std::cout << "ERROR >> El programa ha sido ejecutado de manera incorrecta." << std::endl;
      std::cout << "Introduzca la opción -h o --help para comprobar la correcta ejecución del programa." << std::endl;
    }
    exit(1); /// Exit with error code
  }
  return 0;
};
