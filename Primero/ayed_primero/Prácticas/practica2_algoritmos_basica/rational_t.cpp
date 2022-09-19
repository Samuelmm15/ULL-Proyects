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

#include "rational_t.hpp" /// incluimos el fichero .h relacionado con este fichero

rational_t::rational_t(const int n, const int d) /// función que se encarga de establecer los valores del denominador y del numerador
{
  assert(d != 0); /// si se produce que el denominador es distinto de cero, entonces establecemos los valores del numerador y del denominador
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline /// etiqueta inline para el compilador
int
rational_t::get_num() const /// obtenemos el numerador
{
  return num_;
}



inline /// etiqueta inline para el compilador
int
rational_t::get_den() const /// obtenemos el denominador
{
  return den_;
}


  
void
rational_t::set_num(const int n) /// establecemos que n es el numerador de la operacion
{
  num_ = n;
}


  
void
rational_t::set_den(const int d) /// estblecemos que d es el denominador de la operacion en el caso que este sea distinto de cero
{
  assert(d != 0);
  den_ = d;
}



inline /// etiqueta inline para el compilador
double
rational_t::value() const
{ 
  return double(get_num()) / get_den(); /// función que se encarga de realizar la operacion del racional del numerador entre el denominador
}



rational_t 
rational_t::opposite() const /// función que se encarga de realizar el contrario el oposite del racional
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const /// función que se encagra de hacer el reciproco del racional, es decir, buscar lo qie es esto en internet
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const /// comparacion de dos racionales para ver si son iguales
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const /// comparación de dos racionales para ver quien es mayor
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const /// comparación de dos racionales para ver quien es menor
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const /// calculo de la operación suma de dos racionales
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r) const /// calculo de la operación resta de dos racionales
{
  return add(r.opposite()); /// para ello usamos el opuesto del racional, porque este es negativo y por tanto se realiza la resta
} /// hacemos una suma



rational_t
rational_t::multiply(const rational_t& r) const /// funcion que calcula el producto de dos racionales
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den()); 
}



rational_t
rational_t::divide(const rational_t& r) const /// funcion que calcula la divisón de dos racionales
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
rational_t
operator+(const rational_t& a, const rational_t& b) /// función que se encarga de calcular la suma de dos racionales
{
  return rational_t((a.get_num() * b.get_den()) + (a.get_den() * b.get_num()), (a.get_den() * b.get_den())); /// operador suma sobrecargado
} /// con todo esto hay que hacer uso de las funciones anteriores para poder implementar todo esto



rational_t
operator-(const rational_t& a, const rational_t& b) /// función que se encarga de calcular la resta de dos racionales
{
  return rational_t((a.get_num() * b.get_den()) - (a.get_den() * b.get_num()), (a.get_den() * b.get_den())); /// operador sobrecargado
}



rational_t
operator*(const rational_t& a, const rational_t& b) /// función que se encarga de calcular el producto de dos racionales
{
  return rational_t(a.get_num() * b.get_num(), a.get_den() * b.get_den()); /// operador sobrecargado
}



rational_t
operator/(const rational_t& a, const rational_t& b) /// función que se encarga de realizar la división de dos racionales
{
  return rational_t(a.get_num() * b.get_den(), a.get_den() * b.get_num()); /// operador sobrecargado
}



// E/S
void
rational_t::write(ostream& os) const /// todas las funciones que hay a continuación se encargan de los flujos de entrada y salida de las funciones racionales
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}


istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}