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

    /// Falta la generación de un árbol binario vacío y la implementación de los objetos


    int option = 0; /// implementación del menú de opciones
    do {
        cout << endl;
        menu(option);
        switch(option) {
            case 1:
                clrscr();
            break;

            case 2:
                clrscr();
            break;
        }
    } while(option != 0);
    clrscr();
    cout << "Fin del programa" << endl;
};