/**
 * @file FileOperations.h
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

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class FileOperations {
  public:
    FileOperations(std::string fileName);
    std::vector<std::string> ReadFile();
    void WriteFile();
  private:
    std::string inputFileName;
};