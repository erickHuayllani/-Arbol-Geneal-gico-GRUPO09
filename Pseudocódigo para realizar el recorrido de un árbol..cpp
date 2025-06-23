// Recorrido Preorden (Ra�z, Izquierdo, Derecho)
Funci�n preorden(Nodo* raiz)
    Si raiz != NULL Entonces
        Imprimir raiz->dato
        preorden(raiz->izquierdo)
        preorden(raiz->derecho)
    Fin Si
Fin Funci�n

// Recorrido Inorden (Izquierdo, Ra�z, Derecho)
Funci�n inorden(Nodo* raiz)
    Si raiz != NULL Entonces
        inorden(raiz->izquierdo)
        Imprimir raiz->dato
        inorden(raiz->derecho)
    Fin Si
Fin Funci�n

// Recorrido Postorden (Izquierdo, Derecho, Ra�z)
Funci�n postorden(Nodo* raiz)
    Si raiz != NULL Entonces
        postorden(raiz->izquierdo)
        postorden(raiz->derecho)
        Imprimir raiz->dato
    Fin Si
Fin Funci�n
