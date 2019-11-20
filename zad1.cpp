#include <iostream>

using namespace std;

struct elem {
int dane;
elem * nast;
};

void push(elem* &stos, int x)
{
    elem* nowy = new elem;
    nowy->dane = x;
    nowy->nast = stos;
    stos = nowy;
}

int pop(elem* &stos)
{
    if(stos!=NULL) {
        elem* stary = stos;
        int wynik = stos->dane;
        stos = stos->nast;
        delete stary;
        return wynik;
    } else cout<<"Stos pusty"<<endl;
    return 0;
}

int topEl(elem* stos)
{
    if(stos != NULL){
            int wynik = stos->dane;
            return wynik;
    } else cout<<"Stos pusty"<<endl;
    return 0;
}

bool isEmpty(elem* stos) {
    if (stos==NULL) return true;
    else return false; // usuń tą część
}

void add(elem*&poczkol, elem*&konkol, int x){
    elem*tmp=new elem;
    tmp->dane=x;
    tmp->nast=NULL;
    if(poczkol==NULL) poczkol=tmp;
    if(konkol!=NULL) konkol->nast=tmp;
    konkol=tmp;
}

int next(elem*&poczkol, elem*&konkol){
    if(poczkol!=NULL) {
        int y=poczkol->dane;
        elem*tmp=poczkol;
        if(poczkol->nast==NULL){
            konkol=NULL;
            poczkol=NULL;
        } else {
            poczkol=poczkol->nast;
        }
        delete tmp;
        tmp=NULL;
        return y;
    }
    //cout<<"kolejka pusta"<<endl;
    return 0;
}

void reverseElementsWithAdditionalStack(elem* &stos) {
    elem* tmp=NULL;
    while(stos!=NULL){
        push(tmp,pop(stos));
    }
    stos=tmp;
}

void sortElementsWithAdditionalStack(elem* &stos) {
    elem* stop = NULL;
    elem* stos2 = NULL;
    int min = 0;
    while(stos!=stop){
            min = pop(stos);
            while(stos!=stop){
                    if (topEl(stos)<min){
                        push(stos2,min);
                        min=pop(stos2);
                        } else push(stos2,pop(stos));
            }
            push(stos,min);
            stop=stos;
            while(stos2!=NULL)
                push(stos,pop(stos2));
    }
}

void moveElementsWithAdditionalStack(elem* stos1, elem* &stos2) {
    elem* tmp = NULL;
    while(stos1!=NULL){
        push(tmp,pop(stos1));
    }
    while(tmp!=NULL){
        push(stos2,pop(tmp));
    }

}

void moveElementsWithAdditionalVariables(elem* stos1, elem* &stos2) {
    int i=0;
    while (stos1!=NULL){
        while(stos1!=NULL){
            push(stos2, pop(stos1));
            i++;
        }
        int x=pop(stos2);
        i--;
        while(i>0) {
            push(stos1, pop(stos2));
            i--;
        }
        push(stos2, x);
    }
}

int main()
{
    elem* stos1 = NULL;
    elem* stos2 = NULL;

    cout << "Dodawanie elementów do stosu oraz pobranie wierzchołka" << endl;
    push(stos1, 1);
    push(stos1, 2);
    push(stos1, 3);
    push(stos1, 4);
    cout << topEl(stos1) << endl; // powinno być 4

    cout << "Pobranie wierzchołka i zdjęcie elementu" << endl;
    cout << pop(stos1) << endl; // powinno być 4
    cout << topEl(stos1) << endl; // powinno być 3

    cout << "Odwracanie elementów na stosie" << endl;
    reverseElementsWithAdditionalStack(stos1);
    cout << topEl(stos1) << endl; // powinno być 1

    cout << "Sortowanie elementów na stosie" << endl;
    sortElementsWithAdditionalStack(stos1);
    cout << topEl(stos1) << endl; // powinno być 3

    cout << "Przenoszenie elementów między stosami" << endl;
    stos2 = NULL;
    elem* stos3 = NULL;
    moveElementsWithAdditionalStack(stos1, stos2);
    moveElementsWithAdditionalVariables(stos1, stos3);
    cout << topEl(stos2) << endl; // powinno być 3
    cout << topEl(stos3) << endl; // powinno być 3
    return 0;
}
