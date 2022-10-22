/**
 * @file CodeAnalyzer.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents the class CodeAnalyzer.
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
#include <regex>
#include <vector>

/**
 * @brief This class is used to analyze the code.
 * 
 */
class CodeAnalyzer {
 public:
   CodeAnalyzer();
   void VariablesAnalyzer(std::vector<std::string> linesVector, std::string fileOutName);
   void LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName);
   void MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName);
   void CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName);
   void DescriptionAnalyzer(std::vector<std::string> linesVector, std::string fileOutName);
};