#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>

#include "menu.h"

// #include "seguridad.h"
#include "usuario.h"

#include "horario.h"
#include "aulas.h"
#include "info_biblio.h"
#include "eventos.h" //eventos: nuevo
#include "ver_eventos.h" //ver eventos: nuevo
int main() {
  system("clear");
  std::cout << std::endl;
  // Información de la biblioteca
  get_informacion();
  // Menú
  Horario horario;
  Eventos nuevo_evento;
  std::cout << std::endl << "¡Buenos días!" << std::endl;
  MostrarMenu(horario);
  //guardar horario, hacer siempre antes de que acabe el programa
  horario.guardar_horario();
  nuevo_evento.guardar_eventos(); //hacer siempre 
  return 0;
}

// int main() {
//   Eventos nuevo_evento;
//   Usuario user;
//   nuevo_evento.mostrar();
//   if (nuevo_evento.apuntarse(user)) {
//     std::cout << "Te has apuntado al evento" << std::endl;
//   } else {
//     std::cout << "No se ha podido apuntar al evento" << std::endl;
//   }
//   ver_eventos(user);
//   nuevo_evento.guardar_eventos(); //hacer siempre 
//   imprimir_recordatorio(user); //imprime el recordatorio de las aulas, colocar al principio de las opciones
//   return 0;
// }