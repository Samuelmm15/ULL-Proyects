/**
 * @file FileOperations.cc
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

#include "FileOperations.h"

FileOperations::FileOperations(){};

std::vector<std::string> FileOperations::ReadFile(std::string fileName) {
  std::ifstream fileInput(fileName);
  std::string line;
  std::vector<std::string> linesVector;
  if (fileInput.is_open()) {
    while (getline(fileInput, line)) {
      linesVector.push_back(line);
    }
    fileInput.close();
  } else {
    std::cout << "ERROR >>> " << std::endl;
    std::cout << "El fichero no se ha podido abrir." << std::endl;
    std::cout << "Compruebe si existe dicho fichero." << std::endl;
    exit(1);
  }
  return linesVector;
};

void FileOperations::WriteFile(std::string fileName){};