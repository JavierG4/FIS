#pragma once

#include <filesystem>
#include <iostream>
#include "../library/discusion.h"
#include <vector>
#include <fstream>

void MenuForo();

class Foro {
 public:
   Foro();
   void MostrarDiscusiones();
   void CrearDiscusion();
   void SeleccionarDiscusion();
 private:
   std::vector<Discusion> discusiones_;
};