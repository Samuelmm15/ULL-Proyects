#include <iostream>

using namespace std;

void comparation(float number1,float number2) {
    if (number1 == number2) {
        cout << endl;
        cout << "Los dos números reales introducidos son igales" << endl;
    } else if (number1 > number2) {
        cout << endl;
        cout << "El primer número introducido es mayor que el segundo" << endl;
        cout << "El segundo número introducido es menor que el primero" << endl;
    } else if (number1 < number2) {
        cout << endl;
        cout << "El segundo número introducido es mayor que el primero" << endl;
        cout << "El primer número introducido es menor que el segundo" << endl;
    }
};


int main() {
    
    float number1;
    float number2;
    
    cout << "Introduzca un número real a través del teclado para comparar: ";
    cin >> number1;
    cout << endl;
    cout << "Introduzca el otro número real a través del teclado: ";
    cin >> number2;
    
    comparation(number1, number2); /// accedemos a la función para comparar los valores
    exit(1);
}
