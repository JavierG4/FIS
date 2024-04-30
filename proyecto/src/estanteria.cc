#include "estanteria.h"

void Estanteria::generarCatalogo(const std::string& path) {
  // Limpiar el vector antes de agregar nuevos nombres
  nombres_archivos_.clear();

  // Recorrer la carpeta especificada
  for (const auto& entry : std::filesystem::directory_iterator(path)) {
    // Verificar si la entrada es un archivo regular
    if (entry.is_regular_file()) {
      // Obtener el nombre del archivo
      std::string nombreArchivo = entry.path().filename().string();

      // Agregar el nombre del archivo al vector
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
