#pragma once

#include <iostream>
#include "discusiones.h"

class Foro {
 public:
   Foro();
   void MostrarDiscusiones();

 private:
   std::vector<Discusion> discusiones_;
};