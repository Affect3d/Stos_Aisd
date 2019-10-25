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

oid insert(int x, int i, elem* &lista) {
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

oid insert(int x, int i, elem* &lista) {
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

oid insert(int x, int i, elem* &lista) {
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


