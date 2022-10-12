/**
 * @file Alphabet.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the implementation of the different methods of the alphabet class.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Alphabet.h"

/**
 * @brief This is the constructor of the different Alphabet objects.
 * 
 */
Alphabet::Alphabet() {
};

/**
 * @brief This method sets a symbol into the alphabet of the introduced example.
 * 
 * @param line This is the readed line of the introduced file to obtain the alphabet of the differents chains.
 */
void Alphabet::setSymbolToAlphabet(std::string line) {
  std::string auxiliary;
  for (int i = 0; i < line.size(); i++) {
    if ((line[i] != ' ') && (line[i] != '\n')) { /// When the character is not followed by a space or line break.
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
  if (alphabet.size() == 0) { /// At the case that the alphabet is not introduced in the file. The alphabet is obtained by the different symbols at the chain.
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
        for (int j = 0; j < alphabet.size(); j++) { /// This is a comprobation if the introduced symbol is already introduced in it.
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

/**
 * @brief This method prints the alphabet into the screen.
 * 
 */
void Alphabet::printAlphabet() {
    std::cout << "{ ";
  for (int i = 0; i < alphabet.size(); i++) {
    if (i != (alphabet.size() - 1)) {
      std::cout << alphabet[i] << " , ";
    } else {
      std::cout << alphabet[i];
    }
  }
  std::cout << " } " << " ";
};

/**
 * @brief This method comprobes if a chain belongs at the alphabet.
 * 
 * @param chain is the chain to comprobe.
 * @return true if the chain was formed by the alphabet.
 * @return false if the chain was not formed by the alphabet.
 */
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

std::vector<std::string> Alphabet::getAlphabet() {
  return alphabet;
};

std::string Alphabet::chainComprobation(std::string chain) {
  std::string chainResult;
  for (int i = 0; i < chain.size(); i++) {
    for (int j = 0; j < alphabet.size(); j++) {
      std::string auxiliary = alphabet[j];
      if (chain[i] == auxiliary[0]) {
        if (chainResult.size() == 0) {
          chainResult.push_back(chain[i]);
        } else {
          int counter = 0;
          for (int k = 0; k < chainResult.size(); k++) {
            if (chain[i] == chainResult[k]) {
              counter = 1;
            }
          }
          if (counter == 0) {
            chainResult.push_back(chain[i]);
          }
        }
      }
    }
  }
  return chainResult;
}