#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo {
  int numero;
  struct nodo *siguiente;
  struct nodo *anterior;
};

typedef struct nodo *PunteroLista;

void insertarInicio(PunteroLista &lista, int valor) {
  PunteroLista q;
  q = new (struct nodo);
  q->numero = valor;
  q->siguiente = lista;
  q->anterior = NULL;

  if (lista != NULL) {
    lista->anterior = q;
  }

  lista = q;
}

void mostrarNodo(PunteroLista nodo) {
  cout << ' ' << nodo->anterior << " <- " << nodo << " -> " << nodo->siguiente << endl;
}

void switchNodo(PunteroLista &nodo1, PunteroLista &nodo2, PunteroLista &root) {

  if (nodo1 == root) {
    root = nodo2;
  } else if (nodo2 == root) {
    root = nodo1;
  }

  if ((nodo2->anterior == nodo1) || (nodo1->siguiente == nodo2)) {
    PunteroLista nodo1anterior = nodo1->anterior;
    PunteroLista nodo2siguiente = nodo2->siguiente;

    PunteroLista tmp = nodo2;
    nodo2 = nodo1;
    nodo1 = tmp;

    nodo2->anterior = nodo1;
    nodo2->siguiente = nodo2siguiente;
    nodo1->anterior = nodo1anterior;
    nodo1->siguiente = nodo2;
  } else {

    // apuntadores
    if (nodo1->anterior != NULL) {
      nodo1->anterior->siguiente = nodo2;
    }
    if (nodo1->siguiente != NULL) {
      nodo1->siguiente->anterior = nodo2;
    }
    if (nodo2->anterior != NULL) {
      nodo2->anterior->siguiente = nodo1;
    }
    if (nodo2->siguiente != NULL) {
      nodo2->siguiente->anterior = nodo1;
    }

    PunteroLista tmp2siguiente = nodo2->siguiente;
    PunteroLista tmp2anterior = nodo2->anterior;

    nodo2->siguiente = nodo1->siguiente;
    nodo2->anterior = nodo1->anterior;

    nodo1->siguiente = tmp2siguiente;
    nodo1->anterior = tmp2anterior;

    // fin
    PunteroLista tmp = nodo2;
    nodo2 = nodo1;
    nodo1 = tmp;
  }
}
void mostrarLista(PunteroLista lista) {
  int i = 0;

  while (lista != NULL) {

    cout << i + 1 << ") " << ' ' << lista->anterior << " <- " << lista << " -> "
         << lista->siguiente << endl;
    lista = lista->siguiente;
    i++;
  }
  cout << endl << endl;
}

int main() {
  PunteroLista lista = NULL;
  int opcion; // opcion del menu

  system("color 0b");

  do {

    cout << "\n\t\PunteroLista ENLAZADA DOBLE SIMPLE\n\n";
    cout << " 1. INSERTAR                         " << endl;
    cout << " 2. MOSTRAR                          " << endl;
    cout << " 3. SWITCH PRIMEROS DOS              " << endl;
    cout << " 4. SALIR                            " << endl;

    cout << "\n INGRESE OPCION: ";
    cin >> opcion;

    switch (opcion) {
    case 1:

      cout << "\n NUMERO A INSERTAR: ";
      int dato;
      cin >> dato;
      insertarInicio(lista, dato);
      break;

    case 2:

      mostrarLista(lista);
      break;
    case 3:

      // mostrarLista(lista);

      PunteroLista nodo1 = lista;
      PunteroLista nodo2 = lista->siguiente->siguiente;

      mostrarLista(lista);
      switchNodo(nodo1, nodo2, lista);
      mostrarLista(lista);

      break;
    }

    cout << endl << endl;

  } while (opcion != 4);

  system("pause");
  return 0;
}