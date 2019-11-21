#include <iostream>

using namespace std;

struct elem {
    int dane;
    elem * nast;
    elem* poprz;
};

void insert(int x, int i, elem* &lista) {
    if(i==1){
        elem* nowy=new elem;
        nowy->dane=x;
        nowy->nast=lista;
        nowy->poprz=NULL;
        if(lista!=NULL) lista->poprz=nowy;
        lista=nowy;
    } else if(i>1) {
        elem* temp=lista;
        for(int k=1;k<i;k++)
            temp=temp->nast;
        elem* nowy=new elem;
        nowy->dane=x;
        elem* nastepny=temp->nast;
        temp->nast=nowy;
        if(nastepny!=NULL){
            nastepny->poprz=nowy;
            nowy->poprz=temp;
            nowy->nast=nastepny;
            nastepny=nowy;
        }
    }
}

void remove(elem* &lista) {

}

void remove(int i, elem* &lista) {
    if(i==1){
        elem* wsk=lista;
        lista=lista->nast;
        if(lista!=NULL) lista->poprz=NULL;
        delete wsk;
    } else {
        elem* wsk = lista;
        for(int j=1;j<=i;j++) wsk=wsk->nast;
        wsk->poprz->nast=wsk->nast;
        if(wsk->nast!=NULL) wsk->nast->poprz=wsk->poprz;
        delete wsk;
    }
}

void reverse(elem* &lista) {
    while(lista!=NULL){
        elem* kopia = lista->nast;
        lista->nast = lista->poprz;
        lista->poprz=kopia;
        lista=kopia;
        lista=lista->nast;
    }
}

struct onewayelem {
    int dane;
    onewayelem * nast;
};

void insert(int x, int i, onewayelem* &lista) {
    // ...
}

void to_cyclic(onewayelem* lista) {
    onewayelem* pierwszy = lista;
    while(lista->nast!=NULL) lista=lista->nast;
    lista->nast=pierwszy;
}

void reverse_cyclic(onewayelem* lista) {
    onewayelem* start=lista->nast;
    onewayelem*kopiaP=lista;
    onewayelem*kopiaN=NULL;
    lista=lista->nast;
    do{
        kopiaN=lista->nast;
        lista->nast=kopiaP;
        kopiaP=lista;
        lista=kopiaN;
    } while(lista!=start);
}

struct charelem {
    char znak;
    charelem * nast;
    charelem * poprz;
};

void insert(char x, int i, charelem* &lista) {
    if(i<0) {
        string s = "Indeks poza zakresem";
        throw s;
    }
    if (((int)x<97||(int)x>122)&&(int)x!=42&&(int)x!=43&&(int)x!=45&&(int)x!=47){
        string s="niepoprawny symbol";
        throw s;
    }
    charelem* e=new charelem;
    e->znak=x;
    e->nast=NULL;
    if(i==0){
        e->nast=lista;
        lista=e;
    } else {
        charelem* t=lista;
        for(i-=1;i>0;--i){
            t=t->nast;
            if(t==NULL) {
                string s="indeks poza";
                throw s;
            }
        }
        e->nast=t->nast;
        t->nast=e;
    }
}

bool is_valid_pn(charelem* lista) {
    // ...
    return false;
}

int main()
{
    elem* lista = NULL;

    cout << "Dodawanie oraz usuwanie elementów z listy" << endl;
    insert(1, 1, lista);
    insert(2, 2, lista);
    insert(3, 3, lista);
    insert(4, 4, lista);
    cout << lista->dane << endl; // powinno być 1
    remove(lista);
    cout << lista->dane << endl; // powinno być 2
    remove(3, lista);
    cout << lista->dane << endl; // powinno być 2

    cout << "Odwracanie listy" << endl;
    reverse(lista);
    cout << lista->dane << endl; // powinno być 3

    cout << "Zamiana na listę cykliczną" << endl;
    onewayelem* onewaylista = NULL;
    insert(1, 1, onewaylista);
    insert(2, 2, onewaylista);
    insert(3, 3, onewaylista);
    to_cyclic(onewaylista);
    cout << lista->nast->nast->nast->dane << endl; // powinno być 1

    cout << "Zmiana kierunku listy" << endl;
    reverse_cyclic(onewaylista);
    cout << lista->nast->dane << endl; // powinno być 3

    cout << "Notacja polska" << endl;
    charelem* charlista = NULL;
    insert('/', 1, charlista);
    insert('a', 2, charlista);
    insert('-', 3, charlista);
    insert('b', 4, charlista);
    insert('c', 4, charlista);
    cout << (is_valid_pn(charlista) ? "OK" : "NOT OK") << endl; // powinno być OK
    return 0;
}
