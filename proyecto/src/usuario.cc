#include "usuario.h"

Usuario::Usuario() {
  id_ = 0;
  username_ = "";
  nombre = "";
  apellidos_ = "";
  email_ = "";
  reservas_ = {};
}

Usuario::Usuario(int id, std::string username, std::string nombre, std::string apellidos, std::string email) {
  id_ = id;
  username_ = username;
  nombre = nombre;
  apellidos_ = apellidos;
  email_ = email;
  reservas_ = {};
}


std::ostream& operator<<(std::ostream& out, const Usuario& usuario) {
  out << usuario.id_ << " "
      << usuario.username_ << " "
      << usuario.nombre << " "
      << usuario.apellidos_ << " "
      << usuario.email_;
  for (const auto& reserva : usuario.reservas_) {
    out << " " << reserva;
  }
  return out;
}

std::istream& operator>>(std::istream& in, Usuario& usuario) {
  in >> usuario.username_
      >> usuario.nombre
      >> usuario.apellidos_
      >> usuario.email_
      >> usuario.id_;
  int reserva;
  while (in >> reserva) {
    usuario.reservas_.push_back(reserva);
  }
  return in;
}
