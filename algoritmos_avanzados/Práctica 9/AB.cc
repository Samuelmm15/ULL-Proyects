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
#include <queue>
#include <deque>
#include "nodeB.cc"

#pragma once
using namespace std;

template<class Key>
class AB {
    private:
    NodeB<Key> *root; /// raiz del árbol
    public:
    AB();
    ~AB();
    void Prune(NodeB<Key>* &node);
    bool Isempty(NodeB<Key> *node);
    bool Isleaf(NodeB<Key> *node);
    const int Size();
    const int BranchSize(NodeB<Key> *node);
    const int Height();
    const int BranchHeight(NodeB<Key> *node);
    const bool Balanced();
    const bool BalancedBranch(NodeB<Key> *node);
    void Search(Key &x);
    void Insert(const Key &x);
    void BalancedInsert(const Key &date, NodeB<Key> *node);
    void Preorder(NodeB<Key> *node); /// hacemos uso del preorden
    void LevelsRoute(NodeB<Key> *root); 
};

template<class Key>
AB<Key>::AB() {
    root = NULL;
};

template<class Key>
void AB<Key>::Prune(NodeB<Key>* &node) {
    if (node == NULL)
        return;
    Prune(node->left);
    Prune(node->right);
    delete node;
    node = NULL;
};

template<class Key>
AB<Key>::~AB() {
    Prune(root);
};

template<class Key>
bool AB<Key>::Isempty(NodeB<Key> *node) {
    return node == NULL;
};

template<class Key>
bool AB<Key>::Isleaf(NodeB<Key> *node) {
    return !node->right && !node->left;
};

template<class Key>
const int AB<Key>::Size() {
    return BranchSize(root);
};

template<class Key>
const int AB<Key>::BranchSize(NodeB<Key> *node) {
    if (node == NULL)
        return 0;
    return (1 + BranchSize(node->left) + BranchSize(node->right));
};

template<class Key>
const int AB<Key>::Height() {
    return BranchHeight(root);
};

template<class Key>
const int AB<Key>::BranchHeight(NodeB<Key> *node) {
    if (node == NULL)
        return 0;
    int height_i = BranchHeight(node->left);
    int height_d = BranchHeight(node->right);
    if (height_d > height_i)
        return height_d++;
    else
        return height_i++;
};

template<class Key>
const bool AB<Key>::Balanced() {
    return BalancedBranch(root);
};

template<class Key>
const bool AB<Key>::BalancedBranch(NodeB<Key> *node) {
    if (node == NULL)
        return true;
    int eq = BranchSize(node->left) - BranchSize(node->right);
    switch (eq) {
        case -1:
        case 0:
        case 1:
        return BalancedBranch(node->left) && BalancedBranch(node->right);
        default: return false;
    }
};

template<class Key>
void AB<Key>::Search(Key &x) {
    
};

template<class Key>
void AB<Key>::Insert(const Key &x) {
    if (root == NULL)
        root = new NodeB<int>(x, NULL, NULL);
    else
        BalancedInsert(x, root);
};

template<class Key>
void AB<Key>::BalancedInsert(const Key &date, NodeB<Key> *node) {
    if (BranchSize(node->left) <= BranchSize(node->right)) {
        if (node->left != NULL)
            BalancedInsert(date, node->left);
        else
            node->left = new NodeB<int>(date, NULL, NULL);
    }
    else {
        if (node->right != NULL)
            BalancedInsert(date, node->right);
        else
            node->right = new NodeB<int>(date, NULL, NULL);
    }
    
    cout << "El valor insertado ha sido: " << date << endl;
    LevelsRoute(root);
};

template<class Key>
void AB<Key>::Preorder(NodeB<Key> *node) { /// si se quiere realizar una búsqueda también se puede hacer mediante a esto, debido a que en el punto donde pone procesa, se puede implementar algun tipo de búsqueda dentro del árbol
    if (node == NULL)
        return;
    cout << node->data << endl;
    Preorder(node->left);
    Preorder(node->right);
};

template<class Key>
void AB<Key>::LevelsRoute(NodeB<Key> *root) { /// CORREGIR ESTO
    deque<int> Q;
    NodeB<int> *node;
    int level = 0;
    int actual_level = 0;
    Q.push_back(root->data);

    while (!Q.empty()) {
        node->data = Q.back();
        level = Q.back();
        if (level > actual_level)
            actual_level = level;
            cout << endl;
        if (node != NULL) {
            cout << node->data << endl;
            Q.push_back(node->data);
            Q.push_back(node->data);
        }
        else {

        }
    } 
};
