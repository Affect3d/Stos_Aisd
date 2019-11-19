#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data): data(data) {
        this->left = NULL;
        this->right = NULL;
    }
};

bool search(node* tree, int x) {
    // ...
    return false;
}

int node_count(node* tree) {
    // ...
    return 0;
}

int leaves_count(node* tree) {
    // ...
    return 0;
}

int right_children_count(node* tree) {
    // ...
    return 0;
}

int tree_height(node* tree) {
    // ...
    return 0;
}

bool is_balanced(node* tree) {
    // ...
    return false;
}

bool is_BST(node* tree) {
    // ...
    return false;
}

void delete_leaves(node* &tree) {
    // ...
}

//struktrury drzewa

void print_tree(node* tree, int depth, char prefix) {
    // ...
}

node* mirror_tree(node* tree) {
    // ...
    return NULL;
}

struct node_calc {
    char op;
    int number;
    node_calc* left;
    node_calc* right;
    node_calc(char op, int number): op(op), number(number) {}
};

int eval(node_calc* tree) {
    // ...
    return 0;
}

node* create_perfect_tree(int* a, const int k) {
    // ...
    return NULL;
}

int main()
{
    // Przykładowe drzewo START
node* tree = new node(6);
tree->left = new node(2);
tree->left->left = new node(1);
tree->left->right = new node(4);
tree->left->right->left = new node(3);
tree->left->right->right = new node(5);
tree->right = new node(7);
tree->right->right = new node(9);
tree->right->right->left = new node(8);
// Przykładowe drzewo KONIEC

cout << "Szukanie elementów w drzewie" << endl;
// cout << (search(tree, 3) ? "FOUNDED" : "NOT FOUNDED") << endl; // powinno być FOUNDED
// cout << (search(tree, 0) ? "FOUNDED" : "NOT FOUNDED") << endl; // powinno być NOT FOUNDED

cout << "Liczba wierzchołków w drzewie" << endl;
// cout << node_count(tree)  << endl; // powinno być 9

cout << "Liczba liści w drzewie" << endl;
// cout << leaves_count(tree)  << endl; // powinno być 4

cout << "Liczba prawych synów w drzewie" << endl;
// cout << right_children_count(tree)  << endl; // powinno być 4

cout << "Wysokość drzewa" << endl;
// cout << tree_height(tree)  << endl; // powinno być 3

cout << "Sprawdzanie czy drzewo jest zbalansowane" << endl;
// cout << (is_balanced(tree) ? "BALANCED" : "NOT BALANCED")  << endl; // powinno być NOT BALANCED

cout << "Sprawdzanie czy drzewo jest BST" << endl;
// cout << (is_BST(tree) ? "BST" : "NOT BST")  << endl; // powinno być BST

cout << "Usuwanie liści z drzewa" << endl;
// delete_leaves(tree);
// cout << node_count(tree)  << endl; // powinno być 5

cout << "Wyświetlanie drzewa" << endl;
// print_tree(tree, 2, '.');
/*
Powinno być
6
.2
..4
.7
..9
*/

cout << "Odbicie lustrzane drzewa" << endl;
// mirror_tree(tree);
// print_tree(tree, 2, '.');
/*
Powinno być
6
.7
..9
.2
..4
*/

cout << "Wyrażenie arytmetyczne" << endl;
node_calc* tree_calc = new node_calc('*',0);
tree_calc->left = new node_calc('+',0);
tree_calc->left->left = new node_calc(' ',7);
tree_calc->left->right = new node_calc(' ',8);
tree_calc->right = new node_calc('-',0);
tree_calc->right->left = new node_calc(' ',5);
tree_calc->right->right = new node_calc(' ',4);
// cout << eval(tree_calc)  << endl; // powinno być 15

cout << "Perfekcyjne drzewo" << endl;
int a[] = { 1, 2, 3, 4, 5, 6, 7 };
// tree = create_perfect_tree(a, 3);
// print_tree(tree, 2, '.');
/*
Powinno być
4
.2
..1
..3
.6
..5
..7
*/
    return 0;
}
