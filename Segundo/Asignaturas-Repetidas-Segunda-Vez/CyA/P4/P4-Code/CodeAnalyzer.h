/**
 * @file CodeAnalyzer.h
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

#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>

class CodeAnalyzer {
 public:
   CodeAnalyzer();
   void VariablesAnalyzer(std::vector<std::string> linesVector, std::string fileOutName); /// Función para analizar únicamente las variables del código introducido.
   void LoopsAnalyzer(std::vector<std::string> linesVector, std::string fileOutName); /// Función para analizar únicamente los bucles del código introducido.
   void MainProgramAnalyzer(std::vector<std::string> linesVector, std::string fileOutName); /// Función para analizar únicamente el programa principal del código introducido.
   void CommentaryAnalyzer(std::vector<std::string> linesVector, std::string fileOutName); /// Función para analizar únicamente los comentarios del código introducido.
};