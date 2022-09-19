// AUTOR: Samuel Martín Morales
// FECHA: 04/03/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t /// clase de una matriz
{
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); /// multiplicación de matrices
  void add(const matrix_t<T>&); /// suma de las filas pares de una matriz, y guardar en vector dicha suma

  void write(ostream& = cout) const; /// flujos de lectura y escritura
  void read(istream& = cin);

private:
  int m_, n_; // m_ filas y n_ columnas 
  vector_t<T> v_; /// hacemos uso de la clase y funcion vector
  
  int pos(const int, const int) const; /// variable posición de la matriz
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n) /// constructor de la matriz
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t() /// destructor de la matriz
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n) /// función para poder establecer un resize de la matriz
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const /// obtener el valor de las filas o el numero de filas
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const /// obtener el numero de columnas
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j) /// poder escribir las matrices por pantalla
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j) /// esta es la funcion que hay que usar para esto anterior
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const /// estas dos funciones son iguales que las anteriores, pero para valores constantes
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const /// funciones de flujos de lectura y escritura por pantalla
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const /// obtener posiciones de las matrices
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) /// realizar la multiplicacion de dos matrices
{

  assert(A.get_n() == B.get_m()); /// comprobamos esta condición
  resize(A.get_m(), B.get_n()); /// Realizamos un resize de la matriz
  for (int i = 1; i <= A.get_m(); i++) { /// Fila de la matriz A
    for (int j = 1; j <= B.get_n(); j++) { /// Columna de la matriz B
      at(i,j) = 0;
      for (int k = 1; k <= A.get_n(); k++ ) { /// Columna de la matriz A
        at(i,j) = at(i,j) + (A.at(i,k) * B.at(k,j));
      }
    }
  } 

}

template<class T>
void
matrix_t<T>::add(const matrix_t<T>& B)
{
  vector_t<double> add; /// vector de la suma
  double suma = 0; /// suma de los valores de la fila de la matriz
  int counter = 0;

  add.resize(B.get_m());
  
  for (int i = 1; i <= B.get_m(); i++) {
    for (int j = 1; j <= B.get_n(); j++) {
      if (i%2 == 0) {
        suma = suma + B.at(i,j);
      }
    }
    if (i%2 == 0) {
      counter++;
      add.at(counter) = suma;
      cout << add.at(counter) << " ";
    }
  }
  cout << endl;
}