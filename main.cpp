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

bool isEmpty(ele* stos)
{
    if(stos == NULL)
        return true;
    else return false;
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

void Przenies(elem*& stos1, elem*& stos2)
{
    elem* licznik = stos1;
    int n=0;
}

int main()
{
    elem *newnode = new elem;
    elem *new2 = new elem;
    push(newnode, 4);
    push(new2, 8);
    cout<< topEl(glowa);
    return 0;
}
