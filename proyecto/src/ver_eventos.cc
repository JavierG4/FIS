#include "ver_eventos.h"

#include <fstream>
#include <string>
#include <filesystem>

#define STYLE_ITALIC  "\033[3m"
#define COLOR_RESET   "\033[0m"
#define BOLD     "\033[1m" 

void ver_eventos(Usuario& usuario) {
  std::cout << STYLE_ITALIC << BOLD << "\nEVENTOS" << COLOR_RESET << std::endl;
  std::string ruta_evento = "../base_de_datos/usuarios/" + usuario.get_username();
  for (const auto& entry : std::filesystem::directory_iterator(ruta_evento)) {
    auto filename = entry.path().filename().string();
    if (filename.find("evento") == 0)  {
      std::ifstream file(entry.path());
      if (file) { 
        std::string line;
        while (getline(file, line)) {
          std::cout << line << std::endl;
        }
      } else {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
      }
      file.close();
    }
  }
}