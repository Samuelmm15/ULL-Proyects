/**
 * @file Alphabet.cc
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

#include "Symbol.h"
#include "Alphabet.h"

Alphabet::Alphabet() {
};

void Alphabet::setSymbolToAlphabet(std::string line) {
  std::string auxiliary;
  for (int i = 0; i < line.size(); i++) {
    if ((line[i] != ' ') && (line[i] != '\n')) {
      auxiliary.push_back(line[i]);
    } else {
      if (line[i] != '\n') {
        if (isASymbol(auxiliary) == true) {
          alphabet.push_back(auxiliary);
        }
        auxiliary.clear();
      }
      auxiliary.clear();
    }
  }
};

void Alphabet::printAlphabet() {
    std::cout << "{ ";
  for (int i = 0; i < alphabet.size(); i++) {
    if (i != (alphabet.size() - 1)) {
      std::cout << alphabet[i] << " , ";
    } else {
      std::cout << alphabet[i];
    }
  }
  std::cout << " }" << std::endl;
};

bool Alphabet::alphabetComprobation(std::string chain) {
  bool flag;
  int counter = 0;
  for (int i = 0; i < chain.size(); i++) {
    for (int j = 0; j < alphabet.size(); j++) {
      std::string auxiliary = alphabet[j];
      if (chain[i] == auxiliary[0]) {
        counter++;
      }
    }
  }
  if (counter == chain.size()) {
    return true;
  } else {
    return false;
  }
};