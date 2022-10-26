/**
 * @file FileOperations.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents the implementation of the FileOperations methods.
 * @version 0.1
 * @date 2022-10-19
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FileOperations.h"

/**
 * @brief This is the constructor of the FileOperations objects.
 * 
 */
FileOperations::FileOperations(){};

/**
 * @brief This method is used to read the content of a file.
 * 
 * @param fileName The name of the input file.
 * @return std::vector<std::string> 
 */
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

/**
 * @brief This method is used to write the content of a file.
 * 
 * @param vectorResult The vector with the result of the analysis.
 * @param condition The condition to print the result with a specified format.
 * @param printFlag The condition to open the file in write mode or add mode.
 * @param fileName The name of the outpurt file.
 * @param optionFlag The option to print the result with a specified format.
 */
void FileOperations::WriteFile(std::vector<std::string> vectorResult, bool condition, bool printFlag, std::string fileName, std::string optionFlag) {
  std::fstream outputFile;
  if (printFlag == false) {
    outputFile.open(fileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> " << std::endl;
      std::cout << "El fichero no se ha podido abrir." << std::endl;
      std::cout << "Compruebe si existe dicho fichero." << std::endl;
      exit(1);
    } else {
      if (optionFlag == "Description") {
        outputFile << "DESCRIPCIÓN: " << std::endl;
        for (int i = 0; i < vectorResult.size() - 1; i++) {
          outputFile << vectorResult[i] << std::endl;
        }
        outputFile << "Descripción: [ lines 0 - " <<vectorResult[vectorResult.size() - 1] << " ];" << std::endl;
        outputFile << "\n";
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
      if (optionFlag == "Variables") {
        outputFile << "VARIABLES: " << std::endl;
        outputFile << "[ line " << vectorResult[3] << " ] "
                  << "TIPO: " << vectorResult[0]
                  << "; NOMBRE: " << vectorResult[1]
                  << "; INICIALIZACIÓN: " << vectorResult[2] << ";"
                  << std::endl;
        outputFile << "\n";
      } else if (optionFlag == "Loops") {
        if (condition == false) {
          outputFile << "BUCLES: " << std::endl;
          outputFile << "[ line " << vectorResult[0] << " ] "
                  << "TIPO: " << vectorResult[1] << ";"
                  << std::endl;
          outputFile << "\n";
        } else {
          outputFile << "BUCLES: " << std::endl;
          outputFile << "Número de bucles for: " << vectorResult[0] << ";" << std::endl;
          outputFile << "Número de bucles while: " << vectorResult[1] << ";" << std::endl;
          outputFile << "\n";
        }
      } else if (optionFlag == "Comments") {
        outputFile << "COMENTARIOS: " << std::endl;
        outputFile << "[ line " << vectorResult[1] << " ] "
                  << " COMENTARIO: " << vectorResult[0] << ";"
                  << std::endl;
      } else if (optionFlag == "Main") {
        outputFile << "MAIN: " << std::endl;
        outputFile << vectorResult[0] << ";" << std::endl;
        outputFile << "\n";
      } else if (optionFlag == "Description") {
        outputFile << "DESCRIPCIÓN: " << std::endl;
        for (int i = 0; i < vectorResult.size() - 1; i++) {
          outputFile << vectorResult[i] << std::endl;
        }
        outputFile << "Descripción: [ lines 0 - " <<vectorResult[vectorResult.size() - 1] << "];" << std::endl;
      } else if (optionFlag == "Switch") {
        if (condition == false) {
          outputFile << "\n";
          outputFile << "SWITCH: " << std::endl;
          outputFile << "[ line " << vectorResult[1] << " ] "
                  << "Opción: " << vectorResult[2] << ";"
                  << std::endl;
        } else {
          outputFile << "[ line " << vectorResult[0] << " ] "
                  << "Case" << ";"
                  << std::endl;
        }
      }
    }
  }
};