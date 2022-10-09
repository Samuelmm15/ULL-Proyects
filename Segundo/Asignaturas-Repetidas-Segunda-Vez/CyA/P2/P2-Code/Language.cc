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

bool operator<(const Chain& a, const Chain& b) { /// COMPROBAR LA SOBRECARGA DE LOS OPERADORES
  return true; /// Al introducir varios valores, si se hace uso de una comparación generaba errores
}

Language::Language() {
};

void Language::IntroduceChainsGroup(std::vector<Chain> groupChains) {
  for (int i = 0; i < groupChains.size(); i++) { /// De esta manera se tienen introducidas las cadenas en el lenguaje
    chainVector.insert(groupChains[i]);
  }

}

void Language::LanguageConcatenation(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// Obtenemos el contenido del lenguaje 1
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// Obtenemos el contenido del lenguaje 2
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

  /// Introducimos el lenguaje resultante
  for (int i = 0; i < finalResult.size(); i++) {
    chainVector.insert(finalResult[i]);
  }
  printLanguageToFile(outputFileName, printFlag);
};

void Language::LanguageUnion(Language language1, Language language2, std::string outputFileName, bool printFlag) {
  /// Obtenemos el contenido del lenguaje 1
  std::set<Chain> auxiliaryLanguage1 = language1.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector1;
  for (it = auxiliaryLanguage1.begin(); it != auxiliaryLanguage1.end(); it++) {
    auxiliaryVector1.push_back(*it);
  }
  
  /// Obtenemos el contenido del lenguaje 2
  std::set<Chain> auxiliaryLanguage2 = language2.getLanguage();
  std::set<Chain>::iterator it2;
  std::vector<Chain> auxiliaryVector2;
  for (it2 = auxiliaryLanguage2.begin(); it2 != auxiliaryLanguage2.end(); it2++) {
    auxiliaryVector2.push_back(*it2);
  }

  /// Primero se introducen como resultado todas las cadenas del primer lenguaje
  Alphabet auxiliaryAlphabet;
  auxiliaryAlphabet.setAlphabet(language1.getAlphabet());
  std::vector<Chain> auxiliaryfinalResult;
  for (int i = auxiliaryVector1.size() - 1; i >= 0; i--) {
    Chain auxiliaryChain;
    auxiliaryChain.AddChain(auxiliaryVector1[i].getChain(),auxiliaryAlphabet);
    auxiliaryfinalResult.push_back(auxiliaryChain);
  }

  /// Después se introducen las cadenas del segundo lenguaje que no se encuentren introducidas en el resultado
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

  /// Introducimos todo en el lenguaje
  for (int i = 0; i < auxiliaryfinalResult.size(); i++) {
    chainVector.insert(auxiliaryfinalResult[i]);
  }
  /// Imprimimos
  printLanguageToFile(outputFileName, printFlag);
};

void Language::LanguageInterseccion() {
};

void Language::LanguageSubtract() {
};

void Language::LanguageInverse(Language languageToOperate, std::string outputFileName, bool printFlag) {
  std::set<Chain> auxiliary = languageToOperate.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector;
  for (it = auxiliary.begin(); it != auxiliary.end(); it++) {
    auxiliaryVector.push_back(*it);
  }
  
  for (int i = auxiliaryVector.size() - 1; i >= 0; i--) { /// FALTA INTRODUCIR LOS RESULTADOS EN EL FICHERO DE SALIDA
    Chain auxiliaryObject;
    Alphabet auxiliaryAlphabet;
    auxiliaryAlphabet.setAlphabet(auxiliaryVector[i].getAlphabet());
    auxiliaryObject.AddChain(auxiliaryVector[i].InverseChain(), auxiliaryAlphabet);
    chainVector.insert(auxiliaryObject); /// Este es el lenguage resultante de la operación inversa
  }
  printLanguageToFile(outputFileName, printFlag);
};

void Language::LanguagePotency(Language languageToOperate, std::string outputFileName, bool printFlag) {
  std::set<Chain> auxiliary = languageToOperate.getLanguage();
  std::set<Chain>::iterator it;
  std::vector<Chain> auxiliaryVector;
  for (it = auxiliary.begin(); it != auxiliary.end(); it++) {
    auxiliaryVector.push_back(*it);
  }
  /// A partir de este punto se realiza la operación de potencia
  int nValue;
  std::cout << "Introduzca el valor 'n' para poder realizar la operación de potencia: ";
  std::cin >> nValue;

  if (nValue == 0) {
    printLanguageToFile(outputFileName, printFlag);
  } else { /// se pasa del cero porque es la cadena vacía
    Chain operateWitchChains;
    std::vector<Chain> previousVector;
    std::vector<Chain> actualVector;
    std::vector<Chain> resultVector;
    for (int i = 1; i <= nValue; i++) { /// se debe de hacer la potencia consigo mismo
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
      } else { /// Hay que tener en cuenta que la concatenación es L * L-1
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
        } else { /// Para actualizar los vectores anterior y actual
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

std::set<Chain> Language::getLanguage() {
  return chainVector;
};

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
      outputFile << " }" << "\n";
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