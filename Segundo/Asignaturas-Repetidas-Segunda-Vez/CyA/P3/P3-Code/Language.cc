/**
 * @file Language.cc
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
};

// Language operator+(Language language2) {

// };

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

void Language::LanguageConcatenation(Language language1, Language language2) {
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
      if ((auxiliaryVector1[i].getChain() != "&") && (auxiliaryVector2[j].getChain() != "&")) {
        auxiliaryResult = operateWithChains.ConcatenateChain(auxiliaryVector1[i].getChain(), auxiliaryVector2[j].getChain());
        auxiliaryChain.AddChain(auxiliaryResult,auxiliaryAlphabet);
        finalResult.push_back(auxiliaryChain);
        auxiliaryResult.clear();
      } else {
        if (auxiliaryVector1[i].getChain() == "&") {
          auxiliaryResult = auxiliaryVector2[j].getChain();
          auxiliaryChain.AddChain(auxiliaryResult,auxiliaryAlphabet);
          finalResult.push_back(auxiliaryChain);
          auxiliaryResult.clear();
        } else if (auxiliaryVector2[j].getChain() == "&") {
          auxiliaryResult = auxiliaryVector1[i].getChain();
          auxiliaryChain.AddChain(auxiliaryResult,auxiliaryAlphabet);
          finalResult.push_back(auxiliaryChain);
          auxiliaryResult.clear();
        }
      }
    }
  }
  
  for (int i = 0; i < finalResult.size(); i++) {
    chainVector.insert(finalResult[i]);
  }
};

/**
 * @brief This method implements the union of two languages.
 * 
 * @param language1 The first language to merge.
 * @param language2 The second language to merge.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageUnion(Language language1, Language language2) {
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
};

/**
 * @brief This is the implementaion of the interseccion operation.
 * 
 * @param language1 The first language to do the interseccion.
 * @param language2 The second language to do the interseccion.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageInterseccion(Language language1, Language language2) {
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
};

/**
 * @brief This is the implementation of the substract operation.
 * 
 * @param language1 This is the first language to substract.
 * @param language2 This is the second language to substract.
 * @param outputFileName The name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageSubtract(Language language1, Language language2) {
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
};

/**
 * @brief This is the implemention of the inverse language operation.
 * 
 * @param languageToOperate This is the language to operate.
 * @param outputFileName This is the name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguageInverse(Language languageToOperate) {
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
};

/**
 * @brief This is the implementation of the language potency operation.
 * 
 * @param languageToOperate This is the language to operate.
 * @param outputFileName This is the name of the output file.
 * @param printFlag The flag to use the 'in' mode or 'out' mode at the write at the file.
 */
void Language::LanguagePotency(Language languageToOperate, int nValue) {
  std::set<Chain> auxiliary = languageToOperate.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector;
  for (it = auxiliary.begin(); it != auxiliary.end(); it++) {
    auxiliaryVector.push_back(*it);
  }

  if (nValue == 0) {
    LanguagePrint();
  } else {
    Chain operateWitchChains;
    std::vector<Chain> previousVector;
    std::vector<Chain> actualVector;
    std::vector<Chain> resultVector;
    bool comprobationFlag = false;
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
            if ((actualVector[k].getChain() == "&") && (previousVector[l].getChain() != "&")) {
              auxiliary = previousVector[l].getChain();
              for (int m = 0; m < resultVector.size(); m++) {
                if (auxiliary == resultVector[m].getChain()) {
                  comprobationFlag = true;
                }
              }
              if (comprobationFlag == false) {
                auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
                resultVector.push_back(auxiliaryChainObject);
              }
              comprobationFlag = false;
            }
            if ((actualVector[k].getChain() == "&") | (previousVector[l].getChain() == "&")) {
              auxiliary = actualVector[k].getChain();
              for (int m = 0; m < resultVector.size(); m++) {
                if (auxiliary == resultVector[m].getChain()) {
                  comprobationFlag = true;
                }
              }
              if (comprobationFlag == false) {
                auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
                resultVector.push_back(auxiliaryChainObject);
              }
              comprobationFlag = false;
            }
            if ((actualVector[k].getChain() != "&") && (previousVector[l].getChain() == "&")) {
              auxiliary = actualVector[k].getChain();
              for (int m = 0; m < resultVector.size(); m++) {
                if (auxiliary == resultVector[m].getChain()) {
                  comprobationFlag = true;
                }
              }
              if (comprobationFlag == false) {
                auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
                resultVector.push_back(auxiliaryChainObject);
              }
              comprobationFlag = false;
            }
            if ((actualVector[k].getChain() != "&") && (previousVector[l].getChain() != "&")) {
              auxiliary = operateWitchChains.ConcatenateChain(actualVector[k].getChain(), previousVector[l].getChain());
              for (int m = 0; m < resultVector.size(); m++) {
                if (auxiliary == resultVector[m].getChain()) {
                  comprobationFlag = true;
                }
              }
              if (comprobationFlag == false) {
                auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
                resultVector.push_back(auxiliaryChainObject);
              }
              comprobationFlag = false;
            }
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
  }
};

void Language::ReversePolishNotation(std::string line, std::vector<Language> languageVector) {
  /// Primero le quitamos los espacios a los distintos elementos de la línea
  std::vector<std::string> inbox;
  std::string auxiliary;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != ' ') {
      auxiliary.push_back(line[i]);
      if (i == line.size() - 1) {
        inbox.push_back(auxiliary);
        auxiliary.clear();
      }
    } else {
      inbox.push_back(auxiliary);
      auxiliary.clear();
    }
  }

  std::vector<std::string> stack;
  std::vector<std::string> operands;
  std::vector<Language> partialResult;
  for (int i = 0; i < inbox.size(); i++) {
    if ((inbox[i] != "+") && (inbox[i] != "|") && (inbox[i] != "^") && (inbox[i] != "-") &&
    (inbox[i] != "!") && (inbox[i] != "*")) { /// necesario para determinar el elemento de la bandeja se trata de un operador
      stack.push_back(inbox[i]);
    } else {
      if (stack.size() > 0) { /// Para el caso de que hayan n operandos
        if ((inbox[i] == "+") | (inbox[i] == "|") | (inbox[i] == "^") | (inbox[i] == "-") | (inbox[i] == "*")) { /// SIEMPRE HAY QUE TOMAR LOS DOS ÚLTIMOS VALORES DE LA PILA
          operands.push_back(stack[stack.size() - 2]);
          operands.push_back(stack[stack.size() - 1]);
          stack.erase(stack.end());
          stack.erase(stack.end());
        } else {
          operands.push_back(stack[0]);
          stack.erase(stack.begin());
        }
        if (operands.size() >= 2) {
          if (inbox[i] == "+") {
            int counter = 0;
            char firstOperand = operands[0][1];
            char secondOperand = operands[1][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (secondOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageConcatenation(languageVector[langugePosition1 - 1], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageConcatenation(partialResult[0], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 2) {
              Language languageResult;
              languageResult.LanguageConcatenation(partialResult[0], partialResult[1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.clear();
              partialResult.push_back(languageResult);
              operands.clear();
            }
          } else if (inbox[i] == "|") {
            int counter = 0;
            char firstOperand = operands[0][1];
            char secondOperand = operands[1][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (secondOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageUnion(languageVector[langugePosition1 - 1], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageUnion(partialResult[0], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 2) {
              Language languageResult;
              languageResult.LanguageUnion(partialResult[0], partialResult[1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.clear();
              partialResult.push_back(languageResult);
              operands.clear();
            }
          } else if (inbox[i] == "^") {
            int counter = 0;
            char firstOperand = operands[0][1];
            char secondOperand = operands[1][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (secondOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageInterseccion(languageVector[langugePosition1 - 1], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageInterseccion(partialResult[0], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 2) {
              Language languageResult;
              languageResult.LanguageInterseccion(partialResult[0], partialResult[1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.clear();
              partialResult.push_back(languageResult);
              operands.clear();
            }
          } else if (inbox[i] == "-") {
            int counter = 0;
            char firstOperand = operands[0][1];
            char secondOperand = operands[1][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (secondOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageSubtract(languageVector[langugePosition1 - 1], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguageSubtract(partialResult[0], languageVector[languagePosition2 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 2) {
              Language languageResult;
              languageResult.LanguageSubtract(partialResult[0], partialResult[1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.clear();
              partialResult.push_back(languageResult);
              operands.clear();
            }
          } else if (inbox[i] == "*") {
            int counter = 0;
            char firstOperand = operands[0][1];
            char secondOperand = operands[1][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (secondOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguagePotency(languageVector[langugePosition1 - 1], languagePosition2);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              int languagePosition2 = secondOperand - '0';
              Language languageResult;
              languageResult.LanguagePotency(partialResult[0], languagePosition2);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            }
          }
        } else {
          if (inbox[i] == "!") {
            int counter = 0;
            char firstOperand = operands[0][1];
            if (firstOperand == 'R') {
              counter++;
            }
            if (counter == 0) {
              int langugePosition1 = firstOperand - '0'; /// para convertir de char a int
              Language languageResult;
              languageResult.LanguageInverse(languageVector[langugePosition1 - 1]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            } else if (counter == 1) {
              Language languageResult;
              languageResult.LanguageInverse(partialResult[0]);
              std::string languageResultString = "LR";
              stack.insert(stack.begin(), languageResultString);
              partialResult.push_back(languageResult);
              operands.clear();
            }
          }
        }
      } else { /// Para el caso de que no hayan n operandos
        std::cout << "ERROR >>> operandos insuficientes en la expresión." << std::endl;
      }
    }
  }
  if (stack.size() == 1) {
    std::cout << "El resultado final de la operación " << line << " es >>> " << std::endl;
    Language finalResultLanguage;
    finalResultLanguage = partialResult[0];
    finalResultLanguage.LanguagePrint();
    std::cout << std::endl;
  } else {
    std::cout << "ERROR >>> Expresión incorrecta." << std::endl;
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