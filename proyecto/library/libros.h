#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;

class Libro {
public:
    // Constructor
    Libro(string nombre_libro);

    bool es_disponible();
    void reservar_libro();
    void devolver_libro();
    string get_autor();
    string get_fecha();
    string get_nombre();
    string get_ruta_archivo();
    void mostrar_informacion();
    void cargar_info();
    void guardar_info();

    int get_estado();
    
private:
    string nombre_libro_;
    string ruta_archivo_;
    bool estado_;
    string autor_;
    string fecha_;

};

void mostrar_todos_libros();
void mostrar_libros_disponibles();