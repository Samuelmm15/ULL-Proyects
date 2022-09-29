/**
 * @file symbol.cc
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

#include "Symbol.h"

Symbol::Symbol() {
};

bool Symbol::isASymbol(std::string character) {
  if (character.size() == 1) {
    return true;
  } else {
    return false;
  }
};
