#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    double precio;
    int cantidad;
};

void agregarProducto(vector<Producto> &inventario) {
    Producto nuevo;
    cout << "Ingrese el código del producto: ";
    getline(cin, nuevo.codigo);
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nuevo.nombre);
    cout << "Ingrese el precio del producto: ";
    cin >> nuevo.precio;
    cout << "Ingrese la cantidad en inventario: ";
    cin >> nuevo.cantidad;
    cin.ignore();
    inventario.push_back(nuevo);
    cout << "Producto agregado correctamente.\n";
}

void mostrarProductos(const vector<Producto> &inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario.\n";
    } else {
        cout << "Inventario de productos:\n";
        for (const auto &producto : inventario) {
            cout << "Código: " << producto.codigo << ", Nombre: " << producto.nombre
                 << ", Precio: " << producto.precio << ", Cantidad: " << producto.cantidad << "\n";
        }
    }
}

void buscarProducto(const vector<Producto> &inventario, const string &codigo) {
    auto it = find_if(inventario.begin(), inventario.end(), [&](const Producto &p) {
        return p.codigo == codigo;
    });
    if (it != inventario.end()) {
        cout << "Código: " << it->codigo << ", Nombre: " << it->nombre
             << ", Precio: " << it->precio << ", Cantidad: " << it->cantidad << "\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void actualizarProducto(vector<Producto> &inventario, const string &codigo) {
    auto it = find_if(inventario.begin(), inventario.end(), [&](const Producto &p) {
        return p.codigo == codigo;
    });
    if (it != inventario.end()) {
        cout << "Ingrese el nuevo nombre del producto: ";
        getline(cin, it->nombre);
        cout << "Ingrese el nuevo precio del producto: ";
        cin >> it->precio;
        cout << "Ingrese la nueva cantidad en inventario: ";
        cin >> it->cantidad;
        cin.ignore();
        cout << "Producto actualizado correctamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void eliminarProducto(vector<Producto> &inventario, const string &codigo) {
    auto it = remove_if(inventario.begin(), inventario.end(), [&](const Producto &p) {
        return p.codigo == codigo;
    });
    if (it != inventario.end()) {
        inventario.erase(it, inventario.end());
        cout << "Producto eliminado correctamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

int main() {
    vector<Producto> inventario;
    int opcion;
    string codigo;

    do {
        cout << "\n*** Gestión de Inventario ***\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Actualizar producto por código\n";
        cout << "5. Eliminar producto por código\n";
        cout << "6. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarProducto(inventario);
                break;
            case 2:
                mostrarProductos(inventario);
                break;
            case 3:
                cout << "Ingrese el código del producto a buscar: ";
                getline(cin, codigo);
                buscarProducto(inventario, codigo);
                break;
            case 4:
                cout << "Ingrese el código del producto a actualizar: ";
                getline(cin, codigo);
                actualizarProducto(inventario, codigo);
                break;
            case 5:
                cout << "Ingrese el código del producto a eliminar: ";
                getline(cin, codigo);
                eliminarProducto(inventario, codigo);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
