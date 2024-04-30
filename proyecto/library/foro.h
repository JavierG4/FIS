#pragma once

#include <filesystem>
#include <iostream>
#include "../library/discusion.h"
#include <vector>
#include <fstream>
#include "../library/usuario.h"

class Foro {
 public:
   Foro();
   void MostrarDiscusiones();
   void CrearDiscusion();
   void SeleccionarDiscusion(Usuario& usuario);
 private:
   std::vector<Discusion> discusiones_;
};

void MenuForo(Usuario& user);