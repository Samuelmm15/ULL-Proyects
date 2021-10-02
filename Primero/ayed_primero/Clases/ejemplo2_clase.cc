/// Replicar la búsqueda secuencial de un elemento, pero en este caso hacerlo con break

#include<iostream>

using namespace std;

void Search_element(int n, int A, int v) {
    int flag;
    for (int i = 0; i < n; i++) {
        if (A[i] == v) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        cout << v << " ha sido encontrado" << endl;
    } else {
        cout << "El valor buscado no ha sido encontrado" << endl;
    }
};



int main() {

    int n;
    cout << "Introduza el tamaño del vector que quiere recorrer: ";
    cin >> n;
    
    int A[n];
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }

    int number = 0;
    cout << endl;
    cout << "Introduzca el valor a buscar: ";
    cin >> number;
    Search_element(A[n], n, number);
  
}

