/**
 * @file language.cc
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

#include "Language.h"

bool operator<(const Chain& a, const Chain& b) {
  return a < b;
}

Language::Language(std::vector<Chain> groupChains) {
  // for (int i = 0; i < groupChains.size(); i++) { /// De esta manera se tienen introducidas las cadenas en el lenguaje
  //   std::cout << "Antes" << " ";
  //   chainVector.insert(groupChains[i]);
  //   std::cout << "Recorre" << " ";
  // }
  // int i = 0;
  // while (i < groupChains.size()) {
  //   chainVector.insert(groupChains[i]);
  //   i++;
  // }
  chainVector.insert(groupChains[0]);
  chainVector.insert(groupChains[1]); /// Da error en este punto al introducir varios valores en el set
  // chainVector.insert(groupChains[1]);
  // chainVector.insert(groupChains[2]);
  // chainVector.insert(groupChains[3]);
};

void Language::LanguageConcatenation() {
};

void Language::LanguageUnion() {
};

void Language::LanguageInterseccion() {
};

void Language::LanguageSubtract() {
};

void Language::LanguageInverse() {
};

void Language::LanguagePotency() {
};

void Language::LanguagePrint() {
  std::set<Chain>::iterator it;
  std::cout << "{ ";
  for (it = chainVector.begin(); it != chainVector.end(); it++) {
    std::vector<Chain> auxiliary;
    auxiliary.push_back(*it);
    std::cout << auxiliary[0].getChain() << " ,";
    auxiliary.clear();
  }
  std::cout << " }" << std::endl;
};