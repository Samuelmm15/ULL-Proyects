/**
 * @file Chain.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
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

Chain::~Chain() { /// To destroy de content
  chain.clear();
}

/**
 * @brief This method adds the different introduced chains by the file into a vector of chains.
 * 
 * @param newChain is the chain to introduce into the vector.
 * @param alphabet is the alphabet of the introduced chain.
 */
void Chain::addChain(std::string newChain, Alphabet alphabet) {
  chain = newChain;
  // int flagComprobation = 0;
  // if (alphabet.alphabetComprobation(newChain) == true) {
  //   chain = newChain;
  // } else {
  //   std::cout << "ERROR >> La cadena " << newChain << " no pudo haber sido generada por el alfabeto dado." << std::endl;
  //   flagComprobation = 1;
  // }
  // if (chain.size() == 0) {
  //   if ((newChain.size() >= 2) && (flagComprobation == 0)) {
  //     chain = newChain;
  //   }
  // }
};

/**
 * @brief This method returns the chain of the position given.
 * 
 * @param position is the position of the differents chain introduced.
 * @return std::string is the string that is gonna to use.
 */
std::string Chain::getChain() {
  return chain;
};