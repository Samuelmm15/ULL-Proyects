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

void FileOperations::WriteFile(std::vector<std::string> vectorResult, bool condition, bool printFlag, std::string fileName, std::string OptionFlag) {
  std::fstream outputFile;
  if (printFlag == false) {
    outputFile.open(fileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> " << std::endl;
      std::cout << "El fichero no se ha podido abrir." << std::endl;
      std::cout << "Compruebe si existe dicho fichero." << std::endl;
      exit(1);
    } else {
      if (OptionFlag == "Variables") {
        outputFile << "VARIABLES: " << std::endl;
        outputFile << "[ line " << vectorResult[3] << " ] "
                  << "TIPO: " << vectorResult[0]
                  << "; NOMBRE: " << vectorResult[1]
                  << "; INICIALIZACIÓN: " << vectorResult[2] << ";"
                  << std::endl;
      } else if (OptionFlag == "Loops") {
        outputFile << "BUCLES: " << std::endl;
        outputFile << "[ line " << vectorResult[0] << " ] "
                  << "TIPO: " << vectorResult[1]
                  << std::endl;
      } else if (OptionFlag == "Comments") {
        for (int i = 0; i < vectorResult.size(); i++) {
          outputFile << vectorResult[i] << std::endl;
        }
      } else if (OptionFlag == "Main") {
        for (int i = 0; i < vectorResult.size(); i++) {
          outputFile << vectorResult[i] << std::endl;
        }
      }
    }
  } else {
    outputFile.open(fileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> " << std::endl;
      std::cout << "El fichero no se ha podido abrir." << std::endl;
      std::cout << "Compruebe si existe dicho fichero." << std::endl;
      exit(1);
    } else {
      if (OptionFlag == "Variables") {
        outputFile << "VARIABLES: " << std::endl;
        outputFile << "[ line " << vectorResult[3] << " ] "
                  << "TIPO: " << vectorResult[0]
                  << "; NOMBRE: " << vectorResult[1]
                  << "; INICIALIZACIÓN: " << vectorResult[2] << ";"
                  << std::endl;
      } else if (OptionFlag == "Loops") {
        if (condition == false) {
          outputFile << "BUCLES: " << std::endl;
          outputFile << "[ line " << vectorResult[0] << " ] "
                  << "TIPO: " << vectorResult[1] << ";"
                  << std::endl;
        } else {
          outputFile << "BUCLES: " << std::endl;
          outputFile << "Número de bucles for: " << vectorResult[0] << ";" << std::endl;
          outputFile << "Número de bucles while: " << vectorResult[1] << ";" << std::endl;
        }
      } else if (OptionFlag == "Comments") {
        for (int i = 0; i < vectorResult.size(); i++) {
          outputFile << vectorResult[i] << std::endl;
        }
      } else if (OptionFlag == "Main") {
        outputFile << "MAIN: " << std::endl;
        outputFile << vectorResult[0] << ";" << std::endl;
      }
    }
  }
};