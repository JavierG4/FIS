#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include "seguridad.h"
#include "usuario.h"

int main() {
  //Parte 1 Seguridad
  Usuario user;
  Seguridad seguridad;
  bool resultado = seguridad.MenuSeguridad(user);
  if (!resultado) {
    std::cout << "Error de inicio" << std::endl;
    return 0;
  }
}