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
#include "nodeAVL.h"

#pragma once
using namespace std;

template<class Key>
class AVL {
    private:
    /**
     * @brief The root node of the tree
     * 
     */
    NodeAVL<Key> *root;
    public:
    /**
     * @brief The trace option of the programm
     * 
     */
    bool trace_option = false;
    /**
     * @brief Construct a new AB object
     * 
     */
    AVL();
    /**
     * @brief Destroy the AB object
     * 
     */
    ~AVL();
    /**
     * @brief Fuction that destroys the tree
     * 
     * @param node 
     */
    void Prune(NodeAVL<Key>* &node);
    /**
     * @brief The Rotation II
     * 
     * @param node 
     */
    void Rotation_II(NodeAVL<Key>* &node);
    /**
     * @brief The Rotation DD
     * 
     * @param node 
     */
    void Rotation_DD(NodeAVL<Key>* &node);
    /**
     * @brief The Rotation ID
     * 
     * @param node 
     */
    void Rotation_ID(NodeAVL<Key>* &node);
    /**
     * @brief The Rotation DI
     * 
     * @param node 
     */
    void Rotation_DI(NodeAVL<Key>* &node);
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
    bool BranchSearch(Key &x, NodeAVL<Key> *node);
    /**
     * @brief Fuction that inserts a Key into the tree
     * 
     * @param x 
     */
    void Insert(Key &x);
    void Insert_bal(NodeAVL<Key>* &node, NodeAVL<Key>* new_, bool &grow);
    void Insert_re_bal_left(NodeAVL<Key>* &node, bool &grow);
    void Insert_re_bal_right(NodeAVL<Key>* &node, bool &grow);
    /**
     * @brief Fuction that deletes a Key into the tree
     * 
     * @param x 
     */
    void Delete(Key &x);
    void Delete_Branch(NodeAVL<Key>* &node, int val, bool &decreases);
    void Replace(NodeAVL<Key>* &deleted, NodeAVL<Key>* &replaced, bool &decreases);
    void Delete_re_bal_left(NodeAVL<Key>* &node, bool &decreases);
    void Delete_re_bal_right(NodeAVL<Key>* &node, bool &decreases);
    /**
     * @brief Fuction that makes a levels route
     * 
     * @param root 
     */
    void LevelsRoute(NodeAVL<Key> *root); 
    /**
     * @brief Fuction that prints the tree
     * 
     * @param node 
     */
    void Print(NodeAVL<Key> *node);
};

template<class Key>
AVL<Key>::AVL() {
    root = NULL;
};

template<class Key>
AVL<Key>::~AVL() {
    Prune(root);
};

template<class Key>
void AVL<Key>::Prune(NodeAVL<Key>* &node) { 
    if (node == NULL)
        return;
    Prune(node->left);
    Prune(node->right);
    delete node;
    node = NULL;
};

template<class Key>
void AVL<Key>::Rotation_II(NodeAVL<Key>* &node) {
    NodeAVL<Key>* node1 = node->left;
    node->left = node1->right;
    node1->right = node;
    if (node1->bal == 1) {
        node->bal = 0;
        node1->bal = 0;
    }
    else {
        node->bal = 1;
        node1->bal = -1;
    }
    node = node1;
};

template<class Key>
void AVL<Key>::Rotation_DD(NodeAVL<Key>* &node) {
    NodeAVL<Key>* node1 = node->right;
    node->right = node1->left;
    node1->left = node;
    if (node1->bal == -1) {
        node->bal = 0;
        node1->bal = 0;
    }
    else {
        node->bal = -1;
        node1->bal = 1;
    }
    node = node1;
};

template<class Key>
void AVL<Key>::Rotation_ID(NodeAVL<Key>* &node) {
    NodeAVL<Key>* node1 = node->left;
    NodeAVL<Key>* node2 = node1->right;
    node->left = node2->right;
    node2->right = node;
    node1->right = node2->left;
    node2->left = node1;
    if (node2->bal == -1) {
        node1->bal = 1;
    }
    else {
        node1->bal = 0;
    }
    if (node2->bal == 1) {
        node->bal = -1;
    }
    else {
        node->bal = 0;
    }
    node2->bal = 0;
    node = node2;
};

template<class Key>
void AVL<Key>::Rotation_DI(NodeAVL<Key>* &node) {
    NodeAVL<Key>* node1 = node->right;
    NodeAVL<Key>* node2 = node1->left;
    node->right = node2->left;
    node2->left = node;
    node1->left = node2->right;
    node2->right = node1;
    if (node2->bal == 1) {
        node1->bal = -1;
    }
    else {
        node1->bal = 0;
    }
    if (node2->bal == -1) {
        node->bal = 1;
    }
    else {
        node->bal = 0;
    }
    node2->bal = 0;
    node = node2;
};

template<class Key>
bool AVL<Key>::Search(Key &x) {
    return BranchSearch(x, root);
};

template<class Key>
bool AVL<Key>::BranchSearch(Key &x, NodeAVL<Key> *node) {    
    if (node == NULL) {
        return false;
    }
    if (x == node->data) {
        return true;
    }
    if (x < node->data) {
        BranchSearch(x, node->left);
    }
    BranchSearch(x, node->right); 
};

template<class Key>
void AVL<Key>::Insert(Key &x) {
    NodeAVL<Key>* new_;
    new_ = new NodeAVL<Key>(x,0);
    bool grow = false;
    
    Insert_bal(root, new_, grow);
    
    cout << "El valor insertado ha sido: " << x << endl;
    LevelsRoute(root);
};

template<class Key>
void AVL<Key>::Insert_bal(NodeAVL<Key>* &node, NodeAVL<Key>* new_, bool &grow) { 
    if (node == NULL) {
        node = new_;
        grow = true;
    }
    else if (new_->data < node->data) {
        Insert_bal(node->left, new_, grow);
        if (grow) {
            Insert_re_bal_left(node, grow);
        }
    }
    else {
        Insert_bal(node->right, new_, grow);
        if (grow) {
            Insert_re_bal_right(node, grow);
        }
    }
};

template<class Key>
void AVL<Key>::Insert_re_bal_left(NodeAVL<Key>* &node, bool &grow) {
    switch (node->bal) {
        case -1:
            node->bal = 0;
            grow = false;
        break;
        case 0:
            node->bal = 1;
        break;
        case 1:
            NodeAVL<Key>* node1 = node->left;
            if (node1->bal == 1) {
                if (trace_option == true) {
                    cout << endl;
                    cout << "Desbalanceo: " << endl;
                    LevelsRoute(root);
                    cout << "Rotación II en [" << node->data << "];" << endl;
                }
                Rotation_II(node);
            }
            else {
                if (trace_option == true) {
                    cout << endl;
                    cout << "Desbalanceo: " << endl;
                    LevelsRoute(root);
                    cout << "Rotación ID en [" << node->data << "];" << endl;
                }
                Rotation_ID(node);
            }
            grow = false;
        break;
    }
};

template<class Key>
void AVL<Key>::Insert_re_bal_right(NodeAVL<Key>* &node, bool &grow) {
    switch (node->bal) {
        case 1:
            node->bal = 0;
            grow = false;
        break;
        case 0:
            node->bal = -1;
        break;
        case -1:
            NodeAVL<Key>* node1 = node->right;
            if (node1->bal == -1) {
                if (trace_option == true) {
                    cout << endl;
                    cout << "Desbalanceo: " << endl;
                    LevelsRoute(root);
                    cout << "Rotación DD en [" << node->data << "];" << endl;
                }
                Rotation_DD(node);
            }
            else {
                if (trace_option == true) {
                    cout << endl;
                    cout << "Desbalanceo: " << endl;
                    LevelsRoute(root);
                    cout << "Rotación DI en [" << node->data << "];" << endl;
                }
                Rotation_DI(node);
            }
            grow = false;
        break;
    }
};

template<class Key>
void AVL<Key>::Delete(Key &x) {
    bool decreases = false;
    Delete_Branch(root, x, decreases);

    cout << "Tras la eliminación, el árbol tiene la siguiente forma: " << endl;
    LevelsRoute(root);
};

template<class Key>
void AVL<Key>::Delete_Branch(NodeAVL<Key>* &node, int val, bool &decreases) {
    if (node == NULL) {
        return;
    }
    if (val < node->data) {
        Delete_Branch(node->left, val, decreases);
        if (decreases) {
            Delete_re_bal_left(node, decreases);
        }
    }
    else if (val > node->data) {
        Delete_Branch(node->right, val, decreases);
        if (decreases) {
            Delete_re_bal_right(node, decreases);
        }
    }
    else {
        NodeAVL<Key>* Deleted = node;
        if (node->left == NULL) {
            node = node->right;
            decreases = true;
        }
        else if (node->right == NULL) {
            node = node->left;
            decreases = true;
        }
        else {
            Replace(Deleted, node->left, decreases);
            if (decreases) {
                Delete_re_bal_left(node, decreases);
            }
        }
        delete Deleted;
    }
};

template<class Key>
void AVL<Key>::Replace(NodeAVL<Key>* &deleted, NodeAVL<Key>* &replaced, bool &decreases) {
    if (replaced->right != NULL) {
        Replace(deleted, replaced->right, decreases);
        if (decreases) {
            Delete_re_bal_right(replaced, decreases);
        }
    }
    else {
        deleted->data = replaced->data;
        deleted = replaced;
        replaced = replaced->left;
        decreases = true;
    }
};

template<class Key>
void AVL<Key>::Delete_re_bal_left(NodeAVL<Key>* &node, bool &decreases) {
    switch (node->bal) {
        case -1:
            {
                NodeAVL<Key>* node1 = node->right;
                if (node1->bal > 0) {
                    Rotation_DI(node);
                }
                else {
                    if (node1->bal == 0) {
                        decreases = false;
                    }
                    Rotation_DD(node);
                }
            }
        break;
        case 0:
            {
                node->bal = -1;
                decreases = false;
            }
        break;
        case 1:
            {
                node->bal = 0;
            }

    }
};

template<class Key>
void AVL<Key>::Delete_re_bal_right(NodeAVL<Key>* &node, bool &decreases) {
    switch (node->bal) {
        case 1:
            {
                NodeAVL<Key>* node1 = node->left;
                if (node1->bal < 0) {
                    Rotation_ID(node);
                }
                else {
                    if (node1->bal == 0) {
                        decreases = false;
                    }
                    Rotation_II(node);
                }
            }
        break;
        case 0:
            {
                node->bal = 1;
                decreases = false;
            }
        break;
        case -1:
            {
                node->bal = 0;
            }
    }
};

template<class Key>
void AVL<Key>::LevelsRoute(NodeAVL<Key> *root) { 
    deque<pair<NodeAVL<Key> *, int>> Q;
    NodeAVL<int> *node;
    int level = 0;
    int actual_level = 0;

    Q.push_back(pair<NodeAVL<Key> *, int>(root, 0));
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
            Q.push_back(pair<NodeAVL<Key> *, int>(node->left, level + 1));
            Q.push_back(pair<NodeAVL<Key> *, int>(node->right, level + 1));
        }
    } 
    cout << endl;
};

template<class Key>
void AVL<Key>::Print(NodeAVL<Key> *node) {
    if (node == nullptr) {
        cout << "[.]";
    }
    else {
        cout << "[";
        cout << node->data;
        cout << "]";
    }
};
