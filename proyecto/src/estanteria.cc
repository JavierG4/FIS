#include "estanteria.h"

void Estanteria::generarCatalogo(const std::string& path) {
  nombres_archivos_.clear();

  for (const auto& entry : std::filesystem::directory_iterator(path)) {
    if (entry.is_regular_file()) {
      std::string nombreArchivo = entry.path().filename().string();
      nombres_archivos_.push_back(nombreArchivo);
    }
  }
}

void Estanteria::imprimirCatalogo() {
  if (!nombres_archivos_.empty()) {
    std::cout << "** Catálogo de archivos **" << std::endl;
    for (const auto& nombreArchivo : nombres_archivos_) {
      std::cout << "- " << nombreArchivo << std::endl;
    }
  } else {
    std::cout << "No se encontraron archivos en la carpeta." << std::endl;
  }
}
