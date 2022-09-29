/**
 * @file Alphabet.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contents the class that represents the alphabet of a language.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include "Symbol.h"

#pragma once

class Alphabet : public Symbol {  /// Se hereda la clase símbolo para poder comprobar si se trata de un símbolo
  public:
    Alphabet();
    void setSymbolToAlphabet(std::string line);
    bool alphabetComprobation(std::string chain);
    void printAlphabet();
  private:
    std::vector<std::string> alphabet;
};
