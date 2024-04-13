#ifndef HORARIO_H
#define HORARIO_H

#include <vector>
#include <iostream>

class Horario {
 public:
  Horario(); //constructor
  void set_estado(int dia, int aula, int sesion, std::string estado); //setter
  std::string get_estado(int dia, int aula, int sesion) const; //getter
  void guardar_horario() const; //guardar_horario
  bool buscar_reserva(const std::string& nombre); //buscar reserva
  friend std::ostream& operator<<(std::ostream& out, const Horario& horario); 
 private:
  std::vector<std::vector<std::string>> horario_biblio_;
  std::string ruta_fichero_ = "../base_de_datos/horario/horario.txt";
};

#endif //HORARIO_H