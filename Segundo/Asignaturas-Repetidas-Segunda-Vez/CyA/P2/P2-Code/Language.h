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
#include <fstream>
#include <set>

#include "Chain.h"

class Language : public Chain {
  public:
    friend bool operator<(const Chain& a, const Chain& b); /// sobrecarga del operador
    Language();
    void IntroduceChainsGroup(std::vector<Chain> groupChains);
    void LanguageConcatenation(Language language1, Language language2, std::string outputFileName, bool printFlag);
    void LanguageUnion(Language language1, Language language2, std::string outputFileName, bool printFlag);
    void LanguageInterseccion(Language language1, Language language2, std::string outputFileName, bool printFlag);
    void LanguageSubtract(Language language1, Language language2, std::string outputFileName, bool printFlag);
    void LanguageInverse(Language languageToOperate, std::string outputFileName, bool printFlag);
    void LanguagePotency(Language languageToOperate, std::string outputFileName, bool printFlag);
    void LanguagePrint();
    std::set<Chain> getLanguage();
    void printLanguageToFile(std::string outputFileName, bool printFlag);
  private:
    std::set<Chain> chainVector; /// Hacemos uso de set para poder almacenar las cadenas del lenguaje
};