/**
 * @file MenuOptions.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "MenuOptions.h"

MenuOptions::MenuOptions() {
};

void MenuOptions::ChainsLong(std::string outputFileName, int flag, Alphabet newAlphabet, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << newChain.getChain(0).size() << std::endl;
    }
    outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << newChain.getChain(0).size() << std::endl;
    }
    outputFile.close();
  }
};

void MenuOptions::InverseChains(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    std::string auxiliary;
    for (int i = newChain.getChain(0).size() - 1; i >= 0; i--) {
      auxiliary.push_back(newChain.getChain(0).at(i));
    }
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << auxiliary << std::endl;
    }
    outputFile.close();
  } else {
    std::string auxiliary;
    for (int i = newChain.getChain(0).size() - 1; i >= 0; i--) {
      auxiliary.push_back(newChain.getChain(0).at(i));
    }
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      outputFile << auxiliary << std::endl;
    }
    outputFile.close();
  }
};

void MenuOptions::PrefixesChains(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      int i = 1;
      int j = 0;
      std::string auxiliary;
      outputFile << "& ";
      outputFile << newChain.getChain(0).at(j) << " ";
      while (i != newChain.getChain(0).size()) {
        if (j < i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          j++;
        } else if (j == i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          outputFile << auxiliary << " ";
          auxiliary.clear();
          j = 0;
          i++;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      int i = 1;
      int j = 0;
      std::string auxiliary;
      outputFile << "& ";
      outputFile << newChain.getChain(0).at(j) << " ";
      while (i != newChain.getChain(0).size()) {
        if (j < i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          j++;
        } else if (j == i) {
          auxiliary.push_back(newChain.getChain(0).at(j));
          outputFile << auxiliary << " ";
          auxiliary.clear();
          j = 0;
          i++;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  }
};

void MenuOptions::SufixesChains(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      std::string auxiliary;
      int i = newChain.getChain(0).size() - 1;
      int j = 1;
      int counter = 0;
      outputFile << "& ";
      while (j <= newChain.getChain(0).size()) {
        if (i == newChain.getChain(0).size() - 1 ) {
          auxiliary.push_back(newChain.getChain(0).at(i));
          counter++;
          i--;
        } else {
          auxiliary.insert(0, 1, newChain.getChain(0).at(i));
          i--;
          counter++;
        }
        if (j == counter) {
          outputFile << auxiliary << " ";
          auxiliary.clear();
          i = newChain.getChain(0).size() - 1;
          j++;
          counter = 0;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
      std::string auxiliary;
      int i = newChain.getChain(0).size() - 1;
      int j = 1;
      int counter = 0;
      outputFile << "& ";
      while (j <= newChain.getChain(0).size()) {
        if (i == newChain.getChain(0).size() - 1 ) {
          auxiliary.push_back(newChain.getChain(0).at(i));
          counter++;
          i--;
        } else {
          auxiliary.insert(0, 1, newChain.getChain(0).at(i));
          i--;
          counter++;
        }
        if (j == counter) {
          outputFile << auxiliary << " ";
          auxiliary.clear();
          i = newChain.getChain(0).size() - 1;
          j++;
          counter = 0;
        }
      }
      outputFile << "\n";
    }
    outputFile.close();
  }
};

void MenuOptions::Substrings(std::string outputFileName, int flag, Chain newChain) {
  std::fstream outputFile;
  if (flag == 0) {
    outputFile.open(outputFileName, std::ios_base::out);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
        outputFile << "& ";
        int counterFlag = 0;
        std::string auxiliaryString;
        std::vector<std::string> auxiliaryVector;
        int i = 0;
        int j = 0;
        while (counterFlag <= newChain.getChain(0).size()) { /// Necesario para poder determinar los tamaños de las distintas subcadenas
          j = i;
          int auxiliaryLenght = 0;
          while (auxiliaryLenght <= counterFlag) { /// Este bucle se encarga de dividir la cadena en subcadenas según el tamaño del grupo que se quiera
            if (j < newChain.getChain(0).size()) {
              auxiliaryString.push_back(newChain.getChain(0).at(j));
              auxiliaryLenght = auxiliaryString.size();
            } else {
              auxiliaryLenght = counterFlag + 1;
            }
            j++;
          }
          int comprobationFlag = 0;
          for (int k = 0; k < auxiliaryVector.size(); k++) { /// En este punto se comprueba si en la división por subgrupos alguno se encuentra repetido a alguno anterior
            if (auxiliaryVector.at(k) == auxiliaryString) {
              comprobationFlag = 1;
            }
          }
          if (comprobationFlag == 0) {
            auxiliaryVector.push_back(auxiliaryString);
          }

          auxiliaryString.clear();
          i++;
          if (i == newChain.getChain(0).size()) { /// Se reinician los valores para poder seguir subiendo el tamaño de los distintos grupos
            counterFlag++;
            i = 0; /// En el momento en el que el tamaño de las subcadenas aumenta se reinicia desde la primera posición
            j = 0;  
          } 
        }
        /// Impresión de todo por pantalla
        for (int i = 0; i < auxiliaryVector.size(); i++) {
          outputFile << auxiliaryVector.at(i) << " ";
        }
        outputFile << "\n";
      }
      outputFile.close();
  } else {
    outputFile.open(outputFileName, std::ios_base::app);
    if (!outputFile.is_open()) {
      std::cout << "ERROR >>> Fallo en la apertura del fichero" << std::endl;
    } else {
        outputFile << "& ";
        int counterFlag = 0;
        std::string auxiliaryString;
        std::vector<std::string> auxiliaryVector;
        int i = 0;
        int j = 0; /// Este va a ser el auxiliar de i
        while (counterFlag <= newChain.getChain(0).size()) {
          j = i;
          int auxiliaryLenght = 0;
          while (auxiliaryLenght <= counterFlag) {
            if (j < newChain.getChain(0).size()) {
              auxiliaryString.push_back(newChain.getChain(0).at(j));
              auxiliaryLenght = auxiliaryString.size();
            } else {
              auxiliaryLenght = counterFlag + 1;
            }
            j++;
          }
          int comprobationFlag = 0;
          for (int k = 0; k < auxiliaryVector.size(); k++) {
            if (auxiliaryVector.at(k) == auxiliaryString) {
              comprobationFlag = 1;
            }
          }
          if (comprobationFlag == 0) {
            auxiliaryVector.push_back(auxiliaryString);
          }

          auxiliaryString.clear();
          i++;
          if (i == newChain.getChain(0).size()) {
            counterFlag++;
            i = 0; /// En el momento en el que el tamaño de las subcadenas aumenta se reinicia desde la primera posición
            j = 0;  
          } 
        }
        /// Impresión de todo por pantalla
        for (int i = 0; i < auxiliaryVector.size(); i++) {
          outputFile << auxiliaryVector.at(i) << " ";
        }
        outputFile << "\n";
      }
      outputFile.close();
  }
};