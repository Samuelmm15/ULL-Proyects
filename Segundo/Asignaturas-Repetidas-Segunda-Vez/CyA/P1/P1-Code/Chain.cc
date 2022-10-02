/**
 * @file Chain.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contents the different methods implementation of the chain class.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Chain.h"

/**
 * @brief This is the constructor of the chains objects.
 * 
 */
Chain::Chain() {
};

/**
 * @brief This method adds the different introduced chains by the file into a vector of chains.
 * 
 * @param newChain is the chain to introduce into the vector.
 * @param alphabet is the alphabet of the introduced chain.
 */
void Chain::addChain(std::string newChain, Alphabet alphabet) {
  std::string auxiliary;
  for (int i = 0; i < newChain.size(); i++) {
    if (newChain[i] != ' ') {
      auxiliary.push_back(newChain[i]);
    } else {
      auxiliary.clear();
    }
  }
  int flagComprobation = 0;
  if (alphabet.alphabetComprobation(auxiliary) == true) {
    chain.push_back(auxiliary);
  } else {
    std::cout << "ERROR >> La cadena " << auxiliary << " no pudo haber sido generada por el alfabeto dado." << std::endl;
    flagComprobation = 1;
  }
  if (chain.size() == 0) {
    if ((auxiliary.size() >= 2) && (flagComprobation == 0)) {
    chain.push_back(auxiliary);
    } else {
      chain.push_back("-1"); /// This is a flag to express that the string does not belong to the alphabet given.
    }
  }
};

/**
 * @brief This method returns the chain of the position given.
 * 
 * @param position is the position of the differents chain introduced.
 * @return std::string is the string that is gonna to use.
 */
std::string Chain::getChain(int position) {
  return chain.at(position);
};