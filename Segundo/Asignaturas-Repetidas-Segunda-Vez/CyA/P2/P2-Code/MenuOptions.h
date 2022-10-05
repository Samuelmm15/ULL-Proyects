/**
 * @file MenuOptions.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contains the class of the Menu options.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Alphabet.h"
#include "Chain.h"

#pragma once

/**
 * @brief This class contains the differents methods of the differents options of the program.
 * 
 */
class MenuOptions {
  public:
    MenuOptions();
    void ChainsLong(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain);
    void InverseChains(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain);
    void PrefixesChains(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain);
    void SufixesChains(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain);
    void Substrings(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain);
};