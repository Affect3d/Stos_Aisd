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

void insert(int x, int i, elem* &lista) {
    if(i==1){
        elem*nowy = new elem;
        nowy->dane = x;
        nowy->nast=lista;
        lista=nowy;
    } else if(i>1) {
        elem* nowy = new elem;
        nowy->dane=x;
        elem* poprz = lista;
        int licznik = 0;
        while(licznik!=(i-2)) {
            licznik++;
            poprz=poprz->nast;
            if(poprz==NULL) cout<<"za krotka"<<endl;
        }
        nowy->nast=poprz->nast;
        poprz->nast=nowy;
    } else cout<<"bledne dane";
}

void remove(int i, elem* &lista) {
    if(lista!=NULL) {
        if(i==1) {
            elem* stary = lista;
            lista=lista->nast;
            delete stary;
        } else if(i>1) {
            elem* poprz = lista;
            int licznik = 0;
            while(licznik!=(i-2)) {
                licznik++;
                poprz=poprz->nast;
                if(poprz==NULL) cout<<"mała lista"<<endl;
            }
            elem* stary = poprz->nast;
            if(stary==NULL) cout<<"brak elementu";
            poprz->nast=stary->nast;
            delete stary;
        } else cout<<"bledne dane";
    } else cout<<"pusta lista";
}

int read(int i, elem* lista) {
    if(lista!=NULL) {
        if(i>=1) {
            elem* wyn = lista;
            int licznik=0;
            while(licznik!=(i-1)) {
                licznik++;
                wyn=wyn->nast;
                if(wyn==NULL) cout<<"krotka lista";
            }
            int wynik = wyn->dane;
            return wynik;
        }
        else cout<<"bledne dane";
    }
    else cout<<"pusta lista";
    return 0;
}

int size(elem* lista) {
    if(lista==NULL) return 0;
    else {
        int licznik=0;
        while(lista!=NULL) {
            licznik++;
            lista=lista->nast;
        }
    return licznik;
    }
}

void print(elem* lista) {
    if(lista==NULL) cout<<"pusta lista";
    else {
        while(lista!=NULL) {
            cout<<lista->dane<<endl;
            lista=lista->nast;
        }
    }
}

void printWithReverseOrderWithStack(elem* &lista) {
    elem* stos=NULL;
    for(int i=1;i<size(lista);i++){
        push(stos, read(i,lista));
    }
    while(stos!=NULL) {
        cout<<"Element z stosu: "<<pop(stos)<<endl;
    }
}

void printWithReverseOrder(elem* &lista) {
    for(int i=size(lista); i!=0;i--) {
        cout<< "Element: "<<read(i, lista)<<endl;
    }
}

void destroy(elem* &lista) {
    if(lista==NULL) cout<<"pusta";
    else {
        elem* temp = lista;
        while(temp!=NULL){
            elem* stary=temp;
            temp=temp->nast;
            delete stary;
        }
    }
}

elem* search(int x, elem* lista) {
    elem* wynik =lista;
    while(lista!=NULL) {
        if(wynik->dane==x) return wynik;
        wynik=wynik->nast;
    }
    cout<<"nie znaleziono";
    return NULL;
}

struct elem_poly {
    int wykl;
    int wspolcz;
    elem_poly(int wykl, int wspolcz): wykl(wykl), wspolcz(wspolcz) {}
    elem_poly * nast;
};

void insert(int x,int y, int i, elem_poly* &lista) {
    if(i==1){
        elem_poly*nowy = new elem_poly(x,y);
        nowy->nast=lista;
        lista=nowy;
    } else if(i>1) {
        elem_poly* nowy = new elem_poly(x,y);
        elem_poly* poprz = lista;
        int licznik = 0;
        while(licznik!=(i-2)) {
            licznik++;
            poprz=poprz->nast;
            if(poprz==NULL) cout<<"za krotka"<<endl;
        }
        nowy->nast=poprz->nast;
        poprz->nast=nowy;
    } else cout<<"bledne dane";
}

elem_poly* polyadd(elem_poly* w1, elem_poly* w2) {
    elem_poly* t=NULL;
    int i=0;
    while(w1!=NULL || w2 !=NULL){
        if(w1!=NULL&&w2!=NULL&&w1->wykl==w2->wykl){
            insert(w1->wykl, w1->wspolcz+w2->wspolcz,i++,t);
            w1=w1->nast;
            w2=w2->nast;
        }
        else if((w1!=NULL&&w2!=NULL&&w1->wykl>w2->wykl)||(w1!=NULL&&w2==NULL)){
            insert(w1->wykl, w1->wspolcz, i++, t);
            w1=w1->nast;
        }
        else if ((w1!=NULL&&w2!=NULL&&w1->wykl<w2->wykl)||(w1==NULL&&w2!=NULL)){
            insert(w1->wykl, w2->wspolcz,i++,t);
            w2=w2->nast;
        }
    }
    return t;
}

int main()
{
    elem* lista = NULL;

    cout << "Dodawanie, usuwanie oraz czytanie elementów z listy" << endl;
    insert(1, 1, lista);
    insert(2, 2, lista);
    insert(3, 3, lista);
    insert(4, 4, lista);
    remove(1, lista);
    cout << read(1, lista) << endl; // powinno być 2

    cout << "Pobieranie rozmiaru listy" << endl;
    cout << size(lista) << endl; // powinno być 3

    cout << "Wypisywanie elementów listy" << endl;
    print(lista); // powinno być 2, 3, 4

    cout << "Wypisywanie elementów listy w odwrotnej kolejności z użyciem stosu" << endl;
    printWithReverseOrderWithStack(lista); // powinno być 4, 3, 2

    cout << "Wypisywanie elementów listy w odwrotnej kolejności bez dodatkowych struktur" << endl;
    printWithReverseOrder(lista); // powinno być 4, 3, 2

    cout << "Usuwanie całej listy" << endl;
    elem* listaDoUsuniecia = NULL;
    insert(1, 1, listaDoUsuniecia);
    destroy(listaDoUsuniecia);
    cout << (listaDoUsuniecia == NULL ? "T" : "N") << endl; // powinno być T

    cout << "Przeszukiwanie" << endl;
    elem* znalezionyElement = search(4, lista);
    cout << (znalezionyElement == NULL ? "T" : "N") << endl; // powinno być N
    znalezionyElement = search(5, lista);
    cout << (znalezionyElement == NULL ? "T" : "N") << endl; // powinno być T

    cout << "Wielomiany" << endl;
    elem_poly* ep1 = new elem_poly(5,2);
    ep1->nast = new elem_poly(1,7);
    ep1->nast->nast = new elem_poly(0,4);
    elem_poly* ep2 = new elem_poly(2,-1);
    elem_poly* ep3 = polyadd(ep1, ep2);
    cout << ep3->wykl << " " << ep3->nast->wykl << endl; // powinno być 5 2
    return 0;
}
