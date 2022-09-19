#include <string>

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
 public:
  Producto(std::string nombre, int precio, Usuario &usuario) {
    
  }
  int id_;
  int precio_;
  std::string nombre_;
  std::string owner_;
};

#endif