/**
 * @file hash_table.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The hash table is a tool for the handing and storage of data in secondary memory
 * @version 0.1
 * @date 2021-03-30
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
#include "module_hash.h"
#include "pseudorandom_hash.h"
#include "lineal_exploration.h"
#include "quadratic_exploration.h"
#include "double_dispersion_exploration.h"
#include "redispersion_exploration.h"
#include "vector_hash_table.h"

#pragma once
using namespace std;

template<class Key>
class Hash_Table { 
    private:
        int nDates = 0;
        int nSynonyms = 0;
        vector<Vector_Hash<Key>> vDates;  /// CAMBIAR ESTO
        Module_Hash<Key> *fd_M; 
        Pseudorandom_Hash<Key> *fd_P;
        Lineal_Exploration<Key> *fe_lineal;
        Quadratic_Exploration<Key> *fe_quadratic;
        Double_Dispersion_Exploration<Key> *fe_double;
        Redispersion_Exploration<Key> *fe_redispersion;

    public:
    /**
     * @brief The constructor of the Hash Table
     * 
     * @param n The number of lines of the Table
     * @param fuction_option The option of the dispersion fuction
     * @param M The object of the module dispersion fuction
     * @param P The object of the pseudorandom dispersion fuction
     */
    Hash_Table(int const n, int const fuction_option, int const vector_hash_size, Module_Hash<Key> M, Pseudorandom_Hash<Key> P, Lineal_Exploration<Key> L, Quadratic_Exploration<Key> Q, Double_Dispersion_Exploration<Key> D, Redispersion_Exploration<Key> R); 
    /**
     * @brief To find a key at the Hash Table
     * 
     * @param find_key The key that the fuction is gonna find
     * @param L The object Hash List
     * @return true 
     * @return false 
     */
    bool Find_Key_Hash_Table(int find_key, Vector_Hash<Key> V);
    /**
     * @brief The fuction to insert keys at the Hash Table
     * 
     * @param insert_key The key that the fuction is gonna insert
     * @param L The object Hash List
     * @param position The position of the Key
     * @return true 
     * @return false 
     */
    bool Insert_Key_Hash_Table(int insert_key, Vector_Hash<Key> V, int position); 
    /**
     * @brief The fuction that creates the Hash Table
     * 
     */
    void Create_Table(Vector_Hash<Key> V);
    /**
     * @brief The fuction that returns the size of the Hash Table
     * 
     * @return int 
     */
    int getnDates();
    int vDates_created = 0; 
    vector<int> position_table;
};

template<class Key> /// esto ya está completo
Hash_Table<Key>::Hash_Table(int const n, int const fuction_option, int const vector_hash_size, Module_Hash<Key> M, Pseudorandom_Hash<Key> P, Lineal_Exploration<Key> L, Quadratic_Exploration<Key> Q, Double_Dispersion_Exploration<Key> D, Redispersion_Exploration<Key> R) { 
    if (fuction_option == 1) {
        Hash_Table::nDates = n;
        Hash_Table::nSynonyms = vector_hash_size; 
        fd_M = &M;
        fe_lineal = &L;
        fe_quadratic = &Q;
        fe_double = &D;
        fe_redispersion = &R; 
    } else if (fuction_option == 2) {
        Hash_Table::nDates = n; 
        Hash_Table::nSynonyms = vector_hash_size;
        fd_P = &P;
        fe_lineal = &L;
        fe_quadratic = &Q;
        fe_double = &D;
        fe_redispersion = &R; 
    }
};

template<class Key>
bool Hash_Table<Key>::Find_Key_Hash_Table(int find_key, Vector_Hash<Key> V) {
    for (int i = 0; i < vDates.size(); i++) {
        if (vDates.at(i).Search_Key(find_key) == true) {
            return true;
        } else if (vDates.at(i).Search_Key(find_key) == false) {
            return false;
        }
    }
};

template<class Key>
bool Hash_Table<Key>::Insert_Key_Hash_Table(int insert_key, Vector_Hash<Key> V, int position) {
    if (vDates.at(position).Insert_Key(insert_key) == true) {
        return true;
    } else if (vDates.at(position).Insert_Key(insert_key) == false) {
        return false;
    }
};

template<class Key>
void Hash_Table<Key>::Create_Table(Vector_Hash<Key> V) {
    for (int i = 0; i < nDates; i++) {
        vDates.push_back(V);
    }
};

template<class Key>
int Hash_Table<Key>::getnDates() {
    return nDates;
};