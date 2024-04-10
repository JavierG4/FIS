#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include "seguridad.h"
#include "usuario.h"

#include "horario.h"
#include "reserva_aula.h"

int main() {
  //Parte 1 Seguridad
  Usuario user;
  Seguridad seguridad;
  bool resultado = seguridad.MenuSeguridad(user);
  if (!resultado) {
    std::cout << "Error de inicio" << std::endl;
    return 0;
  }

  //Parte 2 Usuario
  std::cout << "Bienvenido " << user.get_username() << std::endl;
  std::cout << user << std::endl; 

  /*Parte horario
  cuando tengamos el menú puede haber dos opciones, solo ver horario o reservar aulas*/
  Horario horario;
  //reservar aulas
  reservar_aula(horario);
  //ver horario 
  std::cout << horario << std::endl;
}