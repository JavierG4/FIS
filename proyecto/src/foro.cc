#include "../library/foro.h"

void MenuForo(Usuario& user) {
  Foro foro;
  int option = 5;
  while (option != 0) {
    std::cout << GREEN << "\nForo:\n" << RESET;
    std::cout << "\t(0) Salir" << std::endl;
    std::cout << "\t(1) Mostrar discusiones" << std::endl;
    std::cout << "\t(2) Seleccionar discusión" << std::endl;
    std::cout << "\t(3) Crear discusión" << std::endl;
    std::cin >> option;
    switch (option) {
      case 1:
        system("clear");
        foro.MostrarDiscusiones();
        break;
      case 2:
        system("clear");
        foro.SeleccionarDiscusion(user);
        break;
      case 3:
        system("clear");
        foro.CrearDiscusion();
        break;
      case 0:
        system("clear");
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
    std::string tema = file.substr(file.find_last_of("/") + 1); // Obtiene el nombre del archivo
    tema = tema.substr(0, tema.find(".")); // Elimina la extensión del archivo
    discusiones_.push_back(Discusion(tema, file));
  }
}

void Foro::MostrarDiscusiones() {
  for (int i = 0; i < discusiones_.size(); i++) {
    std::cout << "Discusión " << i << " " << discusiones_[i].GetTema() << std::endl;
  }
}

void Foro::SeleccionarDiscusion(Usuario& usuario) {
  MostrarDiscusiones();
  std::cout << GREEN << "\nSelecciona el número de una discusión: " << RESET;
  int index;
  std::cin >> index;
  std::cout << "Discusión seleccionada: " << discusiones_[index].GetTema() << std::endl;
  int option = 5;
  while (option != 0) {
    std::cout << "\t(0) Salir" << std::endl;
    std::cout << "\t(1) Leer discusión" << std::endl;
    std::cout << "\t(2) Escribir mensaje" << std::endl;
    std::cin >> option;
    switch (option) {
      case 1:
        discusiones_[index].Leer();
        break;
      case 2:
        discusiones_[index].Escribir(usuario);
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