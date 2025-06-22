void mostrarInorden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarInorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        mostrarInorden(raiz->derecho);
    }
}

void mostrarPreorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        mostrarPreorden(raiz->izquierdo);
        mostrarPreorden(raiz->derecho);
    }
}

void mostrarPostorden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarPostorden(raiz->izquierdo);
        mostrarPostorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        delete raiz;
    }
