/**
 * @file FileOperations.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-06
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "FileOperations.h"

FileOperations::FileOperations(std::string fileName) {
    inputFileName = fileName;
};

std::vector<std::string> FileOperations::ReadFile() {
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
  std::vector<std::string> fileContent; /// Almacenaje por líneas del fichero
  if (inputFile.is_open()) {
    while (getline(inputFile, line)) {
      fileContent.push_back(line);
    }
    inputFile.close();
  }
  return fileContent;
};

void FileOperations::WriteFile() {
};