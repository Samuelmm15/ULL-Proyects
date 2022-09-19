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

using namespace std;

template<class T>
class vector_t /// declaración de una clase vector con una plantilla template de nombre T
{
public:
  vector_t(const int = 0); /// constructor del vector
  ~vector_t(); /// destructor del vector
  
  void resize(const int); /// función que se encarga del resize de la función vector
  
  // getters
  T get_val(const int) const; /// getter del valor del vector
  int get_size(void) const; /// getter que se encarga de obtener el valor del tamaño del vector
  
  // setters
  void set_val(const int, const T); /// setter que se encarga de establecer los valores del vector
  
  // getters-setters
  T& at(const int); 
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const; /// función para el flujo de entrada y salida 
  void read(istream& = cin);

private:
  T *v_; /// puntero que apunta al valor del vector
  int sz_; /// tamaño del vector
  
  void build(void); /// funciones de contruir y destruir
  void destroy(void);
};



template<class T>
vector_t<T>::vector_t(const int n) /// función que se encarga de contruir el vector de tamaño n
{ sz_ = n;
  build();
}



template<class T>
vector_t<T>::~vector_t() /// función que se encarga de destruir el vector
{
  destroy();
}



template<class T>
void
vector_t<T>::build() /// función build() usada en el constructor del vector
{
  v_ = NULL;
  if (sz_ != 0) { /// si el tamaño es distinto de cero
    v_ = new T[sz_]; /// creamos un vector dinamico de tamaño sz
    assert(v_ != NULL); /// si se produce que el valor del vector es NULL salimos del programa
  }
}



template<class T>
void
vector_t<T>::destroy() /// función que se encarga de destruir el vector
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0; /// con esto limpiamos el vector, la zona de memoria dinamica
}



template<class T>
void
vector_t<T>::resize(const int n) /// función que se encarga de redimensionar el vector
{
  destroy(); /// lo destruimos lo redimensionamos y lo volvemos a construir
  sz_ = n;
  build();
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const /// función que se encarga de obtener el valor del vector
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
vector_t<T>::get_size() const /// función que se encarga de obtener el valor del tamaño del vector
{
  return sz_;
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d) /// función que se encarga de establecer el valor del vector en determinada posición
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T&
vector_t<T>::at(const int i) /// Función que se encarga de escribir los valores de la posición i del vector
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T&
vector_t<T>::operator[](const int i) /// función que se encarga de usar esa escritura anterior, pero para que se pueda escribir por pantalla es esta funcion la que hay que usar
{
  return at(i);
}



template<class T>
const T&
vector_t<T>::at(const int i) const /// volvemos a implementar las dos funciones anteriores, para lo mismo, pero en esta vez son constantes, gracias al const ese que se ha establecido
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}



template<class T>
void
vector_t<T>::write(ostream& os) const /// funciones para los flujos de entrada y salida
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w) /// producto escalar de dos vectores
{
  assert(v.get_size() == w.get_size());
  T aux = 0;
  T suma = 0;
  for (int i = 0; i < v.get_size(); i++) {
    aux = v.at(i) * w.at(i);
    suma = suma + aux;
  }
  return suma;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) /// producto escalar de dos vectores, pero en esta vez racionales
{
  assert(v.get_size() == w.get_size());
  double aux = 0;
  double suma = 0;
  for (int i = 0; i < v.get_size(); i++) {
    aux = v[i].value() * w[i].value();
    suma = suma + aux;
  }
  return suma;
}

