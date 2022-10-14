/**
 * @file FileOperations.cc
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

#include "FileOperations.h"

/**
 * @brief This is the constructor of the class.
 * 
 */
FileOperations::FileOperations() {
};

/**
 * @brief This method implements the reading of the input files.
 * 
 * @param fileName The name of the input file.
 * @return std::vector<std::string> 
 */
std::vector<std::string> FileOperations::ReadFile(std::string fileName) {
  inputFileName = fileName;
  std::ifstream inputFile;
  inputFile.open(inputFileName, std::ios::in);
  if (inputFile.fail()) {
    std::cout << "ERROR >> Fallo en la apertura del fichero de entrada." << std::endl;
    exit(1);
  }
  if (sizeof(inputFile) == 0) {
    std::cout << "ERROR >> El fichero que ha sido introducido para la entrada de datos está vacío." << std::endl;
    exit(1);
  }
  std::string line;
  std::vector<std::string> fileContent; /// Storage by lines of the file.
  if (inputFile.is_open()) {
    while (getline(inputFile, line)) {
      fileContent.push_back(line);
    }
    inputFile.close();
  }
  return fileContent;
};

/**
 * @brief This method divides the alphabet characters to use with the different languages.
 * 
 * @param line This is the line of the input File.
 * @return std::vector<std::string> 
 */
std::vector<std::string> FileOperations::AlphabetDivision(std::string line) {
  std::vector<std::string> result;
  bool comprobationFlag = false;
  for (int i = 0; i < line.size(); i++) {
    if ((line[i] != ' ') && (line[i] != '{') && (line[i] != '\n')) {
      if (line[i] == '}') {
        comprobationFlag = true;
      } else {
        if (comprobationFlag == false) {
          std::string auxiliary;
          auxiliary.push_back(line[i]);
          result.push_back(auxiliary);
        }
      }
    }
  }
  return result;
};

/**
 * @brief This method divides the different chains at the input file to introduce into de language.
 * 
 * @param line This is the line of the input file.
 * @return std::vector<std::string> 
 */
std::vector<std::string> FileOperations::ChainDivision(std::string line) {
  std::vector<std::string> result;
  std::string auxiliary;
  std::vector<std::string> returnFlag;
  bool comprobationFlag = false;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '=') {
      comprobationFlag = true;
    } else { /// Esto es una condición para que recupere únicamente las líneas que tienen lenguajes y no las operaciones
      std::string auxiliaryFlag = "-1";
      returnFlag.push_back(auxiliaryFlag);
    }
    if (comprobationFlag == true) {
      if ((line[i] != '\n') && (line[i] != '{')  && (line[i] != '=') && (line[i] != ' ')) {
        if ((line[i] != ',') && (line[i] != '}')) {
          auxiliary.push_back(line[i]);
        } else {
          result.push_back(auxiliary);
          auxiliary.clear();
        }
      }
    }
  }
  if (comprobationFlag == true) {
    return result;
  } else {
    return returnFlag;
  }
};

void FileOperations::ReversePolishNotation(std::string line) {
  /// Primero le quitamos los espacios a los distintos elementos de la línea
  std::vector<std::string> inbox;
  std::string auxiliary;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != ' ') {
      auxiliary.push_back(line[i]);
      if (i == line.size() - 1) {
        inbox.push_back(auxiliary);
        auxiliary.clear();
      }
    } else {
      inbox.push_back(auxiliary);
      auxiliary.clear();
    }
  }

  // std::cout << "Comprobación: " << std::endl;
  // for (int i = 0; i < inbox.size(); i++) {
  //   std::cout << inbox[i];
  // }
  // std::cout << std::endl;
};