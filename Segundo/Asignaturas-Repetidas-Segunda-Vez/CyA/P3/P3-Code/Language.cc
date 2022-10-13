/**
 * @file language.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file implements the different language methods.
 * @version 0.1
 * @date 2022-10-05
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Language.h"

/**
 * @brief This is the overload of the operator '<' to use the set structure with Chain objects.
 * 
 * @param a The first chain to comprobe.
 * @param b The second chain to comprobe.
 * @return true 
 * @return false 
 */
bool operator<(const Chain& a, const Chain& b) {
  return true;
}

/**
 * @brief This is the constructor of the class
 * 
 */
Language::Language() {
};

/**
 * @brief This method introduces the different chains into the set structure.
 * 
 * @param groupChains The group of chains of the Language.
 */
void Language::IntroduceChainsGroup(std::vector<Chain> groupChains) {
  for (int i = 0; i < groupChains.size(); i++) {
    chainVector.insert(groupChains[i]);
  }
}

/**
 * @brief This method concatenates two introduced languages.
 * 
 * @param language1 The first language to concatenate.
 * @param language2 The second language to concatenate.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageConcatenation(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// The content of the first language.
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// The content of the second language.
  std::set<Chain> auxiliaryLanguage2 = language2.getLanguage();
  std::set<Chain>::iterator it2;
  std::vector<Chain> auxiliaryVector2;
  for (it2 = auxiliaryLanguage2.begin(); it2 != auxiliaryLanguage2.end(); it2++) {
    auxiliaryVector2.push_back(*it2);
  }

  Chain operateWithChains;
  Alphabet auxiliaryAlphabet;
  auxiliaryAlphabet.setAlphabet(language1.getAlphabet());
  std::string auxiliaryResult;
  std::vector<Chain> finalResult;
  for (int i = auxiliaryVector1.size() - 1; i >= 0; i--) {
    for (int j = auxiliaryVector2.size() - 1; j >= 0; j--) {
      Chain auxiliaryChain;
      auxiliaryResult = operateWithChains.ConcatenateChain(auxiliaryVector1[i].getChain(), auxiliaryVector2[j].getChain());
      auxiliaryChain.AddChain(auxiliaryResult,auxiliaryAlphabet);
      finalResult.push_back(auxiliaryChain);
      auxiliaryResult.clear();
    }
  }

  for (int i = 0; i < finalResult.size(); i++) {
    chainVector.insert(finalResult[i]);
  }
  printLanguageToFile(outputFileName, printFlag);
};

/**
 * @brief This method implements the union of two languages.
 * 
 * @param language1 The first language to merge.
 * @param language2 The second language to merge.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageUnion(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// The content of the first language.
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// The content of the second language.
  std::set<Chain> auxiliaryLanguage2 = language2.getLanguage();
  std::set<Chain>::iterator it2;
  std::vector<Chain> auxiliaryVector2;
  for (it2 = auxiliaryLanguage2.begin(); it2 != auxiliaryLanguage2.end(); it2++) {
    auxiliaryVector2.push_back(*it2);
  }

  /// First, the introduction of all the chains of the first language.
  Alphabet auxiliaryAlphabet;
  auxiliaryAlphabet.setAlphabet(language1.getAlphabet());
  std::vector<Chain> auxiliaryfinalResult;
  for (int i = auxiliaryVector1.size() - 1; i >= 0; i--) {
    Chain auxiliaryChain;
    auxiliaryChain.AddChain(auxiliaryVector1[i].getChain(),auxiliaryAlphabet);
    auxiliaryfinalResult.push_back(auxiliaryChain);
  }

  /// Then introduce the chains of the second language that not have the first language.
  bool comparationFlag = false;
  for (int i = auxiliaryVector2.size() - 1; i >= 0; i--) {
    for (int j = 0; j < auxiliaryfinalResult.size(); j++) {
      if (auxiliaryVector2[i].getChain() == auxiliaryfinalResult[j].getChain()) {
        comparationFlag = true;
      }
    }
    if (comparationFlag != true) {
        Chain auxiliaryChain;
        auxiliaryChain.AddChain(auxiliaryVector2[i].getChain(),auxiliaryAlphabet);
        auxiliaryfinalResult.push_back(auxiliaryChain);
      }
      comparationFlag = false;
  }

  for (int i = 0; i < auxiliaryfinalResult.size(); i++) {
    chainVector.insert(auxiliaryfinalResult[i]);
  }
  printLanguageToFile(outputFileName, printFlag);
};

/**
 * @brief This is the implementaion of the interseccion operation.
 * 
 * @param language1 The first language to do the interseccion.
 * @param language2 The second language to do the interseccion.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageInterseccion(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// The content of the first language
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// The content of the second language
  std::set<Chain> auxiliaryLanguage2 = language2.getLanguage();
  std::set<Chain>::iterator it2;
  std::vector<Chain> auxiliaryVector2;
  for (it2 = auxiliaryLanguage2.begin(); it2 != auxiliaryLanguage2.end(); it2++) {
    auxiliaryVector2.push_back(*it2);
  }

  /// Comparation of the chains of the two languages
  Alphabet auxiliaryAlphabet;
  auxiliaryAlphabet.setAlphabet(language1.getAlphabet());
  std::vector<Chain> auxiliaryfinalResult;
  bool comprobationFlag = false;
  for (int i = auxiliaryVector1.size() - 1; i >= 0; i--) {
    for (int j = auxiliaryVector2.size() - 1; j >= 0; j--) {
      if (auxiliaryVector1[i].getChain() == auxiliaryVector2[j].getChain()) {
        comprobationFlag = true;
      }
    }
    if (comprobationFlag == true) {
      Chain auxiliaryChain;
      auxiliaryChain.AddChain(auxiliaryVector1[i].getChain(),auxiliaryAlphabet);
      auxiliaryfinalResult.push_back(auxiliaryChain);
    }
    comprobationFlag = false;
  }

  for (int i = 0; i < auxiliaryfinalResult.size(); i++) {
    chainVector.insert(auxiliaryfinalResult[i]);
  }
  printLanguageToFile(outputFileName, printFlag);
};

/**
 * @brief This is the implementation of the substract operation.
 * 
 * @param language1 This is the first language to substract.
 * @param language2 This is the second language to substract.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageSubtract(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// The content of the first language
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// The content of the second language
  std::set<Chain> auxiliaryLanguage2 = language2.getLanguage();
  std::set<Chain>::iterator it2;
  std::vector<Chain> auxiliaryVector2;
  for (it2 = auxiliaryLanguage2.begin(); it2 != auxiliaryLanguage2.end(); it2++) {
    auxiliaryVector2.push_back(*it2);
  }

  /// Comparation of the two languages
  Alphabet auxiliaryAlphabet;
  auxiliaryAlphabet.setAlphabet(language1.getAlphabet());
  std::vector<Chain> auxiliaryfinalResult;
  bool comprobationFlag = false;
  for (int i = auxiliaryVector1.size() - 1; i >= 0; i--) {
    for (int j = auxiliaryVector2.size() - 1; j >= 0; j--) {
      if (auxiliaryVector1[i].getChain() == auxiliaryVector2[j].getChain()) {
        comprobationFlag = true;
      }
    }
    if (comprobationFlag == false) {
      Chain auxiliaryChain;
      auxiliaryChain.AddChain(auxiliaryVector1[i].getChain(),auxiliaryAlphabet);
      auxiliaryfinalResult.push_back(auxiliaryChain);
    }
    comprobationFlag = false;
  }

  for (int i = 0; i < auxiliaryfinalResult.size(); i++) {
    chainVector.insert(auxiliaryfinalResult[i]);
  }
  printLanguageToFile(outputFileName, printFlag);
};

/**
 * @brief This is the implemention of the inverse language operation.
 * 
 * @param languageToOperate This is the language to operate.
 * @param outputFileName This is the name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageInverse(Language languageToOperate, std::string outputFileName, bool printFlag) {
  std::set<Chain> auxiliary = languageToOperate.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector;
  for (it = auxiliary.begin(); it != auxiliary.end(); it++) {
    auxiliaryVector.push_back(*it);
  }
  
  for (int i = auxiliaryVector.size() - 1; i >= 0; i--) {
    Chain auxiliaryObject;
    Alphabet auxiliaryAlphabet;
    auxiliaryAlphabet.setAlphabet(auxiliaryVector[i].getAlphabet());
    auxiliaryObject.AddChain(auxiliaryVector[i].InverseChain(), auxiliaryAlphabet);
    chainVector.insert(auxiliaryObject); /// This is the result of the inverse chain operation.
  }
  printLanguageToFile(outputFileName, printFlag);
};

/**
 * @brief This is the implementation of the language potency operation.
 * 
 * @param languageToOperate This is the language to operate.
 * @param outputFileName This is the name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguagePotency(Language languageToOperate, std::string outputFileName, bool printFlag) {
  std::set<Chain> auxiliary = languageToOperate.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector;
  for (it = auxiliary.begin(); it != auxiliary.end(); it++) {
    auxiliaryVector.push_back(*it);
  }
  
  int nValue;
  std::cout << "Introduzca el valor 'n' para poder realizar la operación de potencia: ";
  std::cin >> nValue;

  if (nValue == 0) {
    printLanguageToFile(outputFileName, printFlag);
  } else {
    Chain operateWitchChains;
    std::vector<Chain> previousVector;
    std::vector<Chain> actualVector;
    std::vector<Chain> resultVector;
    for (int i = 1; i <= nValue; i++) {
      if (i == 1) { /// initialization
        for (int j = auxiliaryVector.size() - 1; j >= 0; j--) {
          previousVector.push_back(auxiliaryVector[j]);
          actualVector.push_back(auxiliaryVector[j]);
        }
        if (i == nValue) {
          for (int i = 0; i < actualVector.size(); i++) { /// To print the result
            chainVector.insert(actualVector[i]);
          }
        }
      } else { /// The concatenation is L * Ln-1
        int previousFlag = 0;
        for (int k = 0; k < actualVector.size(); k++) {
          for (int l = 0; l < previousVector.size(); l++) {
            Chain auxiliaryChainObject;
            Alphabet auxiliaryAlphabet;
            auxiliaryAlphabet.setAlphabet(actualVector[k].getAlphabet());
            std::string auxiliary;
            auxiliary = operateWitchChains.ConcatenateChain(actualVector[k].getChain(), previousVector[l].getChain());
            auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
            resultVector.push_back(auxiliaryChainObject);
          }
        }
        if (i == nValue) {
          for (int i = 0; i < resultVector.size(); i++) { /// To print the result
            chainVector.insert(resultVector[i]);
          }
        } else {
          if (previousFlag == 1) {
            previousVector.clear();
            for (int i = 0; i < actualVector.size(); i++) {
              previousVector.push_back(actualVector[i]);
            }
            actualVector.clear();
            for (int i = 0; i < resultVector.size(); i++) {
              actualVector.push_back(resultVector[i]);
            }
            resultVector.clear();
            previousFlag = 0;
          } else {
            actualVector.clear();
            for (int i = 0; i < resultVector.size(); i++) {
              actualVector.push_back(resultVector[i]);
            }
            resultVector.clear();
            previousFlag = 1;
        }
          }
      }
    }
    printLanguageToFile(outputFileName, printFlag);
  }
};

/**
 * @brief This method prints the language into the screen.
 * 
 */
void Language::LanguagePrint() {
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliary;
  for (it = chainVector.begin(); it != chainVector.end(); it++) {
    auxiliary.push_back(*it);
  }
  std::cout << "{ ";
  for (int i = auxiliary.size() - 1; i >= 0; i--) { /// La impresión se hace de manera inversa, debido a que el set se encuentra introducido de manera inversa
    if (i != 0) {
      std::cout << auxiliary[i].getChain() << " , ";
    } else {
      std::cout << auxiliary[i].getChain();
    }
  }
  std::cout << " }" << std::endl;
};

/**
 * @brief This method returns the language of the object.
 * 
 * @return std::set<Chain> 
 */
std::set<Chain> Language::getLanguage() {
  return chainVector;
};

/**
 * @brief This method prints the language result into the output File
 * 
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::printLanguageToFile(std::string outputFileName, bool printFlag) {
  std::fstream outputFile;
  if (printFlag == true) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << "{ ";
      std::set<Chain>::iterator it;
      std::vector<Chain> auxiliaryVector;
      for (it = chainVector.begin(); it != chainVector.end(); it++) {
        auxiliaryVector.push_back(*it);
      }
      for (int i = auxiliaryVector.size() - 1; i >= 0; i--) {
        if (i != 0) {
          outputFile << auxiliaryVector[i].getChain() << " , ";
        } else {
          outputFile << auxiliaryVector[i].getChain() << " ";
        }
      }
      outputFile << "}" << "\n";
    }
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << "{ ";
      std::set<Chain>::iterator it;
      std::vector<Chain> auxiliaryVector;
      for (it = chainVector.begin(); it != chainVector.end(); it++) {
        auxiliaryVector.push_back(*it);
      }
      for (int i = auxiliaryVector.size() - 1; i >= 0; i--) {
        if (i != 0) {
          outputFile << auxiliaryVector[i].getChain() << " , ";
        } else {
          outputFile << auxiliaryVector[i].getChain() << " ";
        }
      }
      outputFile << " }" << "\n";
    }
  }
};