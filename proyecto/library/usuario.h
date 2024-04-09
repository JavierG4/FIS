// File: usuario.h
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>

class Usuario {
 public:
   //Constructores
   Usuario();
   Usuario(int, std::string, std::string, std::string, std::string);

   //Getters
   int get_id() { return id_; }
   std::string get_username() { return username_; }
   std::string get_nombre() { return nombre; }
   std::string get_apellidos() { return apellidos_; }
   std::string get_email() { return email_; }
   std::vector<int> get_reservas() { return reservas_; }

    //Setters
   void set_id(int id) { id_ = id; }
   void set_username(std::string username) { username_ = username; }
   void set_nombre(std::string nombre) { nombre = nombre; }
   void set_apellidos(std::string apellidos) { apellidos_ = apellidos; }
   void set_email(std::string email) { email_ = email; }
   void set_reservas(std::vector<int> reservas) { reservas_ = reservas; }

   //Metodos

   //E/S
   friend std::ostream& operator<<(std::ostream&, const Usuario&);
   friend std::istream& operator>>(std::istream& in, Usuario& usuario);
 private:
   int id_;
   std::string username_;
   std::string nombre;
   std::string apellidos_;
   std::string email_;
   std::vector<int> reservas_; // Reservas no int es para que no de error
  
};