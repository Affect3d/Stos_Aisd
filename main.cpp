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

int main()
{
    elem *newnode = new elem;
    elem *new2 = new elem;
    push(newnode, 4);
    push(new2, 8);
    cout<< topEl(glowa);
    return 0;
}
