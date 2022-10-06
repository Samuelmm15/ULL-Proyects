/**
 * @file Alphabet.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

#pragma once

/**
 * @brief This class contains the different alphabets of the introduced file.
 * 
 */
class Alphabet {
  public:
    Alphabet();
    void setSymbolsToAlphabet(std::vector<std::string> dividedAlphabet);
    bool alphabetComprobation(std::string chain);
    void printAlphabet();
    std::vector<std::string> getAlphabet();
    std::string chainComprobation(std::string chain);
  private:
    std::vector<std::string> alphabet;
};
