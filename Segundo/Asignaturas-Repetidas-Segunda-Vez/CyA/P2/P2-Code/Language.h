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
    std::vector<Chain> chainVector; /// Vector de objetos de tipo chain, que contiene todas las cadenas
};