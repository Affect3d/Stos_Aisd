#include <iostream>

using namespace std;

struct elem {
int dane;
elem * nast;
};

void push(elem* &stos, int x)
{
    elem *temp = new elem;
    temp->dane = x;
    temp->nast=stos;
    stos=tmp;
}

int pop(elem* &stos)
{
    if(stos!=NULL) {
        elem* temp = stos;
        stos = stos->nast;
        int dana = temp->dane;
        delete temp;
        return dana;
    } else {
        cout<<"Stos pusty"<<endl;
        return 0;
    }
}

int topEl(elem* stos)
{
    if(stos != NULL){
        return stos->dane;
    } else {
       cout<<"Stos pusty"<<endl;
        return 0;
    }
}

bool isEmpty(elem* stos) {
    // ...
    return false; // usuń tą część
}

void reverseElementsWithAdditionalStack(elem* &stos) {
    // ...
}

void sortElementsWithAdditionalStack(elem* &stos) {
    // ...
}

void moveElementsWithAdditionalStack(elem* stos1, elem* &stos2) {
    // ...
}

void moveElementsWithAdditionalVariables(elem* stos1, elem* &stos2) {
    // ...
}

void insert(int x, int i, elem* &lista) {
    elem *temp = lista;
    if(i==1) {
        push(lista, x);
    } else if (temp->nast == 0) {
        elem *nowy = new elem;
        nowy->dane= x;
        temp->nast=nowy;
    }
    for (int j=2; j<i;j++) {
        if(j==i-1) {
                elem *nowy = new elem;
                nowy->dane= x;
                nowy->nast = temp->nast;
                temp->nast = nowy;
        }
        else temp = temp->nast;
    }
    lista = temp;
}

void print(elem* lista) {
    elem* temp = lista;
    while (temp != NULL) {
        if (temp!=lista) {
            cout<<" <- ";
        }
        cout<<temp->dane;
        temp=temp->nast;
    }
    cout<<endl;
}

int size(elem* lista) {
    int sum=0;
    while (lista != NULL) {
        if(lista->nast !=NULL)
            lista = lista->nast;
        sum++;
    }
    return sum;
}

void remove(int i, elem* &lista) {
    if(i==1) {
        elem *temp = lista;
        lista = temp->nast;
    } else {
        elem *temp = lista;
        int j=1;
        while (temp) {
            if(j+1==i) break;
            temp=temp->nast;
            j++;
        }
        if(temp->nast->nast==0) temp->nast=0;
        else temp->nast=temp->nast-nast;
    }
}

void SortujStos(elem*& stos) {
    elem* temp = NULL;
    int n=0;
    while(stos!=NULL) {
        push(temp, pop(stos));
        n++;
    }
    stos=temp;
    temp=NULL;
    while(n>1) {
        int m =1;
        int min = pop(stos);
        while(m<n) {
            if(topEl(stos)<min) {
                push(temp, min);
                min=pop(stos);
            } else {
                push(temp, pop(stos));
            }
            m++;
        }
        push(stos, min);
        while(temp!=NULL) {
            push(stos, pop(temp));
        }
        n--;
    }
}

void PrzeniesStos(elem*& stos1, elem*& stos2)
{
    elem* temp=NULL;
    while(stos!=NULL) {
        push(temp, pop(stos1));
    }
    while(temp!= NULL) {
        push(stos2, pop(temp));
    }
}

int main() {
    elem* lista = NULL;

    cout << "Dodawanie, usuwanie oraz czytanie elementów z listy" << endl; 
    // insert(1, 1, lista);
    // insert(2, 2, lista);
    // insert(3, 3, lista);
    // insert(4, 4, lista);
    // remove(1, lista);
    // cout << read(1, lista) << endl; // powinno być 2
    
    cout << "Pobranie wierzchołka i zdjęcie elementu" << endl;
// cout << pop(stos1) << endl; // powinno być 4
// cout << topEl(stos1) << endl; // powinno być 3

cout << "Odwracanie elementów na stosie" << endl;
// reverseElementsWithAdditionalStack(stos1);
// cout << topEl(stos1) << endl; // powinno być 1

cout << "Sortowanie elementów na stosie" << endl;
// sortElementsWithAdditionalStack(stos1);
// cout << topEl(stos1) << endl; // powinno być 3

cout << "Przenoszenie elementów między stosami" << endl;
elem* stos2 = NULL;
elem* stos3 = NULL;
// moveElementsWithAdditionalStack(stos1, stos2);
// moveElementsWithAdditionalVariables(stos1, stos3);
// cout << topEl(stos2) << endl; // powinno być 3
// cout << topEl(stos3) << endl; // powinno być 3

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

    cout << "Ulamki Fareya" << endl;
    // elem_farey* ef = ulamek_fareya(4);
    // cout << ef->dzielnik << " " << ef->nast->dzielnik << " " << ef->nast->nast->dzielnik << endl; // powinno być 1 4 3
}
