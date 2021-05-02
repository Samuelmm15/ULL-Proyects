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

void menu(int &option) {  /// The menu of the program
    cout << "<< BIENVENIDO AL MENÚ DE OPCIONES >> " << endl;
    cout << "[0] Salir." << endl;
    cout << "[1] Insertar Clave." << endl;
    cout << "[2] Buscar Clave." << endl;
    cout << "Introduzca una opción: ";
    cin >> option;
};

int main() {

    AB<int> BTree; 

    int option = 0;
    int key_value = 0;
    int search_value = 0;
    do {
        cout << endl;
        menu(option);
        switch(option) {
            case 1:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere añadir al árbol binario: ";
                cin >> key_value;
                BTree.Insert(key_value);
            break;

            case 2:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere buscar en el árbol binario: ";
                cin >> search_value;

                if (BTree.Search(search_value) == true) {
                    cout << "El valor " << search_value << " ha sido encontrado en el árbol binario."; 
                } else if (BTree.Search(search_value) == false) {
                    cout << "El valor " << search_value << " NO ha sido encontrado en el árbol binario.";
                }
            break;
        }
    } while(option != 0);
    clrscr();
    cout << "Fin del programa" << endl;
};