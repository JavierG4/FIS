#include "discusion.h"

Discusion::Discusion(std::string tema, std::string ruta) {
  tema_ = tema;
  ruta_ = ruta;
}

void Discusion::Leer() {
  std::ifstream file(ruta_);
  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }
}

void Discusion::Escribir() {
  Leer();
  std::ofstream file(ruta_, std::ios::app);
  std::string line;
  std::cout << "Escribe tu mensaje: ";
  std::getline(std::cin, line);
  file << line << std::endl;
}