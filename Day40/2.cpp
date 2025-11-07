#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";   
    preorder(root->left);        
    preorder(root->right);       
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder (DFS): ";
    preorder(root);
    cout << "\n";

    cout << "Inorder (DFS): ";
    inorder(root);
    cout << "\n";

    cout << "Postorder (DFS): ";
    postorder(root);
    cout << "\n";

    cout << "Level Order (BFS): ";
    levelOrder(root);
    cout << "\n";

    return 0;
}