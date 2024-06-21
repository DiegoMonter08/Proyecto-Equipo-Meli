#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    int edad;
    float promedio;
};

vector<Estudiante> estudiantes;

void crearEstudiante(int id, const string& nombre, int edad, float promedio) {
    Estudiante nuevo_estudiante = { id, nombre, edad, promedio };
    estudiantes.push_back(nuevo_estudiante);
    cout << "Estudiante creado exitosamente." << endl;
}

void listarEstudiantes() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes para mostrar." << endl;
        return;
    }
    cout << "Lista de Estudiantes:" << endl;
    for (const auto& estudiante : estudiantes) {
        cout << "ID: " << estudiante.id
             << ", Nombre: " << estudiante.nombre
             << ", Edad: " << estudiante.edad
             << ", Promedio: " << estudiante.promedio << endl;
    }
}

void actualizarEstudiante(int id, const string& nuevo_nombre, int nueva_edad, float nuevo_promedio) {
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == id) {
            estudiante.nombre = nuevo_nombre;
            estudiante.edad = nueva_edad;
            estudiante.promedio = nuevo_promedio;
            cout << "Estudiante actualizado exitosamente." << endl;
            return;
        }
    }
    cout << "Error: Estudiante con ID " << id << " no encontrado." << endl;
}

void eliminarEstudiante(int id) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->id == id) {
            estudiantes.erase(it);
            cout << "Estudiante eliminado exitosamente." << endl;
            return;
        }
    }
    cout << "Error: Estudiante con ID " << id << " no encontrado." << endl;
}

int main() {
    int opcion;
    int id;
    string nombre;
    int edad;
    float promedio;

    do {
        cout << "\n--- CRUD de Estudiantes ---\n";
        cout << "1. Crear Estudiante\n";
        cout << "2. Listar Estudiantes\n";
        cout << "3. Actualizar Estudiante\n";
        cout << "4. Eliminar Estudiante\n";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID: ";
                cin >> id;
                cout << "Ingrese Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese Edad: ";
                cin >> edad;
                cout << "Ingrese Promedio: ";
                cin >> promedio;
                crearEstudiante(id, nombre, edad, promedio);
                break;
            case 2:
                listarEstudiantes();
                break;
            case 3:
                cout << "Ingrese ID del Estudiante a actualizar: ";
                cin >> id;
                cout << "Ingrese Nuevo Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese Nueva Edad: ";
                cin >> edad;
                cout << "Ingrese Nuevo Promedio: ";
                cin >> promedio;
                actualizarEstudiante(id, nombre, edad, promedio);
                break;
            case 4:
                cout << "Ingrese ID del Estudiante a eliminar: ";
                cin >> id;
                eliminarEstudiante(id);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}

