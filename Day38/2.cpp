#include <iostream>
using namespace std;



class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node* node){
    if(node==NULL) return 0;

    return 1+ max(height(node->left), height(node->right));
};


int getBalance(Node* node){
    if(node== NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
};

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2= x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node* minValueNode(Node* node){
    if(node==NULL){
        return NULL;
    }
    Node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}



Node* deleteAVL(Node* root, int key){
    if(root == NULL) return root; // empty tree

    // 1. Perform standard BST deletion
    if(key < root->value){
        root->left = deleteAVL(root->left, key);
    }else if(key > root->value){
        root->right= deleteAVL(root->right, key);
    }else{
        if(root->left == NULL || root->right== NULL){
            Node* temp = (root->left != NULL) ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }else {
                *root = *temp;
            }
            delete temp;
        }
        else{
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteAVL(root->right, temp->value);
        }
    }

    if(root != NULL){
        int balance = getBalance(root);

        if(balance > 1){
            if (getBalance(root->left) >= 0) {
                // LL case
                return rightRotate(root);
            } else {
                // LR case
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balance < -1) {
            if (getBalance(root->right) <= 0) {
                // RR case
                return leftRotate(root);
            } else {
                // RL case
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

    }
return root;


}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}




int main() {
    Node* root = NULL;

    // Insert nodes manually (for demonstration)
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(30);

    cout << "AVL Tree Inorder before deletions: ";
    inorder(root);
    cout << endl;

    // Delete nodes
    root = deleteAVL(root, 20); // delete node with 2 children
    root = deleteAVL(root, 5);  // delete leaf

    cout << "AVL Tree Inorder after deletions: ";
    inorder(root);
    cout << endl;

    return 0;
}