#include <iostream>
using namespace std;

// Struktur node tree
struct Node
{
    int data;
    Node* child1;
    Node* child2;
    Node* child3;

    Node(int value)
    {
        data = value;
        child1 = NULL;
        child2 = NULL;
        child3 = NULL;
    }
};

// Preorder traversal
void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";

        preorder(root->child1);
        preorder(root->child2);
        preorder(root->child3);
    }
}

int main()
{
    // Membuat node
    Node* root = new Node(1);

    root->child1 = new Node(2);
    root->child2 = new Node(3);
    root->child3 = new Node(4);

    root->child1->child1 = new Node(5);
    root->child1->child2 = new Node(6);

    root->child1->child2->child1 = new Node(8);

    root->child3->child1 = new Node(7);

    cout << "Hasil Preorder Traversal:\n";

    preorder(root);

    return 0;
}