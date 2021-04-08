// AUTOR: Samuel Martín Morales
// FECHA: 04/03/2021
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once 

#include <iostream> /// librería principal del programa
#include <cassert> /// librería para comprobar si se cumple una condición y si se produce que esta no es cierta lanzar un mensaje de error, sobre todo para las zonas de código más peligrosas
#include <cmath> /// librería para realizar operaciones matemáticas

// pauta de estilo [5]
# define EPSILON 1e-6 /// constante que establece una exponencial

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); /// constructor de operacion racional
  ~rational_t() {} /// destructor de los valores de la operacion racional
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const; /// getter para poder obtener el numerador de la división de la parte privada del programa
  int get_den() const; /// getter para poder obtener el denominador de la divisón de la parte privada del programa
  
  // setters
  void set_num(const int); /// setter para poder establecer el valor del numerador para poder realizar la operacion
  void set_den(const int); /// setter para poder establecer el valor del denominador para poder realizar la oepracion

  double value(void) const; /// función que se encarga de realizar la operacion racional con los valores establecidos
  rational_t opposite(void) const; /// función que se encarga de realizar lo contrario de la solución del racional
  rational_t reciprocal(void) const; /// función que se encarga de hacer el reciproco de la racional

  bool is_equal(const rational_t&, const double precision = EPSILON) const; /// función que se encarga de comprobar si dos racionales son iguales o no
  bool is_greater(const rational_t&, const double precision = EPSILON) const; /// función que se encarga de comprobar si dos raciones una es mayor que otra
  bool is_less(const rational_t&, const double precision = EPSILON) const; /// función que se encarga de comprobar si una racional es menor que otra

  rational_t add(const rational_t&) const; /// función que se encarga de realizar la suma de racionales
  rational_t substract(const rational_t&) const; /// función que se encarga de realizar la resta de racionales
  rational_t multiply(const rational_t&) const; /// función que se encarga de realizar multiplicaciones de racionales
  rational_t divide(const rational_t&) const; /// función que se encarga de realizar la divisón de racionales

  void write(ostream& os = cout) const; /// función para poder escribir por pantalla
  void read(istream& is = cin); /// función para poder leer por pantalla
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; /// variables de la racional, numerador y denominador, declarado en privado 
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&); /// con esta sobrecarga hacemos que se sobrecarge un operador de salida
istream& operator>>(istream& is, rational_t&); /// con esta sobrecarga hacemos que sobrecargue un operador de salida

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); /// función del operador suma
rational_t operator-(const rational_t&, const rational_t&); /// función del operador resta
rational_t operator*(const rational_t&, const rational_t&); /// función del operador producto
rational_t operator/(const rational_t&, const rational_t&); /// función del operador división

