#include <iostream>
using namespace std;

struct elem {
    int dane;
    elem * nast;
};

void push(elem* &stos, int x) {
    // ...
}

int pop(elem* &stos) {
    // ...
    return 0; // usuń tą część
}

int topEl(elem* stos) {
    // ...
    return 0; // usuń tą część
}

void insert(int x, int i, elem* &lista) {
    // ...
}

void remove(int i, elem* &lista) {
    // ...
}

int read(int i, elem* lista) {
    // ...
    return 0; // usuń tą część
}

int size(elem* lista) {
    // ...
    return 0; // usuń tą część
}

void print(elem* lista) {
    // ...
}

void printWithReverseOrderWithStack(elem* &lista) {
    // ...
}

void printWithReverseOrder(elem* &lista) {
    // ...
}

void destroy(elem* &lista) {
    // ...
}

elem* search(int x, elem* lista) {
    // ...
    return NULL; // usuń tą część
}

struct elem_poly {
    int expo;
    int coef;
    elem_poly(int expo, int coef): expo(expo), coef(coef) {}
    elem_poly * nast;
};

elem_poly* polyadd(elem_poly* l1, elem_poly* l2) {
    // ...
    return NULL; // usuń tą część
}

int main() 
{
  elem* lista = NULL;

cout << "Dodawanie, usuwanie oraz czytanie elementów z listy" << endl; 
// insert(1, 1, lista);
// insert(2, 2, lista);
// insert(3, 3, lista);
// insert(4, 4, lista);
// remove(1, lista);
// cout << read(1, lista) << endl; // powinno być 2

cout << "Pobieranie rozmiaru listy" << endl;
// cout << size(lista) << endl; // powinno być 3

cout << "Wypisywanie elementów listy" << endl;
// cout << print(lista) << endl; // powinno być 2, 3, 4

cout << "Wypisywanie elementów listy w odwrotnej kolejności z użyciem stosu" << endl;
// cout << printWithReverseOrderWithStack(lista) << endl; // powinno być 4, 3, 2

cout << "Wypisywanie elementów listy w odwrotnej kolejności bez dodatkowych struktur" << endl;
// cout << printWithReverseOrder(lista) << endl; // powinno być 4, 3, 2

cout << "Usuwanie całej listy" << endl;
// elem* listaDoUsuniecia = NULL;
// insert(1, 1, listaDoUsuniecia);
// destroy(listaDoUsuniecia);
// cout << (listaDoUsuniecia == NULL ? "T" : "N") << endl; // powinno być T

cout << "Przeszukiwanie" << endl;
// elem* znalezionyElement = search(4, lista);
// cout << (znalezionyElement == NULL ? "T" : "N") << endl; // powinno być N
// znalezionyElement = search(5, lista);
// cout << (znalezionyElement == NULL ? "T" : "N") << endl; // powinno być T

cout << "Wielomiany" << endl;
elem_poly* ep1 = new elem_poly(5,2);
ep1->nast = new elem_poly(1,7);
ep1->nast->nast = new elem_poly(0,4);
elem_poly* ep2 = new elem_poly(2,-1);
// elem_poly* ep3 = polyadd(ep1, ep2);
// cout << ep3->expo << " " << expo->nast->expo << endl; // powinno być 5 2
}
