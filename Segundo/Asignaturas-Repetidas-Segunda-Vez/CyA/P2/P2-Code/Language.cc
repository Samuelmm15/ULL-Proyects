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

void Language::LanguageConcatenation() {
};

void Language::LanguageUnion() {
};

void Language::LanguageInterseccion() {
};

void Language::LanguageSubtract() {
};

void Language::LanguageInverse(Language languageToOperate, std::string option, std::string outputFileName) {
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
  printLanguageToFile(outputFileName, option);
};

void Language::LanguagePotency(Language languageToOperate, std::string option, std::string outputFileName) {
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
    printLanguageToFile(outputFileName, option);
  } else { /// se pasa del cero porque es la cadena vacía
    Chain operateWitchChains;
    std::vector<Chain> previousVector;
    std::vector<Chain> actualVector;
    std::vector<Chain> resultVector;
    for (int i = 1; i < nValue; i++) { /// se debe de hacer la potencia consigo mismo
      if (i == 1) {
        for (int j = auxiliaryVector.size() - 1; j >= 0; j++) {
          previousVector.push_back(auxiliaryVector[i]);
          actualVector.push_back(auxiliaryVector[i]);
        }
      } else { /// Hay que tener en cuenta que la concatenación es L * L-1
        for (int i = 0; i < actualVector.size(); i++) {
          for (int j = 0; j < previousVector.size(); j++) {
            Chain auxiliaryChainObject;
            Alphabet auxiliaryAlphabet;
            auxiliaryAlphabet.setAlphabet(actualVector[i].getAlphabet());
            std::string auxiliary;
            auxiliary = operateWitchChains.ConcatenateChain(actualVector[i].getChain(), previousVector[j].getChain());
            auxiliaryChainObject.AddChain(auxiliary, auxiliaryAlphabet);
            resultVector.push_back(auxiliaryChainObject);
          }
        }
        for (int i = 0; i < resultVector.size(); i++) {
          chainVector.insert(resultVector[i]);
        }
        printLanguageToFile(outputFileName, option);
      }
    }
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

void Language::printLanguageToFile(std::string outputFileName, std::string option) { /// SOLUCIONAR LA IMPRESIÓN POR FICHERO PARA QUE SE LIMPIE EL CONTENIDO DE LO ANTERIOR
  std::fstream outputFile;
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
};