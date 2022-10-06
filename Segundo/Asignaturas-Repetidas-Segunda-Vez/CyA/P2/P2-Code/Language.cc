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

bool Language::operator<(Chain p) {
  return true;
}

Language::Language(std::vector<Chain> groupChains) {
  std::set<Chain> setLanguage;
  setLanguage.insert(groupChains[0]);
//   for (int i = 0; i < groupChains.size(); i++) { /// De esta manera se tienen introducidas las cadenas en el lenguaje
//     chainVector.insert(groupChains[i]);
//   }
//   chainVector.insert(groupChains[0]);
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
//   std::set<Chain>::iterator it;
//   std::cout << "{ ";
//   for (it = chainVector.begin(); it != chainVector.end(); it++) {
//     std::vector<Chain> auxiliary;
//     // auxiliary.push_back(*it);
//     // std::cout << auxiliary[0].getChain() << " ";
//     auxiliary.clear();
//   }
//   std::cout << " }" << std::endl;
};