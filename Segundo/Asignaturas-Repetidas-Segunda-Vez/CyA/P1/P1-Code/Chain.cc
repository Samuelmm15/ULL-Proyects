/**
 * @file Chain.cc
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

#include "Chain.h"

Chain::Chain() {
};

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
  }
  }
};

std::string Chain::getChain(int position) {
  // std::cout << chain.at(position) << std::endl;
  return chain.at(position);
};