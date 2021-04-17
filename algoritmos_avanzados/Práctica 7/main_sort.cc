/**
 * @file main_sort.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This program presents an implementation of three algorithms of sort
 * @version 0.1
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "insertion.h"
#include "quicksort.h"
#include "shellsort.h"

void clrscr() {
    system("clear");
};

template<typename Key> void Vector_Sort(vector<Key> &vector_sort, Key number_cells);

template<typename Key>
void Vector_Sort(vector<Key> &vector_sort, Key number_cells) { /// FALTA LA DECLARACIÓN DEL CÓDIGO

};

int main() {
    cout << "<< BIENVENIDO AL PROGRAMA DE ORDENACIÓN DE SECUENCIAS >>" << endl;

    int algorithm_option = 0;
    cout << "Para comenzar introduzca el tipo de algoritmo del cual quiere hacer uso." << endl;
    cout << "Introduzca [1] si quiere el algoritmo de ordenación de inserción." << endl;
    cout << "Introduzca [2] si quiere el algoritmo de ordenación QuickSort." << endl;
    cout << "Introduzca [3] si quiere el algoritmo de ordenación ShellSort." << endl;
    cout << "De cual quiere hacer uso: ";
    cin >> algorithm_option;

    clrscr();
    int cells_size = 0;
    cout << "A continuación introduzca el tamaño de la secuencia que quiere ordenar: ";
    cin >> cells_size;

    clrscr();
    char ejecution_trace;
    cout << "¿Prefiere mostrar en todo momento la traza de ejecución?" << endl;
    cout << "[s/n]: ";
    cin >> ejecution_trace;

    clrscr();
    int write_option = 0;
    cout << "¿Prefiere introducir los valores que quiere ordenar, de manera manueal u aleatoria?" << endl;
    cout << "Si lo prefiere de manera manueal introduza [1], si lo prefiere aleatorio introduzca [2] : ";
    cin >> write_option;

    clrscr();
    if (write_option == 1) { /// en este punto comienza el programa

        if (algorithm_option == 1) {

            if (ejecution_trace == 's') {
        
            } else if (ejecution_trace == 'n') {

            }

        } else if (algorithm_option == 2) {

            if (ejecution_trace == 's') {

            } else if (ejecution_trace == 'n') {

            }

        } else if (algorithm_option == 3) {

            if (ejecution_trace == 's') {

            } else if (ejecution_trace == 'n') {

            }

        }

    } else if (write_option == 2) {

        if (algorithm_option == 1) {

            if (ejecution_trace == 's') {

            } else if (ejecution_trace == 'n') {

            }

        } else if (algorithm_option == 2) {

            if (ejecution_trace == 's') {

            } else if (ejecution_trace == 'n') {

            }

        } else if (algorithm_option == 3) {

            if (ejecution_trace == 's') {

            } else if (ejecution_trace == 'n') {

            }

        }

    } 
    exit(1);
};