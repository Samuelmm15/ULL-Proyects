/**
 * @file Language.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
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

/**
 * @brief This class implements the different operations of the languages.
 * 
 */
class Language : public Chain {
  public:
    friend bool operator<(const Chain& a, const Chain& b); /// this is the overload of the operator <, neccesary to use the set structure with Chains objects.
    Language();
    void IntroduceChainsGroup(std::vector<Chain> groupChains);
    void LanguageConcatenation(Language language1, Language language2);
    void LanguageUnion(Language language1, Language language2);
    void LanguageInterseccion(Language language1, Language language2);
    void LanguageSubtract(Language language1, Language language2);
    void LanguageInverse(Language languageToOperate);
    void LanguagePotency(Language languageToOperate, int nValue);
    void ReversePolishNotation(std::string line, std::vector<Language> languageVector);
    void LanguagePrint();
    void setLanguage(std::set<Chain> languageToInsert);
    std::set<Chain> getLanguage();
    void printLanguageToFile(std::string outputFileName, bool printFlag);
  private:
    std::set<Chain> chainVector; /// Hacemos uso de set para poder almacenar las cadenas del lenguaje
};

Language operator+(Language language1, Language language2);