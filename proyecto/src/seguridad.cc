#include "seguridad.h"
#include <filesystem>

std::string Seguridad::encryptCaesarCipher(std::string text, int key) {
  for (size_t i = 0; i < text.size(); ++i) {
    if (isalpha(text[i])) {
      char offset = isupper(text[i]) ? 'A' : 'a';
      text[i] = static_cast<char>((text[i] - offset + key) % 26 + offset);
    } else if (isdigit(text[i])) {
      text[i] = static_cast<char>(((text[i] - '0' + key) % 10) + '0');
    }
  }
  return text;
}

std::string Seguridad::decryptCaesarCipher(std::string text, int key) {
  for (size_t i = 0; i < text.size(); ++i) {
    if (isalpha(text[i])) {
      char offset = isupper(text[i]) ? 'A' : 'a';
      text[i] = static_cast<char>((text[i] - offset + 26 - key) % 26 + offset);
    } else if (isdigit(text[i])) {
      text[i] = static_cast<char>(((text[i] - '0' + 10 - key) % 10) + '0');
    }
  }
  return text;
}
bool Seguridad::Sign_in(std::string username, std::string password, Usuario& user) {
  
  // Comprobar si ya existe el usuario
  std::ifstream file("../base_de_datos/seguridad/user.txt");
  std::string line;
  while (getline(file,line)) {
    std::istringstream iss(line);
    std::string username1;
    iss >> username1;
    //std::cout << username1 << " " << username << std::endl;
    if (username1 == username) {
      system("clear");
      std::cout << "Ya existe ese usuario o alguien con ese username " << std::endl;
      return false;
    }
  }
  file.close();

  //Toma de datos de usuario
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
  std::cout << "Escriba su primer apellido" << std::endl;
  std::cin >> apellidos;

  //Creación del usuario
  user.set_apellidos(apellidos);
  user.set_email(mail1);
  user.set_id(id);
  user.set_nombre(nombre);
  user.set_username(username);

  // Crear el txt de usuario nuevo
  std::string directory = "../base_de_datos/usuarios/" + username + "/";
  std::filesystem::create_directories(directory);
  std::string filename = "../base_de_datos/usuarios/" + username + "/" + username + ".txt";
  std::ofstream userFile(filename);

  // Añadir datos al archivo
  userFile << username << "\n";
  userFile << nombre << "\n";
  userFile << apellidos << "\n";
  userFile << mail1 << "\n";
  userFile <<  id << "\n";

  // Cerrar el archivo cuando hayas terminado
  userFile.close();

  //Se añade al fichero user.txt el nuevo
  std::ofstream out("../base_de_datos/seguridad/user.txt", std::ios_base::app);
  out << username << " ";
  std::string final_passwd = encryptCaesarCipher(password, user.get_id());;
  out << final_passwd << "\n";
  out.close();
  std::system("clear");
  return true;
}

bool Seguridad::MenuSeguridad(Usuario& user) {
  std::cout << "Buenos días! " << std::endl;
  bool resultado = false;
  int contador = 0;
  int decision = -1;
  do {
    std::cout << "Seleccione la opción que desea realizar:\n"
              //<< "(0) Salir\n"
              << "(0) Iniciar sesión\n" 
              << "(1) Registrarse" << std::endl;
    std::cin >> decision;
    system("clear");
    if (std::cin.fail()) {
        std::cin.clear(); // limpia el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta la entrada incorrecta
        decision = -1;
    }
  } while (decision != 0 && decision != 1);
  if ( decision == 0 ) { // log in
    while (resultado == false && contador < 3 ) { 
      std::string username;
      std::cout << "Escriba su usuario " << std::endl;
      std::cin >> username;
      std::string password;
      std::cout << "\nEscriba su contraseña" << std::endl;
      std::cin >> password;
      resultado = Log_in(username, password, user);
      contador++;
    }
    if (resultado == false) {
      std::cout << "\nTe has quedado sin intentos" << std::endl;
      return false;
    } else {
      return true;
    }
  } else {
    std::string username;
    std::cout << "Escriba su usuario " << std::endl;
    std::cin >> username;
    std::string password = "";
    std::string password1 = "e";
    while (password != password1) { // sign in (registro
      std::cout << "\nEscriba su contraseña" << std::endl;
      std::cin >> password;
      std::cout << "\nEscriba su contraseña de nuevo" << std::endl;
      std::cin >> password1;
    }
    resultado = Sign_in(username, password, user);
    return resultado;
  }
}

int Seguridad::Search_id() {
  std::ifstream file("../base_de_datos/seguridad/id.txt");
  int numero;
  file >> numero;
  file.close();
  std::ofstream file1("../base_de_datos/seguridad/id.txt");
  file1 << numero + 1;
  file1.close();
  return numero;
}

bool Seguridad::Log_in(std::string username, std::string password, Usuario& user) {
  std::ifstream file("../base_de_datos/seguridad/user.txt");
  std::string line;
  std::string filename = "../base_de_datos/usuarios/" + username + "/" + username + ".txt";
  std::ifstream userFile(filename);
  if(!userFile.is_open()) {
    std::cout << "\nUsuario inexistente\n" << std::endl;
    return false;
  }
  userFile >> user;
  while (getline(file,line)) {
    std::istringstream iss(line);
    std::string username1;
    iss >> username1;
    if (username1 == username) {
      std::string password1;
      iss >> password1;
      std::string final_passwd = encryptCaesarCipher(password, user.get_id());
      //std::cout << user.get_id() << std::endl;
      //std::cout << final_passwd << std::endl;
      //std::cout << password1 << std::endl;
      //std::cout << password << std::endl;
      if (password1 == final_passwd) {
        std::cout << "\nHas iniciado sesión" << std::endl;
        return true;
      } else {
        std::cout << "\nContraseña incorrecta\n" << std::endl;
        return false;
      }
    }
  }
  std::cout << "\nNo existe ese usuario" << std::endl;
  return false;
}