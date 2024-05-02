#pragma once

#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>

#include "../library/discusion.h"
#include "../library/usuario.h"

#define GREEN "\033[32m"
#define RESET "\033[0m"

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