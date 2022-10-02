/**
 * @file MenuOptions.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the implementation of the differents methods of the different options of the program.
 * @version 0.1
 * @date 2022-09-28
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "MenuOptions.h"

/**
 * @brief This is the constructor of the MenuOptions objects.
 * 
 */
MenuOptions::MenuOptions() {
};

/**
 * @brief This is the option that brings the size of the different introduced chains at the introduced file.
 * 
 * @param outputFileName is the name of the file that is gonna to write the result.
 * @param flag is a flag to determinate if the file is gonna be open to write the first time or to write lines below the previous line.
 * @param newAlphabet is the object of the chain alphabet.
 * @param newChain is the object of the chain.
 */
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

/**
 * @brief This is the option that write the inverse of the introduced chains.
 * 
 * @param outputFileName is the name of the file that contains the results.
 * @param flag is a flag to determinate if the file is gonna be open to write the first time or to write lines below the previous line.
 * @param newChain is the object of the introduced chain.
 */
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

/**
 * @brief This option write the prefixes of the different introduced chains.
 * 
 * @param outputFileName is the name of the file that contains the results.
 * @param flag is a flag to determinate if the file is gonna be open to write the first time or to write lines below the previous line.
 * @param newChain is the object of the introduced chain.
 */
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

/**
 * @brief This option wirte the sufixes of the differents introduced chains.
 * 
 * @param outputFileName is the name of the file that is gonna write the result.
 * @param flag is a flag to determinate if the file is gonna be open to write the first time or to write lines below the previous line.
 * @param newChain is the object of the introduced chains.
 */
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

/**
 * @brief This option write the differents substrings of the introduced chains.
 * 
 * @param outputFileName is the name of the file that is gonna to write the results.
 * @param flag is a flag to determinate if the file is gonna be open to write the first time or to write lines below the previous line.
 * @param newChain is the object of the introduced chains.
 */
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
        while (counterFlag <= newChain.getChain(0).size()) { /// This is neccesary to obtain the different sizes of the differents substrings.
          j = i;
          int auxiliaryLenght = 0;
          while (auxiliaryLenght <= counterFlag) { /// this loop is responsible for dividing the chain into substrings according to the size of the group you want.
            if (j < newChain.getChain(0).size()) {
              auxiliaryString.push_back(newChain.getChain(0).at(j));
              auxiliaryLenght = auxiliaryString.size();
            } else {
              auxiliaryLenght = counterFlag + 1;
            }
            j++;
          }
          int comprobationFlag = 0;
          for (int k = 0; k < auxiliaryVector.size(); k++) { /// This comprobe if a substring is already introduced into the vector.
            if (auxiliaryVector.at(k) == auxiliaryString) {
              comprobationFlag = 1;
            }
          }
          if (comprobationFlag == 0) {
            auxiliaryVector.push_back(auxiliaryString);
          }

          auxiliaryString.clear();
          i++;
          if (i == newChain.getChain(0).size()) { /// At this point the variables are restarted.
            counterFlag++;
            i = 0;
            j = 0;  
          } 
        }
        
        for (int i = 0; i < auxiliaryVector.size(); i++) { /// This prints all into the output file.
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
        int j = 0;
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
            i = 0;
            j = 0;  
          } 
        }

        for (int i = 0; i < auxiliaryVector.size(); i++) {
          outputFile << auxiliaryVector.at(i) << " ";
        }
        outputFile << "\n";
      }
      outputFile.close();
  }
};