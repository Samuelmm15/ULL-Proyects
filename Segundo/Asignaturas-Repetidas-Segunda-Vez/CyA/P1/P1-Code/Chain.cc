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

/// COMPROBAR SI LAS CADENAS ESTÁN FORMADAS POR SÍMBOLOS DEL ALFABETO

Chain::Chain() {
};

void Chain::addChain(std::string newChain) {
  std::string auxiliary;
  for (int i = 0; i <= (newChain.size() + 1); i++) {
    if ((newChain[i] != ' ') && (newChain[i] != '\n')) {
      auxiliary.push_back(newChain[i]);
    //   std::cout << auxiliary << std::endl;
    } else if (newChain[i] == EOF){ /// COMPROBAR CÓMO OBTENER LAS CADENAS DE MANERA INDEPENDIENTE
      std::cout << auxiliary << std::endl;
      if (newChain[i] != ' ') {
        // std::cout << auxiliary << std::endl;
        if (isASymbol(auxiliary) == false) {
          if (isACorrectChain(auxiliary) == true) {
            chain.push_back(auxiliary);
            std::cout << auxiliary << std::endl;
          }
        }
        auxiliary.clear();
      }
      auxiliary.clear();
    }
  }
};

std::string Chain::getChain(int position) {

};

bool Chain::isACorrectChain(std::string chainToComprobe) {
  if (alphabetComprobation(chainToComprobe) == true) {
    return true;
  } else {
    return false;
  }
};