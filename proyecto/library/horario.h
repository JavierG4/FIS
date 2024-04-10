#ifndef HORARIO_H
#define HORARIO_H

#include <vector>
#include <iostream>

class Horario {
 public:
  Horario(); //constructor
  void set_estado(int dia, int aula, int sesion, std::string estado); //setter
  std::string get_estado(int dia, int aula, int sesion) const; //getter
  friend std::ostream& operator<<(std::ostream& out, const Horario& horario); //imprimir
 private:
  std::vector<std::vector<std::string>> horario_biblio_;
};

#endif // HORARIO_H