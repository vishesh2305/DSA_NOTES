#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int findMax(Node* root) {
    if (root == nullptr)
        return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(5);

    cout << findMax(root) << "\n";
    return 0;
}