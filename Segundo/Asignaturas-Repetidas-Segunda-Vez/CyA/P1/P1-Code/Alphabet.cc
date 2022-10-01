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
  if (alphabet.size() == 0) { /// En el caso de que no se introduzcan los símbolos del alfabeto y se tengan que obtener mediante la cadena de entrada
    for (int i = 0; i < line.size(); i++) {
      if (i == 0) {
        auxiliary.clear();
        auxiliary.push_back(line[i]);
        if (isASymbol(auxiliary) == true) {
          alphabet.push_back(auxiliary);
        }
        auxiliary.clear();
      } else {
        int comprobationFlag = 0;
        auxiliary.push_back(line[i]);
        for (int j = 0; j < alphabet.size(); j++) {
          if (alphabet.at(j) == auxiliary) {
            comprobationFlag = 1;
          }
        }
        if (comprobationFlag == 0) {
          if (isASymbol(auxiliary) == true) {
            alphabet.push_back(auxiliary);
          }
        }
        auxiliary.clear();
      }
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