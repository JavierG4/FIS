#pragma once
#include <iostream>

class Discusion{
 public:
   Discusion(std::string);
   void Leer();
   void Escribir();

 private:
   std::string tema_;
   std::string ruta_;
};