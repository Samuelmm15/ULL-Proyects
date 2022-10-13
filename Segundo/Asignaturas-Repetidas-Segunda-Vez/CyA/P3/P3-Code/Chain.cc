/**
 * @file Chain.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file implements the methods of the Chain class.
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

/**
 * @brief Destroy the Chain:: Chain object
 * 
 */
Chain::~Chain() {
  chain.clear();
}

/**
 * @brief This method adds the different introduced chains by the file into a vector of chains.
 * 
 * @param newChain is the chain to introduce into the vector.
 * @param alphabet is the alphabet of the introduced chain.
 */
void Chain::AddChain(std::string newChain, Alphabet alphabet) {
  chain = newChain;
};

std::string Chain::InverseChain() {
  std::string result;
  if (AlphabetComprobation(chain) == true) {
    std::cout << "ERROR >> La cadena " << chain << " no está formada a partir del alfabeto de dicho lenguaje." << std::endl;
  } else {
    for (int i = chain.size() - 1; i >= 0; i--) {
      result.push_back(chain[i]);
    }
  }
  return result;
}

/**
 * @brief This is the chain operation that concatenates two introduced chains.
 * 
 * @param firstChain Is the first chain to concatenate.
 * @param secondChain Is the second chain to concatenate.
 * @return std::string 
 */
std::string Chain::ConcatenateChain(std::string firstChain, std::string secondChain) {
  for (int i = 0; i < secondChain.size(); i++) {
    firstChain.push_back(secondChain[i]);
  }
  return firstChain;
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