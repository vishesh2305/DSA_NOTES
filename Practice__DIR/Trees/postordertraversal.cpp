#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* leftchild;
    Node* rightchild;
    Node(int data){
        this->data = data;
        leftchild = rightchild = NULL;
    }
};


void postordertraversal(Node* root){
    if(root == NULL) return;
    postordertraversal(root->leftchild);
    postordertraversal(root->rightchild);

    cout << root->data <<" ";
}


int main(){
    Node* root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->leftchild->rightchild = new Node(5);

    postordertraversal(root);

}