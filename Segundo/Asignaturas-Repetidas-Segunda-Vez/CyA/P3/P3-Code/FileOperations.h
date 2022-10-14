/**
 * @file FileOperations.h
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

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "Chain.h"

/**
 * @brief This class implments operations with the file or the content of the file.
 * 
 */
class FileOperations {
  public:
    FileOperations();
    std::vector<std::string> ReadFile(std::string fileName);
    std::vector<std::string> AlphabetDivision(std::string line); /// se devuelve un vector, ya que se trata de un vector de caracteres y no una cadena
    std::vector<std::string> ChainDivision(std::string line);
  private:
    std::string inputFileName;
};