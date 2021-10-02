// AUTOR: Samuel Martín Morales
// FECHA: 02/05/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&); /// para meter valores en la pila
  void pop(void); /// para borrar valores de la pila
  const T& top(void) const; /// para obtener el valor que está encima de la pila
  bool empty(void) const; /// para comprobar si la pila está vacía

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
  int min_(void) const;
  int max_(void) const;
};


// operaciones
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
  std::cout << "Mínimo elemento en la pila: " << min_() << std::endl;
  std::cout << "Máximo elemento en la pila: " << max_() << std::endl;
}

template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

template<class T> 
int stack_l_t<T>::min_(void) const {
  dll_node_t<T>* aux = l_.get_head();
  int comparation = 10000000;
  while (aux != NULL) {
   if (comparation >= aux->get_data()) {
      comparation = aux->get_data();
    } 
    aux = aux->get_next();
  }
  if (comparation == 10000000) {
    return 0;
  }
  return comparation;
};

template<class T>
int stack_l_t<T>::max_(void) const {
  dll_node_t<T>* aux = l_.get_head();
  int comparation = -100000000;
  while (aux != NULL) {
    if (comparation <= aux->get_data()) {
      comparation = aux->get_data();
    } 
    aux = aux->get_next();
  } 
  if (comparation == -100000000) {
    return 0;
  }
  return comparation;
};


#endif  // STACKL_H_
