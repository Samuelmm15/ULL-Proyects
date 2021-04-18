/**
 * @file insertion.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This program presents an implementation of three algorithms of sort
 * @version 0.1
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/// This coments help me to understand the functions of the differents librarys
#include <iostream> /// the main library of the program
#include <fstream> /// the library to read and write text files
#include <stdlib.h> /// the library to use exit(1);
#include <string.h> /// the library to operate with strings
#include <vector> /// the library to do a vector with strings
#include <algorithm> /// the library to use the iterator
#include <cctype> /// the library to use toupper or tolower
#include <sstream> /// library to use the convertors of strings and numbers (istringstream or ostringstream)
#include <list> /// library to use the class list

#pragma once
using namespace std;

template<typename Key> Key Vector_Sort(vector<Key> &sec, Key number_cells);

template<typename Key>
Key Vector_Sort(vector<Key> &sec, Key i_sec) { /// FALTA LA DECLARACIÓN DEL CÓDIGO
    return i_sec = sec.size();
};

template<typename Key>
class Insertion {
    private:
    vector<Key> sec;
    public:
    void Insertion_Comparation(vector<Key> &vector_sort, char ejecution_trace);
    void The_Insertion(vector<Key> &sec, int i_sec, int x_sec);
};

template<typename Key>
void Insertion<Key>::Insertion_Comparation(vector<Key> &vector_sort, char ejecution_trace) {
    if (ejecution_trace == 's') {

    } else if (ejecution_trace == 'n') {
        sec.push_back(vector_sort.at(0)); /// establecemos el valor con el que se comienza la ordenación
        int i_sec = 0;
        int x_sec = 0;
        for (int i = 0; i < vector_sort.size(); i++) {
            i_sec = sec.size();
            x_sec = vector_sort.at(i + 1);
            The_Insertion(sec, i_sec, x_sec);
        }

        for (int i = 0; i < sec.size(); i++) {
            cout << sec.at(i) << " ";
        }
    }
};

template<typename Key>
void Insertion<Key>::The_Insertion(vector<Key> &sec, int i_sec, int x_sec) {
    int j = 0;
    while (x_sec < sec.at(j)) { /// con esto determinamos la posición j dónde el valor va a ser introducido
        j++;
    }

    for (int k = i_sec - 1; k >= j; k--) { /// con esto introducimos el valor a la secuencia ordenada
        sec.erase(sec.begin() + k + 1);
        sec.insert(sec.begin() + k + 1, sec.at(k));
        
        sec.erase(sec.begin() + j);
        sec.insert(sec.begin() + j, x_sec);
    }
};