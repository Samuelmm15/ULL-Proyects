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

#pragma once
using namespace std;

template<class Key>
class Hash_Table { /// falta que la clase reciba la clave
    private:
        int nDates = 0;
        int *vDates; /// Buscar la manera de que el array esté inicializado por nDates
        Module_Hash *fd_M; /// puntero que todavía no esta inicializado, se debe de inicializar
        Pseudorandom_Hash *fd_P;
    public:
    Hash_Table(int const n, int const fuction_option, Module_Hash M, Pseudorandom_Hash P); /// en esta función falta que reciba el objeto que es apuntado por el puntero fd
    bool Find_Key_Hash_Table(bool answer); /// recibe el valor clave X por referencia
    bool Insert_Key_Hash_Table(); /// recibe el valor clave X por referencia
    void Create_Table();
    int getnDates();
    int vDates_created = 0; /// para saber si la tabla ya ha sido creada o no, si ha sido creada está a uno, si no está a uno no ha sido creada
};

template<class Key>
Hash_Table<Key>::Hash_Table(int const n, int const fuction_option, Module_Hash M, Pseudorandom_Hash P) { 
    if (fuction_option == 1) {
        Hash_Table::nDates = n; /// establecemos el tamaño de la tabla
        fd_M = &M; /// enlazado con el objeto
    } else if (fuction_option == 2) {
        Hash_Table::nDates = n; /// establecemos el tamaño de la tabla
        fd_P = &P; /// enlazado con el objeto
    }
};

template<class Key>
bool Hash_Table<Key>::Find_Key_Hash_Table(bool answer) {
    if (answer == true) {
        return true;
    } else if (answer == false) {
        return false;
    }
};

template<class Key>
bool Hash_Table<Key>::Insert_Key_Hash_Table() {

};

template<class Key>
void Hash_Table<Key>::Create_Table() {
    vDates = new int [nDates]; /// inicializamos la tabla de hash
};

template<class Key>
int Hash_Table<Key>::getnDates() {
    return nDates;
};