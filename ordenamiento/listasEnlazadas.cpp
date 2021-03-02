#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo {
  int numero;
  struct nodo *sgte;
  struct nodo *ant;
};

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor) {
  Tlista q;
  q = new (struct nodo);
  q->numero = valor;
  q->sgte = lista;
  q->ant = NULL;

  if (lista != NULL) {
    lista->ant = q;
  }

  lista = q;
}

void mostrarNodo(Tlista nodo) {
  cout << ' ' << nodo->ant << " <- " << nodo << " -> " << nodo->sgte << endl;
}

void switchNodo(Tlista &nodo1, Tlista &nodo2, Tlista &root) {

  if (nodo1 == root) {
    root = nodo2;
  } else if (nodo2 == root) {
    root = nodo1;
  }

  if ((nodo2->ant == nodo1) || (nodo1->sgte == nodo2)) {
    Tlista nodo1ant = nodo1->ant;
    Tlista nodo2sgte = nodo2->sgte;

    Tlista tmp = nodo2;
    nodo2 = nodo1;
    nodo1 = tmp;

    nodo2->ant = nodo1;
    nodo2->sgte = nodo2sgte;
    nodo1->ant = nodo1ant;
    nodo1->sgte = nodo2;
  } else {

    // apuntadores
    if (nodo1->ant != NULL) {
      nodo1->ant->sgte = nodo2;
    }
    if (nodo1->sgte != NULL) {
      nodo1->sgte->ant = nodo2;
    }
    if (nodo2->ant != NULL) {
      nodo2->ant->sgte = nodo1;
    }
    if (nodo2->sgte != NULL) {
      nodo2->sgte->ant = nodo1;
    }

    Tlista tmp2Sgte = nodo2->sgte;
    Tlista tmp2Ant = nodo2->ant;

    nodo2->sgte = nodo1->sgte;
    nodo2->ant = nodo1->ant;

    nodo1->sgte = tmp2Sgte;
    nodo1->ant = tmp2Ant;

    // fin
    Tlista tmp = nodo2;
    nodo2 = nodo1;
    nodo1 = tmp;
  }
}
void mostrarLista(Tlista lista) {
  int i = 0;

  while (lista != NULL) {

    cout << i + 1 << ") " << ' ' << lista->ant << " <- " << lista << " -> "
         << lista->sgte << endl;
    lista = lista->sgte;
    i++;
  }
  cout << endl << endl;
}

int main() {
  Tlista lista = NULL;
  int opcion; // opcion del menu

  system("color 0b");

  do {

    cout << "\n\t\tLISTA ENLAZADA DOBLE SIMPLE\n\n";
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

      Tlista nodo1 = lista;
      Tlista nodo2 = lista->sgte->sgte;

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