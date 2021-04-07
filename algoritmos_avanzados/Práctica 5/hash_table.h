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
class Hash_Table { /// falta que la clase reciba la clave
    private:
        int nDates = 0;
        int *vDates; /// Buscar la manera de que el array esté inicializado por nDates
        Module_Hash<Key> *fd_M; /// puntero que todavía no esta inicializado, se debe de inicializar
        Pseudorandom_Hash<Key> *fd_P;
    public:
    Hash_Table(int const n, int const fuction_option, Module_Hash<Key> M, Pseudorandom_Hash<Key> P); /// en esta función falta que reciba el objeto que es apuntado por el puntero fd
    bool Find_Key_Hash_Table(int find_key, List_Hash<Key> L); /// recibe el valor clave X por referencia
    bool Insert_Key_Hash_Table(int insert_key, List_Hash<Key> L, int position); /// recibe el valor clave X por referencia
    void Create_Table();
    int getnDates();
    int vDates_created = 0; /// para saber si la tabla ya ha sido creada o no, si ha sido creada está a uno, si no está a uno no ha sido creada
    vector<int> position_table;
};

template<class Key>
Hash_Table<Key>::Hash_Table(int const n, int const fuction_option, Module_Hash<Key> M, Pseudorandom_Hash<Key> P) { 
    if (fuction_option == 1) {
        Hash_Table::nDates = n; /// establecemos el tamaño de la tabla
        fd_M = &M; /// enlazado con el objeto
    } else if (fuction_option == 2) {
        Hash_Table::nDates = n; /// establecemos el tamaño de la tabla
        fd_P = &P; /// enlazado con el objeto
    }
};

template<class Key>
bool Hash_Table<Key>::Find_Key_Hash_Table(int find_key, List_Hash<Key> L) {
    if (vDates_created == 1) { /// si la tabla ya ha sido creada realizamos la búsqueda dentro de la tabla
        for (int i = 0; i < nDates; i++) {
            if (vDates[i] == find_key) {
                return true;
            } else if (vDates[i] != find_key) {
                bool answer = false; /// para poder comprobar si el elemento se encuentra dentro de la lista
                answer = L.Find_Key_List_Hash(nDates,find_key);
                if (answer == true) {
                    return true;
                }
            }
        }
    }
};

template<class Key>
bool Hash_Table<Key>::Insert_Key_Hash_Table(int insert_key, List_Hash<Key> L, int position) {
    int inserted = 0;
    if (vDates_created == 1) { /// si se ha producido que la tabla ya ha sido creada
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
                   return true;
               } else if (inserted == 1) {
                   bool answer = false;
                   answer = L.Insert_Key_List_Hash(nDates,insert_key);
                   if (answer == true) {
                       return true;
                   } else if (answer == false) {
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
    vDates = new int [nDates]; /// inicializamos la tabla de hash
};

template<class Key>
int Hash_Table<Key>::getnDates() {
    return nDates;
};