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
