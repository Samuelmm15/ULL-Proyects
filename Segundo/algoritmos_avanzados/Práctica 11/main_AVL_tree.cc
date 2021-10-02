/**
 * @file main_search_binary_tree.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The implementation of a search binary tree
 * @version 0.1
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "AVL.h"
#include "nodeAVL.h"

void clrscr() {
    system("clear");
};

void menu(int &option) {  /// The menu of the program
    cout << "<< BIENVENIDO AL MENÚ DE OPCIONES >> " << endl;
    cout << "[0] Salir." << endl;
    cout << "[1] Insertar Clave." << endl;
    cout << "[2] Buscar Clave." << endl;
    cout << "[3] Eliminar Clave." << endl;
    cout << "[4] Activar / Desactivar Modo Traza." << endl;
    cout << "Introduzca una opción: ";
    cin >> option;
};

int main() {

    AVL<int> AVLTree; 

    int option = 0;
    int key_value = 0;
    int search_value = 0;
    int delete_value = 0;
    do {
        cout << endl;
        menu(option);
        switch(option) {
            case 1:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere añadir al árbol AVL: ";
                cin >> key_value;
                AVLTree.Insert(key_value);
            break;

            case 2:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere buscar en el árbol AVL: ";
                cin >> search_value;

                if (AVLTree.Search(search_value) == true) {
                    cout << "El valor " << search_value << " ha sido encontrado en el árbol AVL."; 
                } else if (AVLTree.Search(search_value) == false) {
                    cout << "El valor " << search_value << " NO ha sido encontrado en el árbol AVL.";
                }
            break;

            case 3:
                clrscr();
                cout << endl;
                cout << "Introduzca la clave que quiere eliminar del árbol AVL: ";
                cin >> delete_value;
                AVLTree.Delete(delete_value);
            break;

            case 4:
                clrscr();
                int option = 0;
                cout << "¿Quiere activar o desactivar la traza?" << endl;
                cout << endl;
                cout << "Si quiere activar la traza pulse [1]" << endl;
                cout << "Si quiere mantener la traza desactivada pulse [2]" << endl;
                cout << "Introduzca una opción: ";
                cin >> option;

                if (option == 1) {
                    AVLTree.trace_option = true;
                } else if (option == 2) {
                    AVLTree.trace_option = false;
                }
            break;
        }
    } while(option != 0);
    clrscr();
    cout << "Fin del programa" << endl;
};