/**
 * @file CodeAnalyzer.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents the implementation of the CodeAnalyzer methods.
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

/**
 * @brief This is the constructor of the class.
 * 
 */
CodeAnalyzer::CodeAnalyzer(){};

/**
 * @brief This method is used to analyze the variables.
 * 
 * @param linesVector The vector with the lines of the code.
 * @param fileOutName The name of the output file.
 */
void CodeAnalyzer::VariablesAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){
  std::regex variablesAnalyzer("^(\\s*)?(int|double) [a-zA-Z]+( = [0-9]+)?;$");

  std::vector<int> numberOfLine;
  std::cout << std::endl;
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_match(linesVector[i], variablesAnalyzer) == true) {
      std::cout << "Variable encontrada en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      numberOfLine.push_back(i);
    }
  }

  /// These regex expressions are used to find the differents values of the variables.
  std::regex typeOfVariable("^(\\s*)?(int|double)"); /// For the type of variable.
  std::regex nameOfVariable("((int|double) [a-zA-Z]+)"); /// For the name of the variable.
  std::regex initializationComprobation("( = )"); /// For the initialization of the variable.

  std::vector<std::string> vectorResult;
  for(int i = 0; i < numberOfLine.size(); i++) {
    std::string line = linesVector[numberOfLine[i]];
    std::smatch match;
    std::regex_search(line, match, typeOfVariable);
    std::string firstPosition = match[0];
    firstPosition.erase(std::remove(firstPosition.begin(), firstPosition.end(), ' '), firstPosition.end()); /// Deleting the spaces.
    
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

    FileOperations fileOperations;
    fileOperations.WriteFile(vectorResult, true, true, fileOutName, "Variables");

    vectorResult.clear();
    firstPosition.clear();
    secondPosition.clear();
    thirdPosition.clear();
  }
};

/**
 * @brief This method is used to analyze the loops.
 * 
 * @param linesVector The vector with the lines of the code.
 * @param fileOutName The name of the output file.
 */
void CodeAnalyzer::LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName){
  std::regex loopsAnalyzer("^(\\s*)?(for|while)");

  std::vector<int> numberOfLine;
  std::vector<std::string> vectorResult;
  /// Loop counter.
  int forCounter = 0;
  int whileCounter = 0;

  std::cout << std::endl;
  std::smatch match;
  for (int i = 0; i < linesVector.size(); i++) {
    std::regex_search(linesVector[i], match ,loopsAnalyzer);
    std::string auxiliary = match[0];
    auxiliary.erase(std::remove(auxiliary.begin(), auxiliary.end(), ' '), auxiliary.end());
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

  FileOperations fileOperations;
  for (int i = 0; i < vectorResult.size(); i++) {
    std::vector<std::string> auxiliaryVector;
    std::string auxiliary;
    auxiliary = std::to_string(numberOfLine[i] + 1);
    auxiliaryVector.push_back(auxiliary);
    vectorResult[i].erase(std::remove(vectorResult[i].begin(), vectorResult[i].end(), ' '), vectorResult[i].end());
    auxiliaryVector.push_back(vectorResult[i]);
    fileOperations.WriteFile(auxiliaryVector, false, true, fileOutName, "Loops");
  }
  
  std::vector<std::string> auxiliaryVector;
  auxiliaryVector.push_back(std::to_string(forCounter));
  auxiliaryVector.push_back(std::to_string(whileCounter));
  fileOperations.WriteFile(auxiliaryVector, true,  true, fileOutName, "Loops");
};

/**
 * @brief This method is used to analyze the main fuction of the program.
 * 
 * @param linesVector The vector with the lines of the code.
 * @param fileOutName The name of the output file.
 */
void CodeAnalyzer::MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName) {
  std::regex mainProgramAnalyzer("^(\\s*)?(int|double)\\s+main\\s*\\(\\s*\\)\\s*\\{");
  std::regex mainProgramAnalyzer1("^(\\s*)?(int)\\smain\\((\\s*|[a-z A-z]*(,\\s)*[a-zA-z]*\\*?\\s[a-zA-Z]*\\[?\\]?)?\\)\\s*\\{");

  std::vector<std::string> vectorResult;
  std::cout << std::endl;
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_search(linesVector[i], mainProgramAnalyzer)) {
      std::cout << "Función main encontrada en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      std::string comprobation = "Sí";
      vectorResult.push_back(comprobation);
    }
    if (std::regex_search(linesVector[i], mainProgramAnalyzer1)) {
      std::cout << "Función main encontrada en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      std::string comprobation = "Sí";
      vectorResult.push_back(comprobation);
    }
  }
  if (vectorResult.size() == 0) {
    std::cout << "No se ha encontrado la función main." << std::endl;
    std::string comprobation = "No";
    vectorResult.push_back(comprobation);
  }
  FileOperations fileOperations;
  fileOperations.WriteFile(vectorResult, true, true, fileOutName, "Main");
};

/**
 * @brief This method is used to analyze the description comments of the program.
 * 
 * @param linesVector The vector with the lines of the code.
 * @param fileOutName The name of the output file.
 */
void CodeAnalyzer::DescriptionAnalyzer(std::vector<std::string> linesVector, std::string fileOutName) {
  std::regex descriptionAnalyzer("^(\\s*)?\\/\\*");
  std::regex descriptionAnalyzer1("^(\\s*)?\\*");
  std::regex descriptionAnalyzer2("^(\\s*)?\\*\\/");

  std::cout << std::endl;
  std::vector<std::string> vectorResult;
  bool firstLineComprobationFlag = false;
  bool finishComprobationFlag = false;
  for (int i = 0; i < linesVector.size(); i++) {
    if (finishComprobationFlag == false) {
      if (std::regex_search(linesVector[i], descriptionAnalyzer)) {
        if (i == 0) {
          firstLineComprobationFlag = true;
        }
        std::cout << "Descripción encontrada en la línea " << i + 1 << ": "
                  << linesVector[i] << std::endl;
        vectorResult.push_back(linesVector[i]);
      }
      if (firstLineComprobationFlag == true) {
        if (std::regex_search(linesVector[i], descriptionAnalyzer1)) {
          std::cout << "Descripción encontrada en la línea " << i + 1 << ": "
                    << linesVector[i] << std::endl;
          vectorResult.push_back(linesVector[i]);
        }
        if (std::regex_search(linesVector[i], descriptionAnalyzer2)) {
          std::cout << "Descripción encontrada en la línea " << i + 1 << ": "
                    << linesVector[i] << std::endl;
          vectorResult.push_back(linesVector[i]);
          finishComprobationFlag = true;
          int finalLine = i + 1;
          vectorResult.push_back(std::to_string(finalLine));
        }
      }
    }
  }

  FileOperations fileOperations;
  fileOperations.WriteFile(vectorResult, true, false, fileOutName, "Description");
};

/**
 * @brief This method is used to analyze the variables of the program.
 * 
 * @param linesVector The vector with the lines of the code.
 * @param fileOutName The name of the output file.
 */
void CodeAnalyzer::CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName) {
  std::regex commentaryAnalyzer("^(\\s*)?\\/\\/");

  std::vector<std::string> vectorResult;
  std::cout << std::endl;
  FileOperations fileOperations;
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_search(linesVector[i], commentaryAnalyzer)) {
      std::cout << "Comentario encontrado en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      vectorResult.push_back(linesVector[i]);
      int position = i + 1;
      vectorResult.push_back(std::to_string(position));
      fileOperations.WriteFile(vectorResult, true, true, fileOutName, "Comments");
      vectorResult.clear();
    }
  }
};

void CodeAnalyzer::SwitchAnalyzer(std::vector<std::string> linesVector, std::string fileOutName) {
  std::regex switchAnalyzer("^(\\s*)?switch\\s*\\(\\s*[a-zA-Z]*\\s*\\)\\s*\\{");
  std::regex caseSwitchAnalyzer("^(\\s*)?case\\s*[0-9a-zA-Z]\\s*:");
  std::regex optionSwitchName("\\([a-zA-Z]*\\)");

  std::vector<std::string> vectorResult;
  std::cout << std::endl;
  FileOperations fileOperations;
  for (int i = 0; i < linesVector.size(); i++) {
    if (std::regex_search(linesVector[i], switchAnalyzer)) {
      std::cout << "Switch encontrado en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      vectorResult.push_back(linesVector[i]);
      int position = i + 1;
      vectorResult.push_back(std::to_string(position));

      std::smatch match;
      std::string nameResult;
      std::regex_search(linesVector[i], match, optionSwitchName);
      nameResult = match.str();
      std::string finalResult;
      for (int i = 0; i < nameResult.size(); i++) {
        if (nameResult[i] != '(' && nameResult[i] != ')') {
          finalResult += nameResult[i];
        }
      }
      vectorResult.push_back(finalResult);

      fileOperations.WriteFile(vectorResult, false, true, fileOutName, "Switch");
      vectorResult.clear();
    }
    if (std::regex_search(linesVector[i], caseSwitchAnalyzer)) {
      std::cout << "Case encontrado en la línea " << i + 1 << ": " << linesVector[i] << std::endl;
      int position = i + 1;
      vectorResult.push_back(std::to_string(position));
      fileOperations.WriteFile(vectorResult, true, true, fileOutName, "Switch");
      vectorResult.clear();
    }
  }
};
