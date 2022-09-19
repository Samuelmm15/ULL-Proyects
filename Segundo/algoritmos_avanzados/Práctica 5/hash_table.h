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
#include "list_hash_table.h"

#pragma once
using namespace std;

template<class Key>
class Hash_Table { 
    private:
        int nDates = 0;
        int *vDates; 
        Module_Hash<Key> *fd_M; 
        Pseudorandom_Hash<Key> *fd_P;
    public:
    /**
     * @brief The constructor of the Hash Table
     * 
     * @param n The number of lines of the Table
     * @param fuction_option The option of the dispersion fuction
     * @param M The object of the module dispersion fuction
     * @param P The object of the pseudorandom dispersion fuction
     */
    Hash_Table(int const n, int const fuction_option, Module_Hash<Key> M, Pseudorandom_Hash<Key> P); 
    /**
     * @brief To find a key at the Hash Table
     * 
     * @param find_key The key that the fuction is gonna find
     * @param L The object Hash List
     * @return true 
     * @return false 
     */
    bool Find_Key_Hash_Table(int find_key, List_Hash<Key> L);
    /**
     * @brief The fuction to insert keys at the Hash Table
     * 
     * @param insert_key The key that the fuction is gonna insert
     * @param L The object Hash List
     * @param position The position of the Key
     * @return true 
     * @return false 
     */
    bool Insert_Key_Hash_Table(int insert_key, List_Hash<Key> L, int position); 
    /**
     * @brief The fuction that creates the Hash Table
     * 
     */
    void Create_Table();
    /**
     * @brief The fuction that returns the size of the Hash Table
     * 
     * @return int 
     */
    int getnDates();
    int vDates_created = 0; 
    vector<int> position_table;
};

template<class Key>
Hash_Table<Key>::Hash_Table(int const n, int const fuction_option, Module_Hash<Key> M, Pseudorandom_Hash<Key> P) { 
    if (fuction_option == 1) {
        Hash_Table::nDates = n; 
        fd_M = &M; 
    } else if (fuction_option == 2) {
        Hash_Table::nDates = n; 
        fd_P = &P; 
    }
};

template<class Key>
bool Hash_Table<Key>::Find_Key_Hash_Table(int find_key, List_Hash<Key> L) {
    if (vDates_created == 1) { 
        for (int i = 0; i < nDates; i++) {
            
            if (vDates[i] == find_key) {
                cout << "Ha sido encontrado en la posicion: " << i << endl;
                return true;
            } else if (vDates[i] != find_key) {
                bool answer = false;
                answer = L.Find_Key_List_Hash(nDates,find_key);
                if (answer == true) {
                    cout << "Ha sido encontrado en la posicion: " << i << endl;
                    return true;
                }
            }
        }
        return false; /// If the key isn't at the Table
    }
};

template<class Key>
bool Hash_Table<Key>::Insert_Key_Hash_Table(int insert_key, List_Hash<Key> L, int position) {
    int inserted = 0;
    if (vDates_created == 1) { 
        for (int i = 0; i < nDates; i++) {
            if (i == position) {
               for (int j = 0; j < position_table.size(); j++) {
                   if (position_table.at(j) == position) {
                       inserted = 1;
                   } else if (position_table.at(j) != position) {
                       inserted = 0;
                   } 
               }
               
               if (inserted == 0) {
                   vDates[i] = insert_key;
                   
                   for (int i = 0; i < nDates; i++) { /// To print the Hash Table
                    cout << vDates[i] << " ";
                        }
                   return true;
               } else if (inserted == 1) {
                   bool answer = false;
                   answer = L.Insert_Key_List_Hash(nDates,insert_key);
                   if (answer == true) {
                       
                       for (int i = 0; i < nDates; i++) { 
                        cout << vDates[i] << " ";
                        }
                       return true;
                   } else if (answer == false) {
                       
                       for (int i = 0; i < nDates; i++) { 
                        cout << vDates[i] << " ";
                        }
                       return false;
                   }
               }
                position_table.push_back(position);
            }
        }   
    }
};

template<class Key>
void Hash_Table<Key>::Create_Table() {
    vDates = new int [nDates]; 
    for (int i = 0; i < nDates; i++) {
        vDates[i] = 0;
    }
    for (int i = 0; i < nDates; i++) {
        cout << vDates[i] << " ";
    }
};

template<class Key>
int Hash_Table<Key>::getnDates() {
    return nDates;
};