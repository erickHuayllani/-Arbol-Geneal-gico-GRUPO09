Estructura Nodo
  id: entero
  nombre: cadena
  padre: Nodo*
  izq: Nodo*
  der: Nodo*

Variable global raiz ? NULL

----------------------------------------
Función insertar(nodo, id, nombre, padre)
  Si nodo = NULL Entonces
    crear nuevo Nodo con campos (id, nombre)
    nuevo.padre ? padre
    Retornar nuevo
  Fin Si

  Si id < nodo.id Entonces
    nodo.izq ? insertar(nodo.izq, id, nombre, nodo)
  Sino Si id > nodo.id Entonces
    nodo.der ? insertar(nodo.der, id, nombre, nodo)
  Sino
    Imprimir "ID ya existe. No se inserta."
  Fin Si

  Retornar nodo
Fin Función

----------------------------------------
Función buscar(nodo, id)
  Si nodo = NULL Entonces
    Retornar NULL
  Fin Si

  Si id = nodo.id Entonces
    Retornar nodo
  Sino Si id < nodo.id Entonces
    Retornar buscar(nodo.izq, id)
  Sino
    Retornar buscar(nodo.der, id)
  Fin Si
Fin Función

----------------------------------------
Procedimiento borrarSubarbol(nodo)
  Si nodo = NULL Entonces
    Retornar
  Fin Si

  borrarSubarbol(nodo.izq)
  borrarSubarbol(nodo.der)
  Eliminar nodo  // liberar memoria
Fin Procedimiento

----------------------------------------
Procedimiento eliminar(nodoRef, id)
  objetivo ? buscar(nodoRef, id)
  Si objetivo = NULL Entonces
    Imprimir "No existe ID =", id
    Retornar
  Fin Si

  padre ? objetivo.padre
  Si padre ? NULL Entonces
    Si padre.izq = objetivo Entonces padre.izq ? NULL
    Sino padre.der ? NULL
  Sino
    // objetivo era la raíz
    raiz ? NULL
  Fin Si

  Si objetivo = nodoRef Entonces
    nodoRef ? NULL
  Fin Si

  borrarSubarbol(objetivo)
  Imprimir "Subárbol con ID =", id, "eliminado."
Fin Procedimiento

----------------------------------------
Procedimiento preorden(nodo)
  Si nodo = NULL Entonces Retornar
  Imprimir nodo.id, "[", nodo.nombre, "]"
  preorden(nodo.izq)
  preorden(nodo.der)
Fin Procedimiento

----------------------------------------
Procedimiento inorden(nodo)
  Si nodo = NULL Entonces Retornar
  inorden(nodo.izq)
  Imprimir nodo.id, "[", nodo.nombre, "]"
  inorden(nodo.der)
Fin Procedimiento

----------------------------------------
Procedimiento postorden(nodo)
  Si nodo = NULL Entonces Retornar
  postorden(nodo.izq)
  postorden(nodo.der)
  Imprimir nodo.id, "[", nodo.nombre, "]"
Fin Procedimiento

----------------------------------------
Procedimiento mostrarAncestros(nodo)
  Si nodo = NULL O nodo.padre = NULL Entonces Retornar
  Imprimir nodo.padre.id, "[", nodo.padre.nombre, "]"
  mostrarAncestros(nodo.padre)
Fin Procedimiento

----------------------------------------
Procedimiento mostrarDescendientes(nodo)
  Si nodo = NULL Entonces Retornar
  Si nodo.izq ? NULL Entonces
    Imprimir nodo.izq.id, "[", nodo.izq.nombre, "]"
  Fin Si
  Si nodo.der ? NULL Entonces
    Imprimir nodo.der.id, "[", nodo.der.nombre, "]"
  Fin Si
  mostrarDescendientes(nodo.izq)
  mostrarDescendientes(nodo.der)
Fin Procedimiento

----------------------------------------
Proceso principal MAIN
  raiz ? NULL
  Repetir
    Imprimir menú de opciones:
      1. Insertar miembro
      2. Eliminar miembro + descendientes
      3. Buscar miembro
      4. Mostrar ancestros
      5. Mostrar descendientes
      6. Recorrido Preorden
      7. Recorrido Inorden
      8. Recorrido Postorden
      9. Salir
    Leer opción

    Segun opción Hacer
      Caso 1:
        Leer id, nombre
        raiz ? insertar(raiz, id, nombre, NULL)
      Caso 2:
        Leer id
        eliminar(raiz, id)
      Caso 3:
        Leer id
        nodo ? buscar(raiz, id)
        Si nodo ? NULL Entonces
          Imprimir "Encontrado:", nodo.id, "[", nodo.nombre, "]"
        Sino
          Imprimir "No encontrado"
        Fin Si
      Caso 4:
        Leer id
        nodo ? buscar(raiz, id)
        Si nodo ? NULL Entonces mostrarAncestros(nodo)
        Sino Imprimir "No encontrado"
      Caso 5:
        Leer id
        nodo ? buscar(raiz, id)
        Si nodo ? NULL Entonces mostrarDescendientes(nodo)
        Sino Imprimir "No encontrado"
      Caso 6: preorden(raiz)
      Caso 7: inorden(raiz)
      Caso 8: postorden(raiz)
    Fin Segun

  Hasta que opción = 9

  // Liberar toda la memoria
  borrarSubarbol(raiz)
Fin MAIN
