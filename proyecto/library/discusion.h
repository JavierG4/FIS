#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>

class Discusion{
 public:
   Discusion(std::string, std::string);
   void Leer();
   void Escribir();
   std::string GetTema() { return tema_; }
   std::string GetRuta() { return ruta_; }

 private:
   std::string tema_;
   std::string ruta_;
};