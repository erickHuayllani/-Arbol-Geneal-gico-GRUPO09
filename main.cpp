int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insertar valor\n";
        cout << "2. Mostrar recorrido inorden\n";
        cout << "3. Mostrar recorrido preorden\n";
        cout << "4. Mostrar recorrido postorden\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa un valor para insertar: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;
            case 2:
                cout << "Recorrido Inorden: ";
                mostrarInorden(raiz);
                cout << "\n";
                break;
            case 3:
                cout << "Recorrido Preorden: ";
                mostrarPreorden(raiz);
                std::cout << "\n";
                break;
            case 4:
                cout << "Recorrido Postorden: ";
                mostrarPostorden(raiz);
                cout << "\n";
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);
    return 0;
}
