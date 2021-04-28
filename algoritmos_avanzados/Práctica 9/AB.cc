/**
 * @file AB.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The implementation of a balanced binary tree
 * @version 0.1
 * @date 2021-04-28
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
#include "nodeB.cc"

#pragma once
using namespace std;

template<class Key>
class AB {
    public:
    int *left_node; /// Para poder establecer si la rama ya ha sido creada o no
    int *right_node;
    vector<Key> preorder;
    vector<Key> postorder;
    vector<Key> in_order;
    AB(int tree_size);
    void Search(Key &x);
    void Insert(const Key &x, NodeB<Key> Node);
};

template<class Key>
AB<Key>::AB(int tree_size) {
    left_node = NULL; /// inicializamos los punteros a nulo
    right_node = NULL;
    preorder.resize(tree_size);
    postorder.resize(tree_size);
    in_order.resize(tree_size);
};

template<class Key>
void AB<Key>::Search(Key &x) {

};

template<class Key>
void AB<Key>::Insert(const Key &x, NodeB<Key> Node) {
    Node.Insert_Node(x, preorder, postorder, in_order, left_node, right_node);
};
