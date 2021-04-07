/**
 * @file module_hash.h
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
class Module_Hash {
    private:
        int table_size;
    public:
    /**
     * @brief The constructor of the module disperse fuction
     * 
     * @param n The size of the Hash Table
     */
    Module_Hash(const int n);
    /**
     * @brief The overload of the operator to calculate the position
     * 
     * @param x The key number that is gonna to insert
     * @return int 
     */
    int operator()(const Key &x);
};

template<class Key>
Module_Hash<Key>::Module_Hash(const int n) {
    table_size = n;
};

template<class Key>
int Module_Hash<Key>::operator()(const Key &x) {
    return (x % table_size); /// the module
};