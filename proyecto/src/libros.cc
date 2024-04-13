#include "../library/libros.h" 

Libro::Libro(string nombre_libro) {
    nombre_libro_ = nombre_libro;
    ruta_archivo_ = "../base_de_datos/repositorio_libros/" + nombre_libro + ".txt";
    cargar_info();
}

bool Libro::es_disponible() {
    return estado_ == 0;
}

void Libro::reservar_libro() {
    estado_ = 1;
    guardar_info();
}

void Libro::devolver_libro() {
    estado_ = 0;
    guardar_info();
}

string Libro::get_autor() {
    return autor_;
}

string Libro::get_fecha() {
    return fecha_;
}

void Libro::mostrar_informacion() {
    cout << "Nombre: " << nombre_libro_ << endl;
    cout << "Autor: " << autor_ << endl;
    cout << "Fecha de publicación: " << fecha_ << endl;
    cout << "Estado: " << (estado_ ? "Reservado" : "Disponible") << endl;
}

void Libro::cargar_info() {
    ifstream archivo(ruta_archivo_);
    if (archivo.is_open()) {
        archivo >> estado_;
        getline(archivo, autor_);
        getline(archivo, fecha_);
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << ruta_archivo_ << endl;
    }
}

void Libro::guardar_info() {
    ofstream archivo(ruta_archivo_);
    if (archivo.is_open()) {
        archivo << estado_ << endl;
        archivo << autor_ << endl;
        archivo << fecha_ << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << ruta_archivo_ << endl;
    }
}
