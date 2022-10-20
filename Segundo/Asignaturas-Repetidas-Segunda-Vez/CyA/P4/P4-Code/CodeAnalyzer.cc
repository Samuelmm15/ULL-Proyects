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

  /// Comenzamos con la comprobación de las variables.
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_match(linesVector[i], variablesAnalyzer) == true) {
      std::cout << "Variable encontrada en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
    }
  }
};

void CodeAnalyzer::LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};

void CodeAnalyzer::MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};

void CodeAnalyzer::CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};
