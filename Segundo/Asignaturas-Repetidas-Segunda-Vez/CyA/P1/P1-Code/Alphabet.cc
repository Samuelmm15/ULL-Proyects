/**
 * @file Alphabet.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Alphabet.h"

Alphabet::Alphabet() {
};

void Alphabet::setSymbolToAlphabet(std::string symbol) {
  if (isASymbol(symbol) == true) {
    alphabet.push_back(symbol);
  }
};

std::vector<std::string> Alphabet::getAlphabet() {
  return alphabet;
};