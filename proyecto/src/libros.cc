#include "../library/libros.h"

using namespace std;

Libro::Libro(string nombre_libro) {
    nombre_libro_ = nombre_libro;
    ruta_archivo_ = "../base_de_datos/repositorio_libros/" + nombre_libro + ".txt";
    cargar_info();
}

bool Libro::es_disponible() {
    return estado_ == 0;
}

int Libro::get_estado() {
    return estado_;
}

void Libro::reservar_libro() {
    if (estado_ == 0) { // Validación de disponibilidad
        cout << "El libro está disponible." << endl;

        cout << "¿Desea reservar el libro? (s/n): ";
        char respuesta;
        cin >> respuesta;

        switch (respuesta) {
            case 's':
                estado_ = 1; // Reservar libro
                guardar_info();
                cout << "El libro ha sido reservado. \n" << endl;
                break;
            case 'n':
                cout << "La reserva del libro ha sido cancelada. \n" << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } else {
        cout << "El libro está reservado o no existe." << endl;
    }
}

void Libro::devolver_libro() {
    if (estado_ == 1) { // Validación de estado
        cout << "El libro está reservado." << endl;

        cout << "¿Desea devolver el libro? (s/n): ";
        char respuesta;
        cin >> respuesta;

        switch (respuesta) {
            case 's':
                estado_ = 0; // Devolver libro
                guardar_info();
                cout << "El libro ha sido devuelto." << endl;
                break;
            case 'n':
                cout << "La devolución del libro ha sido cancelada." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } else {
        cout << "El libro no está reservado o no existe." << endl;
    }
}

string Libro::get_autor() {
    return autor_;
}

string Libro::get_fecha() {
    return fecha_;
}

string Libro::get_ruta_archivo() {
    return ruta_archivo_;
}

void Libro::mostrar_informacion() {
    cout << "Nombre: " << nombre_libro_ << endl;
    cout << "Autor: " << autor_ << endl;
    cout << "Disponibilidad: " << (estado_ ? "Reservado" : "Disponible") << endl;
}

void Libro::cargar_info() {
    ifstream archivo(ruta_archivo_);
    if (archivo.is_open()) {
        archivo >> estado_;
        getline(archivo, autor_);
        getline(archivo, autor_);
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << ruta_archivo_ << endl;
    }
}

void Libro::guardar_info() {
    string linea_estado = to_string(estado_);
    string linea_autor = autor_ + "\n" + fecha_;

    // Abrir el archivo en modo truncamiento y escritura
    ofstream archivo(ruta_archivo_, ios::trunc);
    if (archivo.is_open()) {
        archivo << linea_estado << endl;
        archivo << linea_autor;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << ruta_archivo_ << endl;
    }
}

void Libro::mostrar_todos_libros() {
    // 1. Get the directory path
    string directorio_libros = "../base_de_datos_/repositorio_libros/";

    // 2. Open the directory stream
    ifstream directorio(directorio_libros);

    // 3. Check if the directory was opened successfully
    if (directorio.is_open()) {
        // 4. Read each file name from the directory stream
        string nombre_archivo;
        while (directorio >> nombre_archivo) {
            cout << nombre_archivo << endl;
        }

        // 5. Close the directory stream
        directorio.close();
        } else {
        cout << "Error al abrir el directorio " << directorio_libros << endl;
    }
}

void Libro::mostrar_libros_disponibles() {
    // 1. Get the directory path
    string directorio_libros = "../base_de_datos_/repositorio_libros/";

    // 2. Open the directory stream
    ifstream directorio(directorio_libros);

    // 3. Check if the directory was opened successfully
    if (directorio.is_open()) {
        // 4. Read each file name from the directory stream
        string nombre_archivo;
        while (directorio >> nombre_archivo) {
            Libro archivo(nombre_archivo);
            if (archivo.get_estado() == 0)
            cout << nombre_archivo << endl;
        }

        // 5. Close the directory stream
        directorio.close();
        } else {
        cout << "Error al abrir el directorio " << directorio_libros << endl;
    }
}