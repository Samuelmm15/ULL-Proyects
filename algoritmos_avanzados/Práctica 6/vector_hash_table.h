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
    bool Search_Key(int x); 
    bool Insert_Key(int insert_key);
    bool Is_Full();
};

template<class Key>
Vector_Hash<Key>::Vector_Hash(int vector_hash_size) {
    vector_hash.resize(vector_hash_size);
};

template<class Key>
bool Vector_Hash<Key>::Search_Key(int x) {
    for (int i = 0; i < vector_hash.size(); i++) {
        if (vector_hash.at(i) == x) {
            return false;
        } else if (vector_hash.at(i) != x) {
            return false;
        }
    }
};

template<class Key>
bool Vector_Hash<Key>::Insert_Key(int insert_key) {
    if (Search_Key(insert_key) == false) {
        if (Is_Full() == false) {
            int iterator = 0;
            while(vector_hash.at(iterator) != 0) {
                iterator++;
            }
            vector_hash.clear(vector_hash.begin + iterator);  /// ESTE PUNTO ESTA MAL, SOLO FALTA PODER INSERTAR LOS VALORES AL PRINCIPIO DEL VECTOR DE MANERA CORRECTA
            vector_hash.insert(vector_hash.begin() + iterator,insert_key); /// PRIMERO SE DEBE BORRAR EL ELEMENTO PARA PODER INSERTAR EL NUEVO
            
            
            for (int i = 0; i < vector_hash.size(); i++) {
                cout << vector_hash.at(i) << " ";
            }
            cout << endl;

            return true;
        } else if (Is_Full() == true) {
            return false;
        }
    }
};

template<class Key>
bool Vector_Hash<Key>::Is_Full() {
    int counter = 0;
    for (int i = 0; i < vector_hash.size(); i++) {
        if (vector_hash.at(i) != 0) {
            counter++;
        }
    }
    if (counter == vector_hash.size()) {
        return true;
    } else if (counter != vector_hash.size()) {
        return false;
    }
};