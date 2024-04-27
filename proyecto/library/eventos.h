#ifndef EVENTOS_H
#define EVENTOS_H

#include <vector>
#include <string>

#include "usuario.h"

class Eventos {
 public:
  Eventos();
  bool apuntarse(Usuario& usuario);
  void mostrar();
  void guardar_eventos();
 private:
  std::vector<std::vector<std::string>> lista_eventos_;
};

#endif