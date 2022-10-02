/**
 * @file symbol.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es).
 * @brief This is the file that contents the class that represents a symbol of a alphabet.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include<string.h>

#pragma once

/**
 * @brief This class comprobes if a character is a symbol.
 * 
 */
class Symbol {
  public:
    Symbol();
    bool isASymbol(std::string character);
};
