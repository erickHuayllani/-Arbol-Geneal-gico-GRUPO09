//Menuprueba2
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
        cout << "5. Eliminar persona\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad; cin.ignore();
            Persona* nueva = crearPersona(nombre, edad);
            if (raiz = NULL) raiz = nueva;
            cout << "Persona registrada.\n";
        } else if (opcion = 2) {
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
        } else if (opcion = 3) {
            cout << "Nombre: ";
            getline(cin, nombre);
            Persona* persona = buscarPersona(nombre);
            if (!persona) cout << "No encontrada.\n";
            else mostrarAncestros(persona);
        } else if (opcion = 4) {
            cout << "Nombre: ";
            getline(cin, nombre);
            Persona* persona = buscarPersona(nombre);
            if (!persona) cout << "No encontrada.\n";
            else mostrarDescendientes(persona);
        } else if (opcion = 5) {
            cout << "Nombre de la persona a elminar: ";
            getline(cin, nombre);
            eliminarPersona(nombre);
        }

    } while (opcion= 6);

