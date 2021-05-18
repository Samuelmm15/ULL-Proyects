/**
 * @file nodeBB.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The implementation of a search binary tree
 * @version 0.1
 * @date 2021-05-11
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

template<class Key>
class NodeB {
    public:
    Key data;
    NodeB<Key> *left;
    NodeB<Key> *right;
    
    public:
    NodeB(Key Data) {
        data = Data;
        left = nullptr;
        right = nullptr;
    }
};

template<class Key>
class NodeAVL : public NodeB<Key> {
    public:
    NodeAVL<Key> *left;
    NodeAVL<Key> *right;
    int bal;
    
    public:
    NodeAVL(Key Data, Key bal) : NodeB<Key>(Data) {
        left = NULL;
        right = NULL;
        bal = 0;
    }
};




