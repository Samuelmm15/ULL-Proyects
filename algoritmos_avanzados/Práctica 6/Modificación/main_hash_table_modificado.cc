/**
 * @file main_hash_table.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief The hash table is a tool for the handing and storage of data in secondary memory
 * @version 0.1
 * @date 2021-03-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "hash_table.h"
#include "vector_hash_table.h"
#include "dispersion_fuction.h"
#include "exploration_fuction.h"
#include "module_hash.h"
#include "pseudorandom_hash.h"
#include "lineal_exploration.h"
#include "quadratic_exploration.h"
#include "double_dispersion_exploration.h"
#include "redispersion_exploration.h"
#include "employee.h"

void clrscr() {
    system("clear"); /// To clear the shell for the menu
};

void menu(int &option) { 
    cout << "<< BIENVENIDO AL MENÚ DE SELECCIÓN DE LA OPERACIÓN QUE DESEA REALIZAR >>" << endl;
    cout << "1. Introduzca 1 si quiere realizar la búsqueda de valores clave." << endl;
    cout << "2. Introduzca 2 si quiere realizar la inserción de valores clave." << endl;
    cout << "3. Introduzca 3 si desea salir del menú y finalizar la ejecución del programa." << endl; 
    cout << "Introduzca la operación que desea realizar: ";
    cin >> option;
};

int main() { 
    
    cout << endl;
    cout << "<< BIENVENIDO AL PROGRAMA DE LA TABLA DE HASH >>" << endl;
   
    int hash_table_size = 0;
    cout << "Para comenzar introduzca el tamaño de la tabla de hash de la cual quiere hacer uso: ";
    cin >> hash_table_size;

    clrscr();
    int vector_hash_size = 0;
    cout << "Introduzca el tamaño del vector de la tabla hash del cual quiere hacer uso: ";
    cin >> vector_hash_size;   

    clrscr();
    int fuction_option = 0;
    cout << "A continuación que función va a utilizar ([1] La función de dispersión módulo o [2] La función de dispersión pseudoaleatoria): ";
    cin >> fuction_option;

    clrscr();
    int exploration_fuction_option = 0;
    cout << "Por último introduzca el tipo de función de exploracion la cual va a hacer uso." << endl;
    cout << "Introduzca [1] si quiere hacer uso de la exploración lineal." << endl;
    cout << "Introduzca [2] si quiere hacer uso de la exploración cuadrática." << endl;
    cout << "Introduzca [3] si quiere hacer uso de la doble dispersión." << endl;
    cout << "Introduzca [4] si quiere hacer uso de la redispersión." << endl;
    cout << "Que opción quiere escoger: ";
    cin >> exploration_fuction_option;
    
    Module_Hash<int> M(hash_table_size);
    Pseudorandom_Hash<int> P(hash_table_size);
    Lineal_Exploration<int> L;
    Quadratic_Exploration<int> Q;
    Double_Dispersion_Exploration<int> D;
    Redispersion_Exploration<int> R;
    Hash_Table<int> H(hash_table_size, fuction_option, vector_hash_size, M, P, L, Q, D, R); 
    Vector_Hash<int> V(vector_hash_size);
    Employee<int> E;
    
    /// The menu of the programm
    int option = 0;
    do {
        cout << endl;
        cout << "<< BIENVENIDO AL MENÚ DEL EMPLEADO >>" << endl;
        cout << "Para comenzar, introduzca el número de empleado: ";
        cin >> E.num_of_employee;
        cout << "A continuación, introduzca el nombre del empleado: ";
        cin >> E.nombre;
        cout << "Por último, introduzca el tipo de contrato del empleado: ";
        cin >> E.contrato;
        
        clrscr();
        cout << endl;
        menu(option);
        switch(option) {
            case 1 :
                clrscr();
                if (H.vDates_created == 0) {
                    cout << "La tabla de Hash todavía no ha sido creada." << endl;
                    cout << "Seleccione la opción 2 para poder crear la tabla. " << endl;
                } else if (H.vDates_created == 1) {
                    
                    int find_key = 0;
                    cout << "Introduzca la clave que quiere buscar: ";
                    cin >> find_key;

                    if (H.Find_Key_Hash_Table(find_key, V) == true) {
                          cout << "La clave " << find_key << " ha sido encontrado dentro de la tabla de Hash." << endl;
                    } else if (H.Find_Key_Hash_Table(find_key, V) == false) {   
                        cout << "La clave " << find_key << " no ha sido encontrada dentro de la tabla de Hash." << endl;
                    }
                }
            break;
            case 2 :
                clrscr();
                if (H.vDates_created == 0) {
                    H.vDates_created = 1; 
                    cout << "La tabla ha sido creada" << endl;
                    H.Create_Table(V);
                } else if (H.vDates_created == 1) {

                    int insert_key = 0;
                    cout << "El valor a insertar se trata del número del empleado que se ha introducido anteriormente." << endl;
                    insert_key = E.num_of_employee;
                    
                    int position = 0;
                    if (fuction_option == 1) {
                        position = M(insert_key);
                        if (H.Insert_Key_Hash_Table(insert_key, V, position, exploration_fuction_option) == true) {
                            cout << "La clave " << insert_key << " ha sido insertada con éxito." << endl;
                        } else if (H.Insert_Key_Hash_Table(insert_key, V, position, exploration_fuction_option) == false) {
                            cout << "La clave " << insert_key << " no ha sido insertada." << endl;
                        }
                    } else if (fuction_option == 2) {
                        position = P(insert_key);
                        if (H.Insert_Key_Hash_Table(insert_key, V, position, exploration_fuction_option) == true) {
                            cout << "La clave " << insert_key << " ha sido insertada con éxito." << endl;
                        } else if (H.Insert_Key_Hash_Table(insert_key, V, position, exploration_fuction_option) == false) {
                            cout << "La clave " << insert_key << " no ha sido insertada." << endl;
                        }
                    }
                }
            break;
        }
    } while (option != 3);
    clrscr();
    cout << "Fin del programa" << endl;
    exit(1);
}