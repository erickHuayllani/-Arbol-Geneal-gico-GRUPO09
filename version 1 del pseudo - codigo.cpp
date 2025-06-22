#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    Persona* padre;
    Persona* izquierda; // hijo izquierdo
    Persona* derecha;   // hijo derecho
};

// Registro para búsqueda por nombre
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

// Insertar hijo en el árbol (izquierda o derecha si está libre)
void agregarHijo(Persona* padre, Persona* hijo) {
    if (padre->izquierda == NULL) {
        padre->izquierda = hijo;
    } else if (padre->derecha == NULL) {
        padre->derecha = hijo;
    } else {
        cout << "El padre ya tiene dos hijos.\n";
        return;
    }
    hijo->padre = padre;
}

// Recorridos
void preorden(Persona* raiz) {
    if (raiz != NULL) {
        cout << raiz->nombre << " (" << raiz->edad << ")\n";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

void inorden(Persona* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << raiz->nombre << " (" << raiz->edad << ")\n";
        inorden(raiz->derecha);
    }
}

void posorden(Persona* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        cout << raiz->nombre << " (" << raiz->edad << ")\n";
    }
}

// Mostrar ancestros
void mostrarAncestros(Persona* persona) {
    if (persona->padre != NULL) {
        cout << persona->padre->nombre << " (" << persona->padre->edad << ")\n";
        mostrarAncestros(persona->padre);
    }
}

// Mostrar descendientes
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

// Eliminar subárbol de una persona
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

    // Desconectar del padre
    if (persona->padre != NULL) {
        if (persona->padre->izquierda == persona)
            persona->padre->izquierda = NULL;
        else if (persona->padre->derecha == persona)
            persona->padre->derecha = NULL;
    }

    eliminarSubarbol(persona);
    cout << "Persona eliminada junto con sus descendientes.\n";
}

// =================== MENÚ =====================
int main() {
    int opcion;
    string nombre, nombrePadre;
    int edad;
    Persona* raiz = NULL;

    do {
        cout << "\n--- Menu de Arbol Genealogico ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Establecer relacion padre-hijo\n";
        cout << "3. Mostrar ancestros\n";
        cout << "4. Mostrar descendientes\n";
        cout << "5. Recorrido preorden\n";
        cout << "6. Recorrido inorden\n";
        cout << "7. Recorrido posorden\n";
        cout << "8. Eliminar persona\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad; cin.ignore();
            Persona* nueva = crearPersona(nombre, edad);
            if (raiz == NULL) raiz = nueva;
            cout << "Persona registrada.\n";
        } else if (opcion == 2) {
            cout << "Nombre del padre: ";
            getline(cin, nombrePadre);
            Persona* padre = buscarPersona(nombrePadre);
            if (!padre) {
                cout << "Padre no encontrado.\n";
                continue;
            }
            cout << "Nombre del hijo: ";
            getline(cin, nombre);
            Persona* hijo = buscarPersona(nombre);
            if (!hijo) {
                cout << "Hijo no encontrado.\n";
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
            cout << "Recorrido Preorden:\n";
            preorden(raiz);
        } else if (opcion == 6) {
            cout << "Recorrido Inorden:\n";
            inorden(raiz);
        } else if (opcion == 7) {
            cout << "Recorrido Posorden:\n";
            posorden(raiz);
        } else if (opcion == 8) {
            cout << "Nombre de la persona a eliminar: ";
            getline(cin, nombre);
            eliminarPersona(nombre);
        }

    } while (opcion != 9);

    cout << "Finalizando...\n";
    return 0;
}
