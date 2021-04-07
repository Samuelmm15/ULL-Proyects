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
class List_Hash { 
    private:
        int nDates_copy;
        list<Key> list_hash; 
        int list_created = 0;
    public:
        /**
         * @brief The constructor of the Hash List
         * 
         * @param n The size of the Hash List
         */
        List_Hash(int n); 
        /**
         * @brief The fuction that searchs the key that the user insert
         * 
         * @param n The size of the list
         * @param find The key that is gonna to find at the list
         * @return true 
         * @return false 
         */
        bool Find_Key_List_Hash(int n, int find);
        /**
         * @brief The fuction that inserts the keys at a list
         * 
         * @param n The size of the List
         * @param insert_key The key that is gonna to insert
         * @return true 
         * @return false 
         */
        bool Insert_Key_List_Hash(int n, int insert_key);
};

template<class Key>
List_Hash<Key>::List_Hash(int n) { 
    list<Key> list_hash; 
};

template<class Key>
bool List_Hash<Key>::Find_Key_List_Hash(int n, int find) {
    if (list_created == 1) { 
      list<int>::iterator p = list_hash.begin();
      while (p != list_hash.end()) {
          if (*p == find) {
             cout << "Ha sido encontrado en la posicion: " << *p << " de la lista dentro de la celda." << endl;
            return true;
          } else if (*p != find) {
            cout << "Ha sido encontrado en la posicion: " << *p << " de la lista dentro de la celda." << endl;
            return false;
          }
          p++;
      }      
    }
};

template<class Key>
bool List_Hash<Key>::Insert_Key_List_Hash(int n, int insert_key) {
    if (list_created == 0) {
        nDates_copy = n; 
        for (int i = 0; i < nDates_copy; i++) {
            list_hash.push_back(i);
        }
        cout << "La lista no había sido creada dentro de la celda, la creamos..." << endl;
        list_created = 1; 
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
            list_hash.emplace_back(insert_key); /// To insert the key at the end of the list
            return true;
        }
    }
};