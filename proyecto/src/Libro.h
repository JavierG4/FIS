#include <iostream>
#include <string.h> 
using namespace std;

class Libro {
public:
    // constructor
    Libro(string nombre_libro) {
    nombre_libro_ = nombre_libro;
    ruta_archivo_ = "../base_de_datos/repositorio_libros/" + nombre_libro + ".txt";
    cargar_info();
    }

    bool es_disponible() {
        return estado_ == 0;
    }

    void reservar_libro() {
        estado_ = 1;
        guardar_info();
    }

    void devolver_libro() {
        estado_ = 0;
        guardar_info();
    }

    string get_autor() {
        return autor_;
    }

    string get_fecha() {
        return fecha_;
    }

    void mostrar_informacion() {
      cout << "Nombre: " << nombre_libro_ << endl;
      cout << "Autor: " << autor_ << endl;
      cout << "Fecha de publicación: " << fecha_ << endl;
      cout << "Estado: " << (estado_ ? "Reservado" : "Disponible") << endl;
    }

private:
    string nombre_libro_;
    string ruta_archivo_;
    bool estado_;
    string autor_;
    string fecha_;
};
