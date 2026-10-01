#include <iostream>
#include <cstring>

using namespace std;

// Constante para el límite máximo de registros
const int MAX_CLIENTES = 100;

// Estructura (registro) para almacenar la información de cada venta
struct Venta {
    int id;
    char cliente[50];
    char producto[50];
    char categoria[50];
    int cantidadProductos;
};

// Función para actualizar la cantidad de productos vendidos usando PASO POR REFERENCIA
void actualizarCantidad(int &cantidadActual, int nuevaCantidad) {
    cantidadActual = nuevaCantidad; // Modifica directamente el valor en el registro
}

// Procedimiento para agregar un nuevo registro a la lista
void agregarNuevoRegistro(Venta lista[], int &n) {
    if (n >= MAX_CLIENTES) {
        cout << "\nError: Se ha alcanzado el limite maximo de registros permitidos (" << MAX_CLIENTES << ")." << endl;
        return;
    }

    cout << "\n==========================================================" << endl;
    cout << "--- AGREGAR NUEVO REGISTRO DE VENTA ---" << endl;
    cout << "==========================================================" << endl;

    lista[n].id = n + 1;

    cout << "Nombre del cliente (sin espacios o use '_'): ";
    cin >> lista[n].cliente;

    cout << "Nombre del producto (sin espacios o use '_'): ";
    cin >> lista[n].producto;

    cout << "Categoria del producto (sin espacios o use '_'): ";
    cin >> lista[n].categoria;

    // Validación para evitar valores negativos de productos
    do {
        cout << "Cantidad de productos vendidos: ";
        cin >> lista[n].cantidadProductos;

        if (lista[n].cantidadProductos < 0) {
            cout << "Error: La cantidad de productos no puede ser negativa. Intente de nuevo." << endl;
        }
    } while (lista[n].cantidadProductos < 0);

    n++; // Incrementar el total de clientes registrados
    cout << "\n¡Registro agregado con exito! Total de clientes actuales: " << n << endl;
}

// Procedimiento principal para ejecutar las operaciones del menú
void ejecutarOpcion(int opcion, Venta lista[], int &n) {
    if (opcion == 1) {
        // AGREGAR NUEVO REGISTRO DESDE EL MENU
        agregarNuevoRegistro(lista, n);

    } else if (opcion == 2) {
        // BUSCAR CLIENTES QUE COMPRARON ENTRE 3 Y 10 PRODUCTOS
        int contador = 0;
        cout << "\n==========================================================" << endl;
        cout << "--- BUSQUEDA DE CLIENTES CON COMPRAS EN RANGO [3 - 10] ---" << endl;
        cout << "==========================================================" << endl;

        for (int i = 0; i < n; i++) {
            if (lista[i].cantidadProductos >= 3 && lista[i].cantidadProductos <= 10) {
                cout << "Cliente [" << lista[i].id << "] (" << lista[i].cliente 
                     << ") - Producto: " << lista[i].producto 
                     << " | Cantidad: " << lista[i].cantidadProductos << endl;
                contador++;
            }
        }
        cout << "----------------------------------------------------------" << endl;
        cout << "TOTAL DE CLIENTES ENCONTRADOS EN EL RANGO: " << contador << endl;

    } else if (opcion == 3) {
        // BUSCAR PRODUCTO USANDO strstr()
        char termino[50];
        cout << "\n==========================================================" << endl;
        cout << "--- BUSQUEDA DE PRODUCTO POR PALABRA/CADENA (strstr) ---" << endl;
        cout << "==========================================================" << endl;
        cout << "Ingrese la palabra o texto a buscar en el producto: ";
        cin >> termino;

        int coincidencias = 0;
        for (int i = 0; i < n; i++) {
            if (strstr(lista[i].producto, termino) != NULL) {
                cout << "Coincidencia -> Cliente [" << lista[i].id << "] " 
                     << lista[i].cliente << " | Producto: " << lista[i].producto 
                     << " | Categoria: " << lista[i].categoria 
                     << " | Cantidad: " << lista[i].cantidadProductos << endl;
                coincidencias++;
            }
        }

        if (coincidencias == 0) {
            cout << "No se encontraron productos que contengan la palabra: \"" << termino << "\"" << endl;
        }

    } else if (opcion == 4) {
        // DEMOSTRACIÓN DE FUNCIONES DE CADENAS (strlen, strcpy, strcat)
        int idSeleccionado = 0;
        cout << "\n==========================================================" << endl;
        cout << "--- OPERACIONES CON CADENAS (strlen, strcpy, strcat) ---" << endl;
        cout << "==========================================================" << endl;
        cout << "Ingrese el numero de orden del cliente (1 a " << n << "): ";
        cin >> idSeleccionado;

        if (idSeleccionado >= 1 && idSeleccionado <= n) {
            int pos = idSeleccionado - 1;

            // 1. Uso de strlen()
            int longitud = strlen(lista[pos].producto);
            cout << "\n[strlen] Longitud del nombre del producto: " << longitud << " caracteres." << endl;

            // 2. Uso de strcpy()
            char copiaProducto[50];
            strcpy(copiaProducto, lista[pos].producto);
            cout << "[strcpy] Copia de la cadena realizada: \"" << copiaProducto << "\"" << endl;

            // 3. Uso de strcat()
            char informacionCompleta[100];
            strcpy(informacionCompleta, lista[pos].categoria);
            strcat(informacionCompleta, " - Categoria Confirmada");
            cout << "[strcat] Cadena concatenada: \"" << informacionCompleta << "\"" << endl;
        } else {
            cout << "Error: Numero de orden fuera de rango." << endl;
        }

    } else if (opcion == 5) {
        // ACTUALIZAR CANTIDAD MEDIANTE PASO POR REFERENCIA
        int idBuscado = 0;
        cout << "\n==========================================================" << endl;
        cout << "--- ACTUALIZAR CANTIDAD DE PRODUCTOS (REFERENCIA) ---" << endl;
        cout << "==========================================================" << endl;

        do {
            cout << "Ingrese el numero de orden del cliente a actualizar (1 a " << n << "): ";
            cin >> idBuscado;

            if (idBuscado < 1 || idBuscado > n) {
                cout << "Error: El cliente ingresado no existe." << endl;
            }
        } while (idBuscado < 1 || idBuscado > n);

        int pos = idBuscado - 1;
        int cantidadActual = lista[pos].cantidadProductos;
        int nuevaCantidad = 0;

        cout << "Cantidad actual del Cliente [" << idBuscado << "]: " 
             << cantidadActual << " productos." << endl;

        // Validación: No debe ser negativa Y tampoco debe ser igual a la cantidad actual
        do {
            cout << "Ingrese la nueva cantidad de productos: ";
            cin >> nuevaCantidad;

            if (nuevaCantidad < 0) {
                cout << "Error: La cantidad no puede ser negativa. Intente de nuevo." << endl;
            } else if (nuevaCantidad == cantidadActual) {
                cout << "Error: La nueva cantidad no puede ser igual a la cantidad actual. Intente de nuevo." << endl;
            }
        } while (nuevaCantidad < 0 || nuevaCantidad == cantidadActual);

        // Modificación directa mediante paso por referencia
        actualizarCantidad(lista[pos].cantidadProductos, nuevaCantidad);
        cout << "\n¡Cantidad actualizada correctamente mediante paso por referencia!" << endl;

    } else if (opcion == 6) {
        // VISUALIZAR DATOS MEDIANTE UN PUNTERO A REGISTRO
        int idVer = 0;
        cout << "\n==========================================================" << endl;
        cout << "--- CONSULTA DE REGISTRO MEDIANTE PUNTERO ---" << endl;
        cout << "==========================================================" << endl;
        cout << "Ingrese el numero de orden del cliente a consultar (1 a " << n << "): ";
        cin >> idVer;

        if (idVer >= 1 && idVer <= n) {
            // Puntero apuntando a la dirección de la estructura seleccionada
            Venta *ptrVenta = &lista[idVer - 1];

            cout << "\n--- DATOS OBTENIDOS DESDE EL PUNTERO ---" << endl;
            cout << "ID Orden:     " << ptrVenta->id << endl;
            cout << "Cliente:      " << ptrVenta->cliente << endl;
            cout << "Producto:     " << ptrVenta->producto << endl;
            cout << "Categoria:    " << ptrVenta->categoria << endl;
            cout << "Cantidad:     " << ptrVenta->cantidadProductos << " productos." << endl;
        } else {
            cout << "Error: Posicion o numero de cliente invalido." << endl;
        }

    } else if (opcion == 7) {
        // ORDENAR REGISTROS DE MENOR A MAYOR POR CANTIDAD
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (lista[j].cantidadProductos > lista[j + 1].cantidadProductos) {
                    Venta aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
        }
        cout << "\n¡Registros ordenados de menor a mayor exitosamente!" << endl;

    } else if (opcion == 8) {
        // VISUALIZAR LISTA COMPLETA DE REGISTROS
        cout << "\n==========================================================" << endl;
        cout << "--- LISTA COMPLETA DE VENTAS REGISTRADAS ---" << endl;
        cout << "==========================================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << "[" << i + 1 << "] Orden: " << lista[i].id 
                 << " | Cliente: " << lista[i].cliente 
                 << " | Producto: " << lista[i].producto 
                 << " | Categoria: " << lista[i].categoria 
                 << " | Cantidad: " << lista[i].cantidadProductos << endl;
        }
    }
}

int main() {
    int n = 0;

    cout << "==========================================================" << endl;
    cout << "   TIENDA MASCOTITAS - SISTEMA DE REGISTRO DE VENTAS    " << endl;
    cout << "==========================================================" << endl;

    // Validación inicial de la cantidad de clientes (1 a 100)
    do {
        cout << "Ingrese la cantidad inicial de clientes atendidos (1 - " << MAX_CLIENTES << "): ";
        cin >> n;

        if (n <= 0 || n > MAX_CLIENTES) {
            cout << "Error: La cantidad de clientes debe estar entre 1 y " << MAX_CLIENTES << "." << endl;
        }
    } while (n <= 0 || n > MAX_CLIENTES);

    // Arreglo unidimensional estático de estructuras (registros)
    Venta listaVentas[MAX_CLIENTES];

    // Registro inicial de los datos
    for (int i = 0; i < n; i++) {
        listaVentas[i].id = i + 1;

        cout << "\n--- INGRESO DE DATOS DEL CLIENTE [" << i + 1 << "] ---" << endl;
        cout << "Nombre del cliente (sin espacios o use '_'): ";
        cin >> listaVentas[i].cliente;

        cout << "Nombre del producto (sin espacios o use '_'): ";
        cin >> listaVentas[i].producto;

        cout << "Categoria del producto (sin espacios o use '_'): ";
        cin >> listaVentas[i].categoria;

        do {
            cout << "Cantidad de productos vendidos: ";
            cin >> listaVentas[i].cantidadProductos;

            if (listaVentas[i].cantidadProductos < 0) {
                cout << "Error: La cantidad de productos no puede ser negativa." << endl;
            }
        } while (listaVentas[i].cantidadProductos < 0);
    }

    int opcion = 0;

    // Menú interactivo principal
    do {
        cout << "\n==========================================================" << endl;
        cout << "                    MENU DE OPCIONES                      " << endl;
        cout << "==========================================================" << endl;
        cout << "1. Agregar nuevo cliente / registro" << endl;
        cout << "2. Buscar clientes con compras entre 3 y 10 productos" << endl;
        cout << "3. Buscar producto por palabra/cadena (strstr)" << endl;
        cout << "4. Operaciones con cadenas (strlen, strcpy, strcat)" << endl;
        cout << "5. Actualizar cantidad de productos (Paso por Referencia)" << endl;
        cout << "6. Mostrar registro de cliente mediante PUNTERO" << endl;
        cout << "7. Ordenar registros de menor a mayor por cantidad" << endl;
        cout << "8. Visualizar registros de ventas" << endl;
        cout << "9. Salir del programa" << endl;

        do {
            cout << "Seleccione una opcion (1-9): ";
            cin >> opcion;

            if (opcion < 1 || opcion > 9) {
                cout << "Error: Opcion invalida. Intente de nuevo." << endl;
            }
        } while (opcion < 1 || opcion > 9);

        if (opcion != 9) {
            ejecutarOpcion(opcion, listaVentas, n);
        } else {
            cout << "\n¡Gracias por utilizar el sistema de la Tienda MASCOTITAS!" << endl;
        }

    } while (opcion != 9);

    return 0;
}
