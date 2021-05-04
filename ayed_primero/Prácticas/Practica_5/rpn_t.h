// AUTOR: Samuel Martín Morales
// FECHA: 02/05/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
  stack_l_t<int> W;
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      
      // poner código
      W.push(i);

      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      
      // poner código
      operate_(c);
    }
  }
  // poner código
  int solution = 0;
  solution = W.top();
  W.pop();
  return solution;
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/');
  
  int x = 0;
  int y = 0;
  int solution = 0;
  // poner código
  x = W.top();
  W.pop();
  std::cout << "   Sacamos de la pila un operando: " << x << std::endl;
  
  // poner código
  y = W.top();
  W.pop();
  std::cout << "   Sacamos de la pila otro operando: " << y << std::endl;
  
  switch (c) {
    case '+':
      // poner código
      solution = y + x;
      break;
      // poner código resto de operadores
    case '-':
      solution = y - x;
      break;
    case '*':
      solution = y * x;
      break;
    case '/':
      solution = y / x;
      break;
  }

  // poner código
  W.push(solution);
  std::cout << "   Metemos en la pila el resultado: " << solution << std::endl;
  solution = 0;
  x = 0;
  y = 0;
}

 
#endif  // RPNT_H_
