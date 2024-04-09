#include "seguridad.h"

#include <string>

std::string Seguridad::encryptCaesarCipher(std::string text, int key) {
  for (size_t i = 0; i < text.size(); ++i) {
    if (isalpha(text[i])) {
      char offset = isupper(text[i]) ? 'A' : 'a';
      text[i] = static_cast<char>((text[i] - offset + key) % 26 + offset);
    }
  }
  return text;
}

std::string Seguridad::decryptCaesarCipher(std::string text, int key) {
  return encryptCaesarCipher(text, 26 - key);
}

bool Seguridad::Sign_in(std::string username, std::string password, Usuario& user) {
  std::ifstream file("../base_de_datos/seguridad/user.txt");
  std::string line;
  while (getline(file,line)) {
    std::ifstream(line);
    std::string username1;
    line >> username1;
    if (username1 == username) {
      std::cout << "Ya existe ese usuario o alguien con ese username " << std::endl;
      return false;
    }
  }
  std::cout << "No existe nadie con ese username" << std::endl;
  std::cout << "Es necesario que escribas unos datos para completar tu ficha técnica" << std::endl;
  int id = Search_id();
  std::string nombre;
  std::string apellidos;
  std::string mail;
  std::string mail1;
  std::cout << "Escribe tu correo " << std::endl;
  std::cin >> mail;
  std::cout << "Vuelve a escribir tu correo para comprobar " << std::endl;
  std::cin >> mail1;
  while (mail1 != mail) {
    std::cout << "Has escrito dos correos diferentes" << std::endl;
    std::cout << "Escribe tu correo " << std::endl;
    std::cin >> mail;
    std::cout << "Vuelve a escribir tu correo para comprobar " << std::endl;
    std::cin >> mail1;
  }
  std::cout << "Escriba su nombre sin apellidos" << std::endl;
  std::cin >> nombre;
  std::cout << "Escriba sus apellidos" << std::endl;
  std::cin >> apellidos;

  //Creación del usuario
  user.set_apellidos(apellidos);
  user.set_email(mail1);
  user.set_id(id);
  user.set_nombre(nombre);
  user.set_username(username);
}

bool MenuSeguridad(Usuario& user) {
  std::cout << "Buenos días! " << std::endl;
  bool resultado = false;
  int contador = 0;
  int decision = 2;
  while (decision != 1 ||decision != 0 ) { 
    std::cout << "Desea iniciar sesión o registrarse / 0 = (log in) / 1 = (sign in) " << std::endl;
  }
  if ( decision == 0 ) { // log in
    while (resultado == false || contador < 3 ) { 
      std::string username;
      std::cout << "Escriba su usuario " << std::endl;
      std::cin >> username;
      std::string password;
      std::cout << "Escriba su contraseña" << std::endl;
      std::cin >> password;
      resultado = Log_in(username, password, user);
      contador++;
    }
    std::cout << "Te has quedado sin intentos" << std::endl;
  } else {
    std::string username;
    std::cout << "Escriba su usuario " << std::endl;
    std::cin >> username;
    std::string password;
    std::cout << "Escriba su contraseña" << std::endl;
    std::cin >> password;
    resultado = Sign_in(username, password, user);
  }
}
