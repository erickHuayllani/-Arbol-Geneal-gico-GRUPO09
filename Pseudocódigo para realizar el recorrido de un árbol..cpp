// Recorrido Preorden (Raíz, Izquierdo, Derecho)
Función preorden(Nodo* raiz)
    Si raiz != NULL Entonces
        Imprimir raiz->dato
        preorden(raiz->izquierdo)
        preorden(raiz->derecho)
    Fin Si
Fin Función

// Recorrido Inorden (Izquierdo, Raíz, Derecho)
Función inorden(Nodo* raiz)
    Si raiz != NULL Entonces
        inorden(raiz->izquierdo)
        Imprimir raiz->dato
        inorden(raiz->derecho)
    Fin Si
Fin Función

// Recorrido Postorden (Izquierdo, Derecho, Raíz)
Función postorden(Nodo* raiz)
    Si raiz != NULL Entonces
        postorden(raiz->izquierdo)
        postorden(raiz->derecho)
        Imprimir raiz->dato
    Fin Si
Fin Función
