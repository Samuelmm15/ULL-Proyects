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
#include "FileOperations.h"

CodeAnalyzer::CodeAnalyzer(){};

void CodeAnalyzer::VariablesAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){
  bool printFlag = false;
  std::regex variablesAnalyzer("^(\\s*)?(int|double) [a-zA-Z]+( = [0-9]+)?;$");

//   std::string test = "int factorial = 1;";
//   if (std::regex_match(test, variablesAnalyzer)) {
//     std::cout << "Matched" << std::endl;
//   } else {
//     std::cout << "Not Matched" << std::endl;
//   }

  std::vector<int> numberOfLine;
  std::cout << std::endl;
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

    /// Escritura de los resultados en el fichero de salida.
    FileOperations fileOperations;
    fileOperations.WriteFile(vectorResult, false, printFlag, fileOutName, "Variables");
    printFlag = true;
    // std::cout << std::endl;
    // // /// Comprobación de los datos obtenidos.
    // for (int i = 0; i < vectorResult.size(); i++) {
    //   std::cout << vectorResult[i] << std::endl;
    // }
    vectorResult.clear();
    firstPosition.clear();
    secondPosition.clear();
    thirdPosition.clear();
  }
};

void CodeAnalyzer::LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){
  bool printFlag = true;
  std::regex loopsAnalyzer("^(\\s*)?(for|while)");

  std::vector<int> numberOfLine;
  std::vector<std::string> vectorResult;
  /// Contador de bucles.
  int forCounter = 0;
  int whileCounter = 0;

  std::cout << std::endl;
  /// Comenzamos con la comprobación de los bucles.
  std::smatch match;
  for (int i = 0; i < linesVector.size(); i++) {
    std::regex_search(linesVector[i], match ,loopsAnalyzer);
    std::string auxiliary = match[0];
    auxiliary.erase(std::remove(auxiliary.begin(), auxiliary.end(), ' '), auxiliary.end()); /// Eliminación de los espacios en blanco.
    if ((auxiliary == "for") || (auxiliary == "while")) {
      std::cout << "Bucle encontrado en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      if (auxiliary == "for") {
        forCounter++;
      } else {
        whileCounter++;
      }
      numberOfLine.push_back(i);
      vectorResult.push_back(match[0]);
    }
  }

  /// Impresión de los resultados en el fichero de salida.
  FileOperations fileOperations;
  for (int i = 0; i < vectorResult.size(); i++) {
    std::vector<std::string> auxiliaryVector;
    std::string auxiliary;
    auxiliary = std::to_string(numberOfLine[i] + 1);
    auxiliaryVector.push_back(auxiliary);
    vectorResult[i].erase(std::remove(vectorResult[i].begin(), vectorResult[i].end(), ' '), vectorResult[i].end());
    auxiliaryVector.push_back(vectorResult[i]);
    fileOperations.WriteFile(auxiliaryVector, false, printFlag, fileOutName, "Loops");
  }
  
  std::vector<std::string> auxiliaryVector;
  auxiliaryVector.push_back(std::to_string(forCounter));
  auxiliaryVector.push_back(std::to_string(whileCounter));
  fileOperations.WriteFile(auxiliaryVector, true,  printFlag, fileOutName, "Loops");
};

void CodeAnalyzer::MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};

void CodeAnalyzer::CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){};
