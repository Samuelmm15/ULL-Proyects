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
#include "list_hash_table.h"
#include "dispersion_fuction.h"
#include "module_hash.h"
#include "pseudorandom_hash.h"

void clrscr() {
    system("clear"); /// con esta función se puede limpiar la pantalla para cada iteraccion del menú
};

void menu(int &option) { /// funcion para la impresion del menú
    cout << "<< BIENVENIDO AL MENÚ DE SELECCIÓN DE LA OPERACIÓN QUE DESEA REALIZAR >>" << endl;
    cout << "1. Introduzca 1 si quiere realizar la búsqueda de valores clave." << endl;
    cout << "2. Introduzca 2 si quiere realizar la inserción de valores clave." << endl;
    cout << "3. Introduzca 3 si desea salir del menú y finalizar la ejecución del programa." << endl; 
    cout << "Introduzca la operación que desea realizar: ";
    cin >> option;
};

int main() { 
    
    cout << "<< BIENVENIDO AL PROGRAMA DE LA TABLA DE HASH >>" << endl;
    int fuction_option = 0;
    cout << "A continuación que función va a utilizar ([1] La función de dispersión módulo o [2] La función de dispersión pseudoaleatoria): ";
    cin >> fuction_option;

    int hash_table_size = 0;
    cout << "Para comenzar introduza el tamaño de la tabla de hash de la cual quiere hacer uso: ";
    cin >> hash_table_size;   
    
    Module_Hash M;
    Pseudorandom_Hash P;  
    Hash_Table<int> H(hash_table_size, fuction_option, M, P); /// incializacion de los valores de la tabla
    List_Hash<int> L(H.getnDates());
    
    /// Menú del programa
    int option = 0;
    do {
        cout << endl;
        menu(option);
        switch(option) {
            case 1 :
                clrscr();
                if (H.vDates_created == 0) {
                    cout << "La tabla de Hash todavía no ha sido creada." << endl;
                    cout << "Seleccione la opción 2 para poder crear la tabla y añadir las claves que considere." << endl;
                } else if (H.vDates_created == 1) {
                    int find_key;
                    cout << "Introduzca el valor clave que quiere buscar en la tabla: ";
                    cin >> find_key;
                    bool answer;
                    answer = L.Find_Key_List_Hash(H.getnDates(), find_key);
                    if (H.Find_Key_Hash_Table(answer) == true) {
                        cout << "El valor " << find_key << " ha sido encontrado en la tabla de hash." << endl;
                    } else if (H.Find_Key_Hash_Table(answer) == false) {
                        cout << "El valor " << find_key << " no ha sido encontrado en la tabla de hash." << endl;
                    }
                }
            break;
            case 2 :
                clrscr();
                if (H.vDates_created == 0) {
                    H.vDates_created = 1; /// establecemos que la tabla ha sido creada
                    cout << "La tabla ha sido creada" << endl;
                    H.Create_Table(); /// creamos la tabla
                } else if (H.vDates_created == 1) {
                    int insert_key;
                    cout << "Introduzca el valor clave que quiere introducir dentro de la tabla: ";
                    cin >> insert_key;
                    H.Insert_Key_Hash_Table();
                }
            break;
        }
    } while (option != 3);
    clrscr();
    cout << "Fin del programa" << endl;
    exit(1);
}