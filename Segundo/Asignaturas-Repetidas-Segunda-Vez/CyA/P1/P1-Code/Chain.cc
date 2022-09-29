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

Chain::~Chain() {
  chain.clear();
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
  if (alphabet.alphabetComprobation(auxiliary) == true) {
    chain.push_back(auxiliary);
  }
};

std::string Chain::getChain(int position) {
  // std::cout << chain.at(position) << std::endl;
  return chain.at(position);
};