/**
 * @file list_hash_table.h
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

#pragma once
using namespace std;

template<class Key>
class List_Hash { /// Con esta clase se implementa la lista que se encuentra dentro de cada celda dentro de la propia tabla
    private:
        int nDates_copy;
        list<Key> list_hash; /// inicializamos el objeto lista y la lista de claves vacía
        int list_created = 0;
    public:
        List_Hash(int n); /// Los constructores de las clases deben de declararse sin establecer nada delante
        bool Find_Key_List_Hash(int n, int find);
        bool Insert_Key_List_Hash(int n, int insert_key);
};

template<class Key>
List_Hash<Key>::List_Hash(int n) { 
    list<Key> list_hash; /// inicializamos el objeto lista y la lista de claves vacía
};

template<class Key>
bool List_Hash<Key>::Find_Key_List_Hash(int n, int find) {
    if (list_created == 0) { /// La lista no ha sido creada, la creamos 
        nDates_copy = n; /// tenemos copiado el tamaño de la tabla para poder implementar las listas
        for (int i = 0; i < nDates_copy; i++) {
            list_hash.push_back(i);
        }
        cout << "La lista no había sido creada dentro de la celda, la creamos..." << endl;
        list_created = 1; /// La lista ha sido creada
        return false;
    } else if (list_created == 1) { /// si se produce que la lista ya ha sido creada
      list<int>::iterator p = list_hash.begin();
      while (p != list_hash.end()) {
          if (*p == find) {
            return true;
          } else {
            return false;
          }
          p++;
      }      
    }
};

template<class Key>
bool List_Hash<Key>::Insert_Key_List_Hash(int n, int insert_key) {
    if (list_created == 0) {
        nDates_copy = n; /// tenemos copiado el tamaño de la tabla para poder implementar las listas
        for (int i = 0; i < nDates_copy; i++) {
            list_hash.push_back(i);
        }
        cout << "La lista no había sido creada dentro de la celda, la creamos..." << endl;
        list_created = 1; /// La lista ha sido creada
        return false;
    } else if (list_created == 1) {
        int inserted = 0;
        list<int>::iterator p = list_hash.begin();
        while (p != list_hash.end()) {
            if (*p == insert_key) {
                inserted = 1;
                return false;
            } 
            p++;
        }
        if (inserted == 0) {
            list_hash.emplace_back(insert_key); /// añadimos el numero que queremos insertar al final de la lista
            return true;
        }

    
    }
};