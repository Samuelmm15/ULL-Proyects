/**
 * @file FileOperations.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents the class FileOperations.
 * @version 0.1
 * @date 2022-10-19
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief This class is used to operate with files.
 * 
 */
class FileOperations {
  public:
    FileOperations();
    std::vector<std::string> ReadFile(std::string fileName);
    void WriteFile(std::vector<std::string> vectorResult, bool printFlag, bool condition, std::string fileName, std::string optionFlag);
};