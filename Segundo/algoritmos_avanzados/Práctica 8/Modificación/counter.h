/**
 * @file counter.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This program presents an implementation of three algorithms of sort
 * @version 0.1
 * @date 2021-04-29
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

template<typename Key>
class Counter {
    private:
    int counter = 0;
    public:
    int operator< (const int);
    int operator> (const int);
    int operator== (const int);
    int operator<= (const int);
    int operator>= (const int);
    int print();
};

template<typename Key>
int Counter<Key>::operator< (const int) {
    counter++;
};

template<typename Key>
int Counter<Key>::operator> (const int) {
    counter++;
};

template<typename Key>
int Counter<Key>::operator== (const int) {
    counter++;
};

template<typename Key>
int Counter<Key>::operator<= (const int) {
    counter++;
};

template<typename Key>
int Counter<Key>::operator>= (const int) {
    counter++;
};

template<typename Key>
int Counter<Key>::print() {
    return counter;
    counter = 0;
};