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

void Discusion::Escribir(Usuario& usuario) {
  Leer();
  std::ofstream file(ruta_, std::ios::app);
  std::string line;
  std::cout << "Escribe tu mensaje: " << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer de std::cin
  std::getline(std::cin, line);
  file << usuario.get_username() << ": " << std::endl;
  file << line << std::endl;
  file << std::endl;
  file.close();
  system("clear");
}