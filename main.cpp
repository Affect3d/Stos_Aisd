#include <iostream>

using namespace std;

struct elem {
int dane;
elem * nast;
};

struct elem* glowa = NULL;

void push(elem* &stos, int x)
{
    //elem *nowy = new elem;
    stos->dane = x;
    stos->nast=glowa;
    glowa=stos;
}

int pop(elem* &stos)
{
    elem *nowy = stos;
    stos = stos->nast;
    delete nowy;
    return stos->dane;
}

int topEl(elem* stos)
{
    struct elem *ptr;
    if(glowa == NULL){
        cout<<"stack is empty";
    } else {
        while (ptr != NULL) {
            if(ptr->dane == stos->dane)
                return ptr->dane;
            ptr = ptr->nast;
        }
    }
    return 0;
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
