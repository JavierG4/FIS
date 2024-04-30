#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

class Estanteria {
private:
  // Vector para almacenar los nombres de archivo
  std::vector<std::string> nombres_archivos_;

public:
  // Constructor por defecto
  Estanteria() = default;
  
  void generarCatalogo(const std::string& path);
  void imprimirCatalogo();
};