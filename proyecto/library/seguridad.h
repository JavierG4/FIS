#include <iostream>
#include <string>
#include <usuario.h>
#include <cstdlib>

class Seguridad {
 public:
   bool Sign_in(std::string, std::string, Usuario&);
   bool Log_in(std::string, std::string, Usuario&);
   std::string decryptCaesarCipher(std::string text, int key);
   std::string encryptCaesarCipher(std::string text, int key);
   int Search_id();
   bool MenuSeguridad(Usuario&);
};



