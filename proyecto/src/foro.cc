#include "../library/foro.h"

void MenuForo() {
  Foro foro;
  int option = 5;
  while (option != 0) {
    std::cout << "1. Mostrar discusiones" << std::endl;
    std::cout << "2. Seleccionar discusión" << std::endl;
    std::cout << "3. Crear discusión" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cin >> option;
    switch (option) {
      case 1:
        foro.MostrarDiscusiones();
        break;
      case 2:
        foro.SeleccionarDiscusion();
        break;
      case 3:
        foro.CrearDiscusion();
        break;
      case 0:
        return;
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
}

Foro::Foro() {
  std::string ruta = "../base_de_datos/foro";
  for (const auto & entry : std::filesystem::directory_iterator(ruta)) {
    std::string file = entry.path();
  }
}

void Foro::MostrarDiscusiones() {
  for (int i = 0; i < discusiones_.size(); i++) {
    std::cout << i << ". " << discusiones_[i].GetTema() << std::endl;
  }
}

void Foro::SeleccionarDiscusion() {
  MostrarDiscusiones();
  std::cout << "Selecciona una discusión: ";
  int index;
  std::cin >> index;
  std::cout << "Discusión seleccionada: " << discusiones_[index].GetTema() << std::endl;
  int option = 5;
  while (option != 0) {
    std::cout << "1. Leer discusión" << std::endl;
    std::cout << "2. Escribir mensaje" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cin >> option;
    switch (option) {
      case 1:
        discusiones_[index].Leer();
        break;
      case 2:
        discusiones_[index].Escribir();
        break;
      case 0:
        return;
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
}

void Foro::CrearDiscusion() {
  std::string tema;
  std::cout << "Introduce el tema de la discusión: ";
  std::cin >> tema;
  std::string ruta = "../base_de_datos/foro/" + tema + ".txt";
  std::ofstream file(ruta);
  Discusion discusion(tema, ruta);
  discusiones_.push_back(discusion);
  std::cout << "Discusión creada" << std::endl;
}