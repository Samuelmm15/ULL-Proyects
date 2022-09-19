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

using namespace std;

template<typename Key> Key Vector_Sort_Insertion(vector<Key> &sec, Key number_cells);

template<typename Key>
Key Vector_Sort_Insertion(vector<Key> &sec, Key number_cells) { /// Fuction template for the method Insertion
    cout << endl;
    char ejecution_trace;
    cout << "¿Prefiere mostrar en todo momento la traza de ejecución?" << endl;
    cout << "[s/n]: ";
    cin >> ejecution_trace;

    if (ejecution_trace == 's') {
        int x = 0;
        int j = 0;
        for (int i = 0; i < number_cells; i++) {
            for (int k = 1; k < sec.size(); k++) {
                j = k;
                x = sec[k];
                sec[-1] = x;
                while ((x < sec[j-1]) && (j > 0)) {
                    cout << endl;
                    cout << "Antes de realizar el cambio: " << endl;
                    cout << sec[j] << " y " << sec[j-1] << endl;
                    sec[j] = sec[j-1];
                    j--;

                    cout << "En este punto tenemos el vector: " << endl;
                    for (int i = 0; i < sec.size(); i++) {
                        cout << sec.at(i) << " ";
                    }
                    cout << endl;
                }
                sec[j] = x;
            }
        }
    } else if (ejecution_trace == 'n') {
        int x = 0;
        int j = 0;
        for (int i = 0; i < number_cells; i++) {
            for (int k = 1; k < sec.size(); k++) {
                j = k;
                x = sec[k];
                sec[-1] = x;
                while ((x < sec[j-1]) && (j > 0)) {
                    sec[j] = sec[j-1];
                    j--;
                }
                sec[j] = x;
            }
        }
    }
    
    cout << endl;
    cout << "El vector finalmente ordenado es: " << endl;
    for (int i = 0; i < sec.size(); i++) {
        cout << sec.at(i) << " ";
    }
    cout << endl;
};

template<typename Key>
void Qsort(vector<Key> &sec, int ini, int fin, char ejecutation_trace) {
    if (ejecutation_trace == 's') {
        int i = ini;
        int f = fin;

        int p = sec[(i+f)/2];
        while (i <= f) {
            while (sec[i] < p) {
                i++;
            }
            while (sec[f] > p) {
                f--;
            }
            if (i <= f) {
                cout << endl;
                cout << "Antes de realizar el cambio: " << endl;
                cout << sec[i] << " y " << sec[f] << endl;
                swap(sec[i], sec[f]);
                cout << "Tras el cambio: " << endl;
                cout << sec[i] << " y " << sec[f] << endl;
                i++;
                f--;
            }

            cout << "En este punto tenemos el vector: " << endl;
            for (int i = 0; i < sec.size(); i++) {
            cout << sec.at(i) << " ";
            }
            cout << endl;
        }
        if (ini < f) {
            Qsort(sec,ini,f,ejecutation_trace);
        }
        if (i < fin) {
            Qsort(sec,i,fin,ejecutation_trace);
        }
    } else if (ejecutation_trace == 'n') {
        int i = ini;
        int f = fin;

        int p = sec[(i+f)/2];
        while (i <= f) {
            while (sec[i] < p) {
                i++;
            }
            while (sec[f] > p) {
                f--;
            }
            if (i <= f) {
                swap(sec[i], sec[f]);
                i++;
                f--;
            }
        }
        if (ini < f) {
            Qsort(sec,ini,f,ejecutation_trace);
        }
        if (i < fin) {
            Qsort(sec,i,fin,ejecutation_trace);
        }
    }
};

template<typename Key> Key Vector_Sort_Quicksort(vector<Key> &sec, Key number_cells);

template<typename Key>
Key Vector_Sort_Quicksort(vector<Key> &sec, Key number_cells) { /// Fuction template for the method QuickSort
    cout << endl;
    char ejecution_trace;
    cout << "¿Prefiere mostrar en todo momento la traza de ejecución?" << endl;
    cout << "[s/n]: ";
    cin >> ejecution_trace;

    if (ejecution_trace == 's') {
        int ini = 0;
        int fin = number_cells - 1;

        Qsort (sec,ini,fin, ejecution_trace);
    } else if (ejecution_trace == 'n') {
        int ini = 0;
        int fin = number_cells - 1;

        Qsort (sec,ini,fin, ejecution_trace);
    }

    cout << endl;
    cout << "El vector finalmente ordenado es: " << endl;
    for (int i = 0; i < sec.size(); i++) {
        cout << sec.at(i) << " ";
    }
    cout << endl;
};

template<typename Key> Key Vector_Sort_Shellsort(vector<Key> &sec, Key number_cells);

template<typename Key>
Key Vector_Sort_Shellsort(vector<Key> &sec, Key number_cells) { /// Fuction template for the method ShellSort
    cout << endl;
    char ejecution_trace;
    cout << "¿Prefiere mostrar en todo momento la traza de ejecución?" << endl;
    cout << "[s/n]: ";
    cin >> ejecution_trace;

    if (ejecution_trace == 's') {
        int del = number_cells;
        while (del > 1) {
            del = del / 2;

            int d = 0;
            d = del;
            int n = 0;
            n = number_cells;

            for (int i = d; i < n; i++) {
                int x;
                x = sec[i];
                int j;
                j = i;
                while ((j >= d) && (x < sec[j - d])) {
                    cout << endl;
                    cout << "Antes de realizar el cambio: " << endl;
                    cout << sec[j] << " y " << sec[j - d] << endl;
                    sec[j] = sec[j - d];
                    cout << "Tras el cambio: " << endl;
                    cout << sec[j] << " y " << sec[j - d] << endl;
                    j = j - d;

                    cout << "En este punto tenemos el vector: " << endl;
                    for (int i = 0; i < sec.size(); i++) {
                        cout << sec.at(i) << " ";
                    }
                    cout << endl;
                }
                sec[j] = x;
            }
        }
    } else if (ejecution_trace == 'n') {
        int del = number_cells;
        while (del > 1) {
            del = del / 2;

            int d = 0;
            d = del;
            int n = 0;
            n = number_cells;

            for (int i = d; i < n; i++) {
                int x;
                x = sec[i];
                int j;
                j = i;
                while ((j >= d) && (x < sec[j - d])) {
                    sec[j] = sec[j - d];
                    j = j - d;
                }
                sec[j] = x;
            }
        }
    }
    
    cout << endl;
    cout << "El vector finalmente ordenado es: " << endl;
    for (int i = 0; i < sec.size(); i++) {
        cout << sec.at(i) << " ";
    }
    cout << endl;
};

void clrscr() {
    system("clear");
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
    int write_option = 0;
    cout << "¿Prefiere introducir los valores que quiere ordenar, de manera manueal u aleatoria?" << endl;
    cout << "Si lo prefiere de manera manueal introduza [1], si lo prefiere aleatorio introduzca [2] : ";
    cin >> write_option;

    clrscr();
    vector<int> vector_sort;

    if (write_option == 1) { /// Here starts the programm
        int auxiliary = 0;
        cout << "Para comenzar la ordenación, introduzca los valores que quiere ordenar;" << endl;
        for (int i = 0; i < cells_size; i++) {
            cout << "";
            cin >> auxiliary;
            vector_sort.push_back(auxiliary);
        }

        cout << endl;
        cout << "Finalmente el vector introducido, es el siguiente: " << endl;

        for (int i = 0; i < vector_sort.size(); i++) {
            cout << vector_sort.at(i) << " ";
        }
        cout << endl;

        if (algorithm_option == 1) { 

            Vector_Sort_Insertion<int>(vector_sort, cells_size);
        
        } else if (algorithm_option == 2) {

            Vector_Sort_Quicksort<int>(vector_sort, cells_size);

        } else if (algorithm_option == 3) {

            Vector_Sort_Shellsort<int>(vector_sort, cells_size);
            
        }

    } else if (write_option == 2) {
        int range_min = 1;
        int range_max = 1000;
        int counter = 0;
        int auxiliary = 0;
        cout << "Para comenzar se va a crear un vector de manera aleatoria, con valores entre 1 y 1000" << endl;
        do {
            auxiliary = rand() % (range_max-range_min-1) + range_min;
            vector_sort.push_back(auxiliary);
            counter++;
        } while (counter != cells_size);

        cout << endl;
        cout << "Finalmente el vector creado de manera alaeatoria, es el siguiente: " << endl;

        for (int i = 0; i < vector_sort.size(); i++) {
            cout << vector_sort.at(i) << " ";
        }
        cout << endl;

        if (algorithm_option == 1) {

            Vector_Sort_Insertion<int>(vector_sort, cells_size);

        } else if (algorithm_option == 2) {

            Vector_Sort_Quicksort<int>(vector_sort, cells_size);
            
        } else if (algorithm_option == 3) {

            Vector_Sort_Shellsort<int>(vector_sort, cells_size);

        }

    } 
    exit(1);
};