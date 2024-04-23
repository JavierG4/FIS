#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "libros.h"

class Estanteria {
public:
  Estanteria();
  ~Estanteria();

  void cargar_catalogo();
  void mostrar_catalogo();
  void listar_archivos();

private:
  std::vector<Libro> catalogo_;
  std::string ruta_archivo_libro_;
};
