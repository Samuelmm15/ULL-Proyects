/**
 * @file Chain.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contents the class that represents a chain of a language.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "Alphabet.h"

#pragma once

class Chain : public Alphabet {
  public:
    Chain();
    ~Chain();
    void addChain(std::string newChain, Alphabet alphabet);
    std::string getChain(int position);
  private:
    std::vector<std::string> chain;
};
