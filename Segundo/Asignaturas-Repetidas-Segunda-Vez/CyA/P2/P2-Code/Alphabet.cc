/**
 * @file Alphabet.cc
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
void Alphabet::setSymbolsToAlphabet(std::vector<std::string> dividedAlphabet) {
  for (int i = 0; i < dividedAlphabet.size(); i++) { /// Introducción de los símbolos en el alfabeto del lenguaje en el caso de que sean de longitud uno
    if (dividedAlphabet[i].size() == 1) {
      alphabet.push_back(dividedAlphabet[i]);
    }
  }
};

/**
 * @brief This method prints the alphabet into the screen.
 * 
 */
void Alphabet::PrintAlphabet() {
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
bool Alphabet::AlphabetComprobation(std::string chain) {
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

void Alphabet::setAlphabet(std::vector<std::string> alphabetToIntroduce) {
  alphabet = alphabetToIntroduce;
};

std::vector<std::string> Alphabet::getAlphabet() {
  return alphabet;
};

std::string Alphabet::ChainComprobation(std::string chain) {
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