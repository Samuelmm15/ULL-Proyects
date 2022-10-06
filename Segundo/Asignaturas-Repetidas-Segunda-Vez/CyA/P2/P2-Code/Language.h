/**
 * @file language.h
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

#include <iostream>
#include <set>

#include "Chain.h"

class Language : public Chain {
  public:
    Language();
    void languageConcatenation();
    void languageUnion();
    void languageInterseccion();
    void languageSubtract();
    void languageInverse();
    void languagePotency();
  private:
    std::set<Chain> chainVector; /// Hacemos uso de set para poder almacenar las cadenas del lenguaje
};