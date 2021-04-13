/**
 * @file vector_hash_table.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The hash table is a tool for the handing and storage of data in secondary memory
 * @version 0.1
 * @date 2021-04-13
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
class Vector_Hash {
    private:
    vector<Key> vector_hash;
    public:
    Vector_Hash(int vector_hash_size);
    bool Search_Key(Key& x) const;
    bool Insert_Key(int insert_key);
    bool Is_Full() const;
};

template<class Key>
Vector_Hash<Key>::Vector_Hash(int vector_hash_size) {
    for (int i = 0; i < vector_hash_size; i++) {
        vector_hash.push_back(0);
    }
    for (int i = 0; i < vector_hash_size; i++) {
        cout << vector_hash.at(i) << " ";
    }
    cout << endl;
};

template<class Key>
bool Vector_Hash<Key>::Search_Key(Key& x) const {

};

template<class Key>
bool Vector_Hash<Key>::Insert_Key(int insert_key) {

};

template<class Key>
bool Vector_Hash<Key>::Is_Full() const {

};