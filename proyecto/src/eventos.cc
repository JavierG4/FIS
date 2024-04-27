#include "eventos.h"

#include <iostream>
#include <fstream>
#include <sstream>

#define COLOR_VERDE  "\033[32m"
#define COLOR_VIOLET  "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_RESET   "\033[0m"

Eventos::Eventos() {
  std::string ruta = "../base_de_datos/eventos/eventos.txt";
  std::ifstream file(ruta);
  std::string linea;
  while (getline(file, linea)) {
    std::istringstream iss(linea);
    std::vector<std::string> evento;
    std::string parte;
    while (getline(iss, parte, ',')) {
      evento.push_back(parte);
    }
    lista_eventos_.push_back(evento);
  }
  file.close();
}
bool Eventos::apuntarse(Usuario& usuario) {
  std::cout << "Escriba el nombre del evento al que desea apuntarse: ";
  std::string nombre_del_evento;
  std::getline(std::cin, nombre_del_evento);
  for (auto& evento : lista_eventos_) {
    if (evento[0] == nombre_del_evento && std::stoi(evento[3]) < std::stoi(evento[2])) {
      evento[3] = std::to_string(std::stoi(evento[3]) + 1);
      std::string ruta_reserva = "../base_de_datos/usuarios/" + usuario.get_username() + "/" + "evento_" + nombre_del_evento +  ".txt";
      std::ofstream archivo(ruta_reserva);
      if (archivo.is_open()) {
        archivo << "Nombre del evento: " << nombre_del_evento << std::endl;
        archivo << "Fecha evento: " << evento[1];
        archivo.close();
      } else {
        std::cout << "No se pudo abrir el archivo para guardar la reserva." << std::endl;
      }
      return true;  
    }
  }
  return false;  
}
void Eventos::mostrar() {
  std::cout << COLOR_VIOLET << "Eventos de la biblioteca 📖"<< COLOR_RESET << std::endl;
  for (const auto& evento : lista_eventos_) {
    std::cout << COLOR_CYAN << "Evento: " << COLOR_RESET << evento[0]
              << ", " << COLOR_VERDE << "Fecha: " << COLOR_RESET << evento[1]
              << ", " << COLOR_VERDE <<  "Aforo: " << COLOR_RESET << evento[3]
              << "/" << evento[2] << std::endl;
  }
}

void Eventos::guardar_eventos() {
  std::string ruta = "../base_de_datos/eventos/eventos.txt";
  std::ofstream file(ruta);
  for (const auto& evento : lista_eventos_) {
    file << evento[0] << "," << evento[1] << "," << evento[2] << "," << evento[3] << std::endl;
  }
  file.close();
}
