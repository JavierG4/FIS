#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>

#include "menu.h"

#include "seguridad.h"
#include "usuario.h"

#include "horario.h"
#include "aulas.h"
#include "info_biblio.h"

int main() {
  std::cout << std::endl;
  // Información de la biblioteca
  get_informacion();
  // Menú
  bool sesioniniciada = false;
  Horario horario;
  std::cout << std::endl << "¡Buenos días!" << std::endl;
  if (MostrarMenu(sesioniniciada)) {
    // Seguridad
    Usuario user;
    Seguridad seguridad;
    bool resultado = seguridad.MenuSeguridad(user);
    if (!resultado) {
      std::cout << "Error de inicio" << std::endl;
    } else {
      // Usuario
      system("clear");
      std::cout << "Bienvenido/a " << user.get_username() << std::endl;
      MenuRegistrado(user, horario);
    }
  }
  //guardar horario, hacer siempre antes de que acabe el programa
  horario.guardar_horario();
  return 0;
}