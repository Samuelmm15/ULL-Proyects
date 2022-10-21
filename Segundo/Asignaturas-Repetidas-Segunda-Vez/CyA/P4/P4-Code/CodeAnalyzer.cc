/**
 * @file CodeAnalyzer.cc
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

#include "CodeAnalyzer.h"

CodeAnalyzer::CodeAnalyzer(){};

void CodeAnalyzer::VariablesAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){
  std::regex variablesAnalyzer("^(\\s*)?(int|double) [a-zA-Z]+( = [0-9]+)?;$");

//   std::string test = "int factorial = 1;";
//   if (std::regex_match(test, variablesAnalyzer)) {
//     std::cout << "Matched" << std::endl;
//   } else {
//     std::cout << "Not Matched" << std::endl;
//   }

  std::vector<int> numberOfLine;
  /// Comenzamos con la comprobación de las variables.
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_match(linesVector[i], variablesAnalyzer) == true) {
      std::cout << "Variable encontrada en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      numberOfLine.push_back(i);
    }
  }

  /// Creación de expresiones regulares para la obtención de los distintos datos;
  std::regex typeOfVariable("^(\\s*)?(int|double)"); /// Expresión regular para obtener el tipo de variable.
  std::regex nameOfVariable("((int|double) [a-zA-Z]+)"); /// Obtención del nombre de la variable.
  std::regex initializationComprobation("( = )"); /// Comprobación de si la variable está inicializada.

  std::vector<std::string> vectorResult;
  for(int i = 0; i < numberOfLine.size(); i++) {
    /// Comprobación del tipo de variable.
    std::string line = linesVector[numberOfLine[i]];
    std::smatch match;
    std::regex_search(line, match, typeOfVariable);
    std::string firstPosition = match[0];
    firstPosition.erase(std::remove(firstPosition.begin(), firstPosition.end(), ' '), firstPosition.end()); /// Eliminación de los espacios en blanco.
    
    /// comprobación del nombre de la variable.
    std::smatch match1;
    std::regex_search(line, match1, nameOfVariable);
    std::string secondPosition;
    secondPosition = match1[0];
    
    std::string auxiliary;
    for (int i = 0; i < secondPosition.size(); i++) {
      if (secondPosition[i] != ' ') {
        auxiliary = auxiliary + secondPosition[i];
      } else {
        if ((auxiliary == "int") || (auxiliary == "double")) {
          auxiliary.clear();
        } else {
          secondPosition.clear();
          secondPosition = auxiliary;
          auxiliary.clear();
        }
      }
      if (i == secondPosition.size() - 1) {
        secondPosition.clear();
        secondPosition = auxiliary;
        auxiliary.clear();
      }
    }

    /// Comprobación de si la variable está inicializada.
    std::smatch match2;
    std::regex_search(line, match2, initializationComprobation);
    std::string thirdPosition;
    if (match2[0] == " = ") {
      thirdPosition = "Sí";
    } else {
      thirdPosition = "No";
    }
    vectorResult.push_back(firstPosition);
    vectorResult.push_back(secondPosition);
    vectorResult.push_back(thirdPosition);
    std::string linePosition = std::to_string(numberOfLine[i] + 1);
    vectorResult.push_back(linePosition);

    std::cout << std::endl;
    // /// Comprobación de los datos obtenidos.
    for (int i = 0; i < vectorResult.size(); i++) {
      std::cout << vectorResult[i] << std::endl;
    }
    vectorResult.clear();
    firstPosition.clear();
    secondPosition.clear();
    thirdPosition.clear();
  }
};

void CodeAnalyzer::LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};

void CodeAnalyzer::MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};

void CodeAnalyzer::CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};
