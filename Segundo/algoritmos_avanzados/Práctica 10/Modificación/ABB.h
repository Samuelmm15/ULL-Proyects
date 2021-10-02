/**
 * @file ABB.h
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
#include <deque>
#include "nodeBB.h"

#pragma once
using namespace std;

template<class Key>
class ABB {
    private:
    /**
     * @brief The root node of the tree
     * 
     */
    NodeBB<Key> *root;
    int counter = 0;
    public:
    /**
     * @brief Construct a new AB object
     * 
     */
    ABB();
    /**
     * @brief Destroy the AB object
     * 
     */
    ~ABB();
    /**
     * @brief Fuction that destroys the tree
     * 
     * @param node 
     */
    void Prune(NodeBB<Key>* &node);
    /**
     * @brief Fuction that searchs a Key
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool Search(Key &x);
    /**
     * @brief Fuction that searchs the key into the branchs
     * 
     * @param x 
     * @param node 
     * @return true 
     * @return false 
     */
    bool BranchSearch(Key &x, NodeBB<Key> *node);
    /**
     * @brief Fuction that inserts a Key into the tree
     * 
     * @param x 
     */
    void Insert(Key &x);
    /**
     * @brief Fuction that generates a balanced insertion into the tree
     * 
     * @param date 
     * @param node 
     */
    void BBInsert(Key &date, NodeBB<Key>* &node);
    /**
     * @brief Fuction that calculates the preorder of the tree
     * 
     * @param node 
     */
    void Preorder(NodeBB<Key> *node); 
    /**
     * @brief Fuction that makes a levels route
     * 
     * @param root 
     */
    void LevelsRoute(NodeBB<Key> *root, bool option); 
    /**
     * @brief Fuction that prints the tree
     * 
     * @param node 
     */
    void Print(NodeBB<Key> *node);
    void Levels();
};

template<class Key>
ABB<Key>::ABB() {
    root = NULL;
};

template<class Key>
ABB<Key>::~ABB() {
    Prune(root);
};

template<class Key>
void ABB<Key>::Prune(NodeBB<Key>* &node) { 
    if (node == NULL)
        return;
    Prune(node->left);
    Prune(node->right);
    delete node;
    node = NULL;
};

template<class Key>
bool ABB<Key>::Search(Key &x) {
    return BranchSearch(x, root);
};

template<class Key>
bool ABB<Key>::BranchSearch(Key &x, NodeBB<Key> *node) {    
    if (node == NULL) {
        return false;
    }
    if (x == node->clave) {
        return true;
    }
    if (x < node->clave) {
        BranchSearch(x, node->left);
        BranchSearch(x, node->right); 
    }
};

template<class Key>
void ABB<Key>::Insert(Key &x) {
    BBInsert(x, root);

    cout << "El valor insertado ha sido: " << x << endl;
    LevelsRoute(root, false);
};

template<class Key>
void ABB<Key>::BBInsert(Key &date, NodeBB<Key>* &node) {
    if (node == NULL) {
        node = new NodeBB<Key>(date, date);
    } else if (date < node->clave) {
        BBInsert(date, node->left);
    } else {
        BBInsert(date, node->right);
    }
    
};

template<class Key>
void ABB<Key>::Preorder(NodeBB<Key> *node) { 
    if (node == NULL)
        return;
    cout << node->data << endl;
    Preorder(node->left);
    Preorder(node->right);
};

template<class Key>
void ABB<Key>::Levels() {
    LevelsRoute(root, true);
};

template<class Key>
void ABB<Key>::LevelsRoute(NodeBB<Key> *root, bool option) { 
    
    if (option == true) {
        int counter = 0;
        deque<pair<NodeBB<Key> *, int>> Q;
        NodeBB<int> *node;
        int level = 0;
        int actual_level = 0;

        Q.push_back(pair<NodeBB<Key> *, int>(root, 0));
        cout << "Nivel 0:";
        while (!Q.empty()) {
            node = Q.front().first;
            level = Q.front().second;
            Q.pop_front();
            if (level > actual_level) {
                actual_level = level;
                cout << endl;
                cout << "Nivel " << actual_level << " : ";
            }
            Print(node);
            if (node != nullptr) {
                Q.push_back(pair<NodeBB<Key> *, int>(node->left, level + 1));
                Q.push_back(pair<NodeBB<Key> *, int>(node->right, level + 1));
                counter++;
            }
        } 
        cout << endl;
        cout << "El número de nodos que tienen el árbol es de " << counter << " nodos." << endl;

    } else {
        deque<pair<NodeBB<Key> *, int>> Q;
        NodeBB<int> *node;
        int level = 0;
        int actual_level = 0;

        Q.push_back(pair<NodeBB<Key> *, int>(root, 0));
        cout << "Nivel 0:";

        while (!Q.empty()) {
            node = Q.front().first;
            level = Q.front().second;
            Q.pop_front();
            if (level > actual_level) {
                actual_level = level;
                cout << endl;
                cout << "Nivel " << actual_level << " : ";
            }
            Print(node);
            if (node != nullptr) {
                Q.push_back(pair<NodeBB<Key> *, int>(node->left, level + 1));
                Q.push_back(pair<NodeBB<Key> *, int>(node->right, level + 1));
            }
        } 
        cout << endl;
    }
};

template<class Key>
void ABB<Key>::Print(NodeBB<Key> *node) {
    if (node == nullptr) {
        cout << "[.]";
    }
    else {
        cout << "[";
        cout << node->data;
        cout << "]";
    }
};
