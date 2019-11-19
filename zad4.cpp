#include <iostream>
using namespace std;

struct elem {
    int dane;
    elem * nast;
    elem * poprz;
};

void insert(int x, int i, elem* &lista) {
    // ...
}

void remove(elem* &lista) {
    // ...
}

void remove(int i, elem* &lista) {
    // ...
}

void reverse(elem* &lista) {
    // ...
}

struct onewayelem {
    int dane;
    elem * nast;
};

void insert(int x, int i, onewayelem* &lista) {
    // ...
}

void to_cyclic(onewayelem* lista) {
    // ...
}

void reverse_cyclic(onewayelem* lista) {
    // ...
}

struct charelem {
    char znak;
    elem * nast;
    elem * poprz;
};

void insert(char znak, int i, charelem* &lista) {
    // ...
}

bool is_valid_pn(elem* lista) {
    // ...
    return false;
}

int main()
{
    elem* lista = NULL;

cout << "Dodawanie oraz usuwanie elementów z listy" << endl; 
// insert(1, 1, lista);
// insert(2, 2, lista);
// insert(3, 3, lista);
// insert(4, 4, lista);
// cout << lista->dane << endl; // powinno być 1
// remove(lista);
// cout << lista->dane << endl; // powinno być 2
// remove(3, lista);
// cout << lista->dane << endl; // powinno być 2

cout << "Odwracanie listy" << endl;
// reverse(lista);
// cout << lista->dane << endl; // powinno być 3

cout << "Zamiana na listę cykliczną" << endl;
onewayelem* onewaylista = NULL;
// insert(1, 1, onewaylista);
// insert(2, 2, onewaylista);
// insert(3, 3, onewaylista);
// to_cyclic(onewaylista);
// cout << lista->nast->nast->nast->dane << endl; // powinno być 1

cout << "Zmiana kierunku listy" << endl;
// reverse_cyclic(onewaylista);
// cout << lista->nast->dane << endl; // powinno być 3

cout << "Notacja polska" << endl;
charelem* charlista = NULL;
// insert('/', 1, charlista);
// insert('a', 2, charlista);
// insert('-', 3, charlista);
// insert('b', 4, charlista);
// insert('c', 4, charlista);
// cout << (is_valid_pn(charlista) ? "OK" : "NOT OK") << endl; // powinno być OK
    return 0;
}
