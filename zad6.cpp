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

void print_tree(node* tree, int depth, char prefix) {
    // ...
}

void insert_bst_tree(node* &tree, node* node) {
    // ...
}

void remove_node_from_bst_tree(node* &tree, node* node) {
    // ...
}

bool search_in_bst_tree(node* bst_tree) {
    // ...
    return false;
}

int main() {
    node* nodes[9] = { new node(8), new node(3), new node(1), new node(6), new node(4), new node(7), new node(10),
                  new node(14), new node(13) };
node* tree = NULL;
cout << "Wprowadzanie węzłów do drzewa BST" << endl;
for (int i = 0; i < 9; ++i) {
    // insert_bst_tree(tree, nodes[i]);
}
// print_tree(tree, 3, '.');
/*
Powinno być:
8
.3
..1
..6
...4
...7
.10
..14
...13
*/

cout << "Usuwanie węzła do drzewa BST" << endl;
// remove_node_from_bst_tree(tree, nodes[1]);
// print_tree(tree, 3, '.');
/*
Powinno być:
8
.4
..1
..6
...7
.10
..14
...13
*/

cout << "Wyszukiwanie wartości w drzewie BST" << endl;
// cout << (search_in_bst_tree(tree, 13) ? "FOUNDED" : "NOT FOUNDED") << endl; // powinno być FOUNDED
// cout << (search_in_bst_tree(tree, 3) ? "FOUNDED" : "NOT FOUNDED") << endl; // powinno być NOT FOUNDED
return 0;
}
