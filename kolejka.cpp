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

void add(elem* &kon_kolejki, elem* &kon_kolejki, int x)
{
    if(kon!=NULL) {
        elem* nowy = new elem;
        nowy->dane = x;
        nowy->nast = NULL;
        kon_kolejki->nast = nowy;
        kon_kolejki = nowy;
    }else {
        elem* nowy = new elem;
        nowy->dane = x;
        nowy->nast = NULL;
        kon_kolejki = nowy;
        kon_kolejki = nowy;
    }
}

int next (elem*& pocz_kolejki, elem* &kon_kolejki) {
    if (pocz!=NULL) {
        elem* stary = pocz;
        int wynik = stary->dane;
        if(pocz_kolejki==kon_kolejki) kon_kolejki=NULL;
        pocz_kolejki = stary->nast;
        delete stary;
        return wynik;
    } else cout<<"Pusta kolejka"<<endl;
}

int firstEl(elem* pocz_kolejki) {
    if(pocz != NULL) {
        int wynik = pocz_kolejki->dane;
        return wynik;
    } else cout << "Pusta kolejka"<<endl;
}

bool isEmpty(else* pocz_kolejki) {
    if(pocz_kolejki==NULL) return true;
    else return false;
}

void twoStacksAdd(elem* &stos1, elem* &stos2, int x) {
    // ...
}

int twoStackNext(elem* &stos1, elem* &stos2) {
    // ...
    return 0; // usuń tą część
}

void arrayAdd(elem* arr[], int x) {
    // ...
}

int arrayNext(elem* arr[]) {
    // ...
    return 0; // usuń tą część
}

int arrayfirstEl(elem* arr[]) {
    // ...
    return 0; // usuń tą część
}

bool arrayIsEmpty(elem* arr[]) {
    // ...
    return false; // usuń tą część
}

void reverseStackElementsWithAdditionalQueue(elem* &stos) {
    // ...
}

int main() 
{
    elem* pocz_kolejki = NULL;
    elem* kon_kolejki = NULL;

    cout << "Dodawanie elementów do kolejki oraz pobranie głowy kolejki" << endl; 
    // add(pocz_kolejki, kon_kolejki, 1);
    // add(pocz_kolejki, kon_kolejki, 2);
    // add(pocz_kolejki, kon_kolejki, 3);
    // add(pocz_kolejki, kon_kolejki, 4);
    // cout << firstEl(pocz_kolejki) << endl; // powinno być 1

    cout << "Kolejka na stosach" << endl;
    elem* stos1 = NULL;
    elem* stos2 = NULL;
    // twoStacksAdd(stos1, stos2, 1);
    // twoStacksAdd(stos1, stos2, 2);
    // cout << firstEl(stos1) << endl; // powinno być 1
    // cout << twoStackNext(stos1, stos2); // powinno być 1
    // cout << firstEl(stos1) << endl; // powinno być 2
    
    cout << "Pobranie głowy kolejki i zdjęcie elementu" << endl;
    // cout << next(pocz_kolejki, kon_kolejki) << endl; // powinno być 1
    // cout << firstEl(stos1) << endl; // powinno być 2

    cout << "Kolejka na tablicy" << endl;
    elem* kolejka[9];
    // arrayAdd(kolejka, 1);
    // arrayAdd(kolejka, 2);
    // cout << arrayfirstEl(kolejka) << endl; // powinno być 1
    // cout << arrayNext(kolejka) << endl; // powinno być 1
    // cout << arrayfirstEl(kolejka) << endl; // powinno być 2

    cout << "Odwracanie elementów na stosie" << endl;
    elem* stos = NULL;
    // push(stos, 1);
    // push(stos, 2);
    // push(stos, 3);
    // cout << topEl(stos) << endl; // powinno być 3
    // reverseStackElementsWithAdditionalQueue(stos);
    // cout << topEl(stos) << endl; // powinno być 1
        return 0;   
}

void print(elem* pocz_kolejki) {
    elem* temp = pocz_kolejki;
    while (temp != NULL) {
        if (temp!=pocz_kolejki) {
            cout<<" <- ";
        }
        cout<<temp->dane;
        temp=temp->nast;
    }
    cout<<endl;
}
