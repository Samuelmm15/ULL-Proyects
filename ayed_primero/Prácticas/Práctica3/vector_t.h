// AUTOR: Samuel Martín Morales
// FECHA: 30/03/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream> /// librería estándar de c++
#include <cassert> /// librería para salir de aquellas funciones en las que se puede producir algun fallo y es necesario detectarlo

template<class T> class vector_t { /// clase vector
 public:
  // constructores
  vector_t(const int = 0);
  vector_t(const vector_t&); // constructor de copia

  // operador de asignación
  vector_t<T>& operator=(const vector_t<T>&); /// sobrecarga del operador asignación

  // destructor
  ~vector_t(); 
  
  // getters
  T get_val(const int) const; /// obtener el valor del vector
  int get_size(void) const; /// obtener el tamaño del vector
  
  // setters
  void set_val(const int, const T); /// establecer un valor a cierta posición del vector
  
  // getters-setters
  T& at(const int); /// sobrecarga de la operación at
  T& operator[](const int); /// sobrecarga del operador []
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void resize(const int); /// para la realización de la redimensión del vector
  
  // E/S
  void read(std::istream& = std::cin); /// para las operaciones de lectura y escritura del vector
  void write(std::ostream& = std::cout) const;

 private:
  T *v_; /// posición del vector
  int sz_; /// tamaño del vector
  
  void build(void); /// para construir el vector
  void destroy(void); /// para destruir el vector
};


template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) { /// construcción del vector
  build();
}

// constructor de copia
template<class T> vector_t<T>::vector_t(const vector_t<T>& w) /// una copia de la construcción del vector
    : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) { /// sobrecarga del operador de asignación
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

template<class T> vector_t<T>::~vector_t() { /// destructor del vector
  destroy();
}

template<class T> void vector_t<T>::build() { /// construcción del vector
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template<class T> void vector_t<T>::destroy() { /// destrucción del vector
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T> void vector_t<T>::resize(const int n) { /// para redimensionar el vector
  destroy();
  sz_ = n;
  build();
}

template<class T> inline T vector_t<T>::get_val(const int i) const { /// para obtener el valor de cierta posición del vector
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> inline int vector_t<T>::get_size() const { /// para obtener el tamaño del vector
  return sz_;
}

template<class T> void vector_t<T>::set_val(const int i, const T d) { /// para establecer un valor dentro de una posición del vector
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template<class T> T& vector_t<T>::at(const int i) { /// sobrecarga de la operación at
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> T& vector_t<T>::operator[](const int i) { /// sobrecarga del operador []
  return at(i);
}

template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

template<class T> void vector_t<T>::read(std::istream& is) { /// ooperación de lectura
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

template<class T> void vector_t<T>::write(std::ostream& os) const { /// operación de escritura
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) { /// sobrecarga del operador >>
  v.read(is);
  return is;
}

template<class T> std::ostream& operator<<(std::ostream& os, /// sobrecarga del operador <<
					   const vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
