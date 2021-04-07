/**
 * @file pseudorandom_hash.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The hash table is a tool for the handing and storage of data in secondary memory
 * @version 0.1
 * @date 2021-04-02
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
#include "dispersion_fuction.h"

#pragma once
using namespace std;

template<class Key>
class Pseudorandom_Hash {
    private: 
    int table_size;
    public:
    Pseudorandom_Hash(const int n);
    ~Pseudorandom_Hash();
    int operator()(const Key &x);
};

template<class Key>
Pseudorandom_Hash<Key>::Pseudorandom_Hash(const int n) {
    table_size = n;
};

template<class Key>
Pseudorandom_Hash<Key>::~Pseudorandom_Hash() {

};

template<class Key>
int Pseudorandom_Hash<Key>::operator()(const Key &x) {
    srand(x);
        return (rand() % table_size);
};