#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    Persona* padre;
    Persona* izquierda;
    Persona* derecha;
};

vector<Persona*> personas;

Persona* crearPersona(string nombre, int edad) {
    Persona* nueva = new Persona;
    nueva->nombre = nombre;
    nueva->edad = edad;
    nueva->padre = NULL;
    nueva->izquierda = NULL;
    nueva->derecha = NULL;
    personas.push_back(nueva);
    return nueva;
}

Persona* buscarPersona(string nombre) {
    for (int i = 0; i < personas.size(); i++) {
        if (personas[i]->nombre == nombre)
            return personas[i];
    }
    return NULL;
}

void agregarHijo(Persona* padre, Persona* hijo) {
    if (padre->izquierda == NULL) {
        padre->izquierda = hijo;
    } else if (padre->derecha == NULL) {
        padre->derecha = hijo;
    } else {
        cout << "El padre ya tiene dos hij@s.\n";
        return;
    }
    hijo->padre = padre;
}

void mostrarAncestros(Persona* persona) {
    if (persona->padre != NULL) {
        cout << persona->padre->nombre << " (" << persona->padre->edad << ")\n";
        mostrarAncestros(persona->padre);
    }
}

void mostrarDescendientes(Persona* persona) {
    if (persona != NULL) {
        if (persona->izquierda)
            cout << persona->izquierda->nombre << " (" << persona->izquierda->edad << ")\n";
        if (persona->derecha)
            cout << persona->derecha->nombre << " (" << persona->derecha->edad << ")\n";
        mostrarDescendientes(persona->izquierda);
        mostrarDescendientes(persona->derecha);
    }
}

void eliminarSubarbol(Persona* persona) {
    if (persona == NULL) return;

    eliminarSubarbol(persona->izquierda);
    eliminarSubarbol(persona->derecha);

    for (int i = 0; i < personas.size(); i++) {
        if (personas[i] == persona) {
            personas.erase(personas.begin() + i);
            break;
        }
    }
    delete persona;
}

void eliminarPersona(string nombre) {
    Persona* persona = buscarPersona(nombre);
    if (persona == NULL) {
        cout << "Persona no encontrada.\n";
        return;
    }

    if (persona->padre != NULL) {
        if (persona->padre->izquierda == persona)
            persona->padre->izquierda = NULL;
        else if (persona->padre->derecha == persona)
            persona->padre->derecha = NULL;
    }

    eliminarSubarbol(persona);
    cout << "Persona eliminada junto con sus descendientes.\n";
}

int obtenerOpcionValida() {
    int opcion;
    while (true) {
        cout << "Opcion: ";
        if (cin >> opcion) {
            if (opcion >= 1 && opcion <= 6) {
                cin.ignore(); // Limpiar el buffer(memori alamacenada)
                return opcion;
            } else {
                cout << "Por favor elija una opcion valida del menu (1-6)...\n";
            }
        } else {
            cout << "Entrada invalida. Por favor ingrese un numero del menu...\n";
            cin.clear(); // Limpiar el estado de error
            while (cin.get() != '\n'); // Limpia el buffer(memori alamacenada)
        }
    }
}

int obtenerEdadValida() {
    int edad;
    while (true) {
        cout << "Edad: ";
        if (cin >> edad) {
            if (edad >= 0) {
                cin.ignore(); // Limpiar el buffer(memori alamacenada)
                return edad;
            } else {
                cout << "La edad no puede ser negativa. Por favor ingrese un valor valido.\n";
            }
        } else {
            cout << "Entrada invalida. Por favor ingrese un numero valido.\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}

int main() {
    int opcion;
    string nombre, nombrePadre;
    int edad;
    Persona* raiz = NULL;

    do {
        cout << "\n--- Menu de Arbol Genealogico ---\n";
        cout << "1. Agregar persona(s)\n";
        cout << "2. Establecer relacion padre-hij@\n";
        cout << "3. Mostrar ancestros\n";
        cout << "4. Mostrar descendientes\n";
        cout << "5. Eliminar persona\n";
        cout << "6. Salir\n";
        
        opcion = obtenerOpcionValida();

        if (opcion == 1) {
            do {
                cout << "\nIngrese el nombre (o 0 para terminar de ingresar datos): ";
                getline(cin, nombre);
                
                if (nombre == "0") break;
                
                edad = obtenerEdadValida();
                
                Persona* nueva = crearPersona(nombre, edad);
                if (raiz == NULL) raiz = nueva;
                cout << "Persona registrada.\n";
                
            } while (true);
            
        } else if (opcion == 2) {
            cout << "Nombre del padre: ";
            getline(cin, nombrePadre);
            Persona* padre = buscarPersona(nombrePadre);
            if (!padre) {
                cout << "Padre no encontrado.\n";
                continue;
            }
            cout << "Nombre del hij@: ";
            getline(cin, nombre);
            Persona* hijo = buscarPersona(nombre);
            if (!hijo) {
                cout << "Hij@ no encontrado.\n";
                continue;
            }
            agregarHijo(padre, hijo);
        } else if (opcion == 3) {
            cout << "Nombre: ";
            getline(cin, nombre);
            Persona* persona = buscarPersona(nombre);
            if (!persona) cout << "No encontrada.\n";
            else mostrarAncestros(persona);
        } else if (opcion == 4) {
            cout << "Nombre: ";
            getline(cin, nombre);
            Persona* persona = buscarPersona(nombre);
            if (!persona) cout << "No encontrada.\n";
            else mostrarDescendientes(persona);
        } else if (opcion == 5) {
            cout << "Nombre de la persona a eliminar: ";
            getline(cin, nombre);
            eliminarPersona(nombre);
        }

    } while (opcion != 6);

    cout << "Cerrando el sistema.Hasta la proxima[Presionar enter]...\n";
    return 0;
}
