#include <iostream>
#include <algorithm>   
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int findDepth(Node* root, int x) {
    if (root == nullptr) return -1;

    int dist = -1;

    if ((root->data == x) ||
        (dist = findDepth(root->left, x)) >= 0 ||
        (dist = findDepth(root->right, x)) >= 0)
        return dist + 1;

    return dist;
}

int findHeightUtil(Node* root, int x, int &height) {
    if (root == nullptr) return -1;

    int leftHeight = findHeightUtil(root->left, x, height);
    int rightHeight = findHeightUtil(root->right, x, height);

    int ans = max(leftHeight, rightHeight) + 1;

    if (root->data == x)
        height = ans;

    return ans;
}

int findHeight(Node* root, int x) {
    int h = -1;
    findHeightUtil(root, x, h);
    return h;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->left->right = new Node(25);
    root->left->right->right = new Node(45);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    int k = 25;

    cout << "Depth of node " << k << ": " << findDepth(root, k) << "\n";
    cout << "Height of node " << k << ": " << findHeight(root, k) << "\n";

    return 0;
}