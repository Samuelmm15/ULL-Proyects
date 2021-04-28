/**
 * @file main_balanced_binary_tree.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The implementation of a balanced binary tree
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "AB.cc"
#include "nodeB.cc"

void clrscr() {
    system("clear");
};

void menu(int &option) {
    cout << "<< BIENVENIDO AL MENÚ DE OPCIONES >> " << endl;
    cout << "[0] Salir." << endl;
    cout << "[1] Insertar Clave." << endl;
    cout << "[2] Buscar Clave." << endl;
    cout << "Introduzca una opción: ";
    cin >> option;
};

int main() {

    int tree_size = 0;
    cout << endl;
    cout << "Antes de comenzar..." << endl;
    cout << "Introduzca el tamaño del árbol del que va a hacer uso: ";
    cin >> tree_size;

    AB<int> BTree(tree_size); /// creamos el objeto árbol
    NodeB<int> Node;


    int option = 0; /// implementación del menú de opciones
    int key_value = 0;
    do {
        cout << endl;
        menu(option);
        switch(option) {
            case 1:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere añadir al árbol binario: ";
                cin >> key_value;
                BTree.Insert(key_value, Node);
            break;

            case 2:
                clrscr();
            break;
        }
    } while(option != 0);
    clrscr();
    cout << "Fin del programa" << endl;
};