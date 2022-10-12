/**
 * @file symbol.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents implements the differents methods of the Symbol class.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Symbol.h"

/**
 * @brief This method constructs the Symbols objects.
 * 
 */
Symbol::Symbol() {
};

/**
 * @brief This method comprobes if a introduced character is a symbol.
 * 
 * @param character This is the introduced character to comprobe.
 * @return true if the size of the character is one. It is a symbol of an alphabet.
 * @return false if the size of the character is higher than one.
 */
bool Symbol::isASymbol(std::string character) {
  if (character.size() == 1) {
    return true;
  } else {
    return false;
  }
};
