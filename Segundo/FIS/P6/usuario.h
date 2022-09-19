#include <string>
#include <vector>

#include "producto.h"

#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
 public:
  Usuario(std::string nombre, std::string contraseña, std::vector<Producto> productos) {
    nombre_ = nombre;
    contraseña_ = contraseña;
    productos_ = productos;
  }
  void AnadirProducto(Producto producto) {

  }
  void QuitarProducto(int id) {

  }
 private:
  std::string nombre_;
  std::string contraseña_;
  std::vector<Producto> productos_;
};

#endif