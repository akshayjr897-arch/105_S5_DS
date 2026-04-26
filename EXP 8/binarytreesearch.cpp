#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Insert into BST
Node* insert(Node* root, int x) {
    if (!root) return new Node{x, NULL, NULL};

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Search in BST
bool search(Node* root, int key) {
    if (!root) return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, x, key;
    Node* root = NULL;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    while (n--) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter element to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Element found";
    else
        cout << "Element not found";
}