Estructura Nodo
    Entero dato
    Nodo* izquierdo
    Nodo* derecho
Fin Estructura

Funci�n crearNodo(Entero valor) -> Nodo*
    Nodo* nuevo = nuevo Nodo
    nuevo->dato = valor
    nuevo->izquierdo = NULL
    nuevo->derecho = NULL
    Retornar nuevo
Fin Funci�n

Funci�n insertar(Nodo* raiz, Entero valor) -> Nodo*
    Si raiz == NULL Entonces
        Retornar crearNodo(valor)
    Fin Si
    
    Si valor < raiz->dato Entonces
        raiz->izquierdo = insertar(raiz->izquierdo, valor)
    Sino Si valor > raiz->dato
        raiz->derecho = insertar(raiz->derecho, valor)
    Fin Si
    
    Retornar raiz
Fin Funci�n
