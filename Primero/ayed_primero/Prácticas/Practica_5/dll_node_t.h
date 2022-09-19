// AUTOR: Samuel Martín Morales
// FECHA: 02/05/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

// Clase para nodos de listas doblemente enlazadas
template <class T> class dll_node_t {
 public:
  // constructores
  dll_node_t() : prev_(NULL), data_(), next_(NULL) {}  // por defecto
  dll_node_t(const T& data) : prev_(NULL), data_(data), next_(NULL) {}

  // destructor
  ~dll_node_t(void) {}

  // getters & setters
  dll_node_t<T>* get_next(void) const { return next_; } /// para obtener el siguiente nodo
  void set_next(dll_node_t<T>* next) { next_ = next; } /// para establecer el siguiente nodo
  
  dll_node_t<T>* get_prev(void) const { return prev_; } /// para obtener el nodo previo
  void set_prev(dll_node_t<T>* prev) { prev_ = prev; } /// para establecer el nodo previo
  
  const T& get_data(void) const { return data_; } /// para obtener el dato del nodo
  void set_data(const T& data) { data_ = data; } /// para establecer el dato del nodo

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* prev_;
  T data_;
  dll_node_t<T>* next_;
};

  
// E/S
template <class T> std::ostream& dll_node_t<T>::write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_
