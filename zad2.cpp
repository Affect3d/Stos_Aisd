#include <iostream>

using namespace std;

struct elem {
    int dane;
    elem * nast;
};

void push(elem* &stos, int x) {
    elem* nowy = new elem;
    nowy->dane = x;
    nowy->nast = stos;
    stos = nowy;
}

int pop(elem* &stos) {
    if(stos!=NULL) {
        elem* stary = stos;
        int wynik = stos->dane;
        stos = stos->nast;
        delete stary;
        return wynik;
    } else cout<<"Stos pusty"<<endl;
    return 0;
}

int topEl(elem* stos) {
    if(stos != NULL){
            int wynik = stos->dane;
            return wynik;
    } else cout<<"Stos pusty"<<endl;
    return 0;
}

void add(elem* &pocz_kolejki, elem* &kon_kolejki, int x)
{
    if(kon_kolejki!=NULL) {
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

int next (elem*&pocz_kolejki, elem*&kon_kolejki) {
    if (pocz_kolejki!=NULL) {
        elem* stary = pocz_kolejki;
        int wynik = stary->dane;
        if(pocz_kolejki==kon_kolejki) kon_kolejki=NULL;
        pocz_kolejki = stary->nast;
        delete stary;
        return wynik;
    } else cout<<"Pusta kolejka"<<endl;
}

int firstEl(elem* pocz_kolejki) {
    if(pocz_kolejki != NULL) {
        int wynik = pocz_kolejki->dane;
        return wynik;
    } else cout << "Pusta kolejka"<<endl;
}

bool isEmpty(elem* pocz_kolejki) {
    if(pocz_kolejki==NULL) return true;
    else return false;
}

void twoStacksAdd(elem* &stos1, elem* &stos2, int x) {
    push(stos2,x);
}

int twoStackNext(elem* &stos1, elem* &stos2) {
    if(stos1!=NULL) return pop(stos1);
    else {
        while(stos2!=NULL) {
            push(stos1,pop(stos2));
        }
        if(stos1!=NULL) return pop(stos1);
        else cout<<"Pusta kolejka"<<endl;
    }
    return 0; // usuń tą część
}

const int N=9;
int rozm=0;
int kon=0;
int pocz=0;

void arrayAdd(elem* arr[], int x) {
    //jak policzyc ile elementów
    if(rozm==N) cout<<"pełny"<<endl;
    else {
        arr[kon]=x;
        rozm++;
        kon++;
        if(kon==N) kon=0;
    }
}

int arrayNext(elem* arr[]) {
    if(rozm()==0) cout<<"Pusty"<<endl;
    else {
        int wynik = arr[pocz];
        rozm--;
        pocz++;
        if(pocz==N) pocz=0;
        return wynik;
    }
    return 0; // usuń tą część
}

int arrayfirstEl(elem* arr[]) {
    return arr[0]->dane;
    return 0; // usuń tą część
}

bool arrayIsEmpty(elem* arr[]) {
    if(arr==NULL) return true;
    return false; // usuń tą część
}

void reverseStackElementsWithAdditionalQueue(elem* &stos) {
    //pocz i kon jest potrzebny
    elem* pocz=firstEl(stos);
    elem* kon=NULL;
    while (stos!=NULL) {
        add(pocz, kon, pop(stos));
    }
    while(kon!=NULL) {
        push(stos, next(pocz, kon));
    }
}

int main()
{
    elem* pocz_kolejki = NULL;
    elem* kon_kolejki = NULL;

    cout << "Dodawanie elementów do kolejki oraz pobranie głowy kolejki" << endl;
    add(pocz_kolejki, kon_kolejki, 1);
    add(pocz_kolejki, kon_kolejki, 2);
    add(pocz_kolejki, kon_kolejki, 3);
    add(pocz_kolejki, kon_kolejki, 4);
    cout << firstEl(pocz_kolejki) << endl; // powinno być 1

    cout << "Kolejka na stosach" << endl;
    elem* stos1 = NULL;
    elem* stos2 = NULL;
    twoStacksAdd(stos1, stos2, 1);
    twoStacksAdd(stos1, stos2, 2);
    cout << firstEl(stos1) << endl; // powinno być 1
    cout << twoStackNext(stos1, stos2); // powinno być 1
    cout << firstEl(stos1) << endl; // powinno być 2

    cout << "Pobranie głowy kolejki i zdjęcie elementu" << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl; // powinno być 1
    cout << firstEl(stos1) << endl; // powinno być 2

    cout << "Kolejka na tablicy" << endl;
    elem* kolejka[9];
    arrayAdd(kolejka, 1);
    arrayAdd(kolejka, 2);
    cout << arrayfirstEl(kolejka) << endl; // powinno być 1
    cout << arrayNext(kolejka) << endl; // powinno być 1
    cout << arrayfirstEl(kolejka) << endl; // powinno być 2

    cout << "Odwracanie elementów na stosie" << endl;
    elem* stos = NULL;
    push(stos, 1);
    push(stos, 2);
    push(stos, 3);
    cout << topEl(stos) << endl; // powinno być 3
    reverseStackElementsWithAdditionalQueue(stos);
    cout << topEl(stos) << endl; // powinno być 1
    return 0;
}
