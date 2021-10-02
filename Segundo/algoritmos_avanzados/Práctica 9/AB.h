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
#include <deque>
#include "nodeB.h"

#pragma once
using namespace std;

template<class Key>
class AB {
    private:
    /**
     * @brief The root node of the tree
     * 
     */
    NodeB<Key> *root;
    int counter = 0;
    public:
    /**
     * @brief Construct a new AB object
     * 
     */
    AB();
    /**
     * @brief Destroy the AB object
     * 
     */
    ~AB();
    /**
     * @brief Fuction that destroys the tree
     * 
     * @param node 
     */
    void Prune(NodeB<Key>* &node);
    /**
     * @brief Fuction that calculates if the tree is empty
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool Isempty(NodeB<Key> *node);
    /**
     * @brief Fuction that calculates if it is a leaf of the tree
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool Isleaf(NodeB<Key> *node);
    /**
     * @brief Fuction that calculates the size of the tree
     * 
     * @return const int 
     */
    const int Size();
    /**
     * @brief Fuction that calculates the size of a branch of the tree
     * 
     * @param node 
     * @return const int 
     */
    const int BranchSize(NodeB<Key> *node);
    /**
     * @brief Fuction that calculates the height of the tree
     * 
     * @return const int 
     */
    const int Height();
    /**
     * @brief Fuction that calculates the height of a branch of the tree
     * 
     * @param node 
     * @return const int 
     */
    const int BranchHeight(NodeB<Key> *node);
    /**
     * @brief Fuction that calculates if the tree is balanced
     * 
     * @return true 
     * @return false 
     */
    const bool Balanced();
    /**
     * @brief Fuction that calculates if a branch is balanced
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    const bool BalancedBranch(NodeB<Key> *node);
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
    bool BranchSearch(Key &x, NodeB<Key> *root);
    /**
     * @brief Fuction that inserts a Key into the tree
     * 
     * @param x 
     */
    void Insert(const Key &x);
    /**
     * @brief Fuction that generates a balanced insertion into the tree
     * 
     * @param date 
     * @param node 
     */
    void BalancedInsert(const Key &date, NodeB<Key> *node);
    /**
     * @brief Fuction that calculates the preorder of the tree
     * 
     * @param node 
     */
    void Preorder(NodeB<Key> *node); 
    /**
     * @brief Fuction that makes a levels route
     * 
     * @param root 
     */
    void LevelsRoute(NodeB<Key> *root); 
    /**
     * @brief Fuction that prints the tree
     * 
     * @param node 
     */
    void Print(NodeB<Key> *node);
};

template<class Key>
AB<Key>::AB() {
    root = NULL;
};

template<class Key>
AB<Key>::~AB() {
    Prune(root);
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
bool AB<Key>::Search(Key &x) {
    return BranchSearch(x, root);
};

template<class Key>
bool AB<Key>::BranchSearch(Key &x, NodeB<Key> *root) {    
    deque<pair<NodeB<Key> *, int>> Q;
    NodeB<int> *node;
    bool aux;
    int level = 0;
    int actual_level = 0;

    Q.push_back(pair<NodeB<Key> *, int>(root, 0));

    while (!Q.empty()) {
        node = Q.front().first;
        level = Q.front().second;
        Q.pop_front();
        if (level > actual_level) {
            actual_level = level;
        }
        if (node != NULL) {
            if (node->data == x) {
                aux = true;
            }
            if (node->data != x) {
                aux = false;
            }
            Q.push_back(pair<NodeB<Key> *, int>(node->left, level + 1));
            Q.push_back(pair<NodeB<Key> *, int>(node->right, level + 1));
        }
    }
    return aux;   
};

template<class Key>
void AB<Key>::Insert(const Key &x) {
    if (root == NULL)
        root = new NodeB<int>(x, NULL, NULL);
    else
        BalancedInsert(x, root);

    cout << "El valor insertado ha sido: " << x << endl;
    LevelsRoute(root);
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
    
};

template<class Key>
void AB<Key>::Preorder(NodeB<Key> *node) { 
    if (node == NULL)
        return;
    cout << node->data << endl;
    Preorder(node->left);
    Preorder(node->right);
};

template<class Key>
void AB<Key>::LevelsRoute(NodeB<Key> *root) { 
    deque<pair<NodeB<Key> *, int>> Q;
    NodeB<int> *node;
    int level = 0;
    int actual_level = 0;

    Q.push_back(pair<NodeB<Key> *, int>(root, 0));
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
        if (node != NULL) {
            Q.push_back(pair<NodeB<Key> *, int>(node->left, level + 1));
            Q.push_back(pair<NodeB<Key> *, int>(node->right, level + 1));
        }
    } 
    cout << endl;
};

template<class Key>
void AB<Key>::Print(NodeB<Key> *node) {
    if (node == NULL) {
        cout << "[.]";
    }
    else {
        cout << "[";
        cout << node->data;
        cout << "]";
    }
};
