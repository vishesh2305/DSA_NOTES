#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* leftchild;
    Node* rightchild;
    Node(int data){
        this->data = data;
        leftchild=rightchild = NULL;
    }
};


void preordertraversal(Node* root){
    if(root == NULL) return;

    cout << root->data << endl;

    preordertraversal(root->leftchild);
    preordertraversal(root->rightchild);
}


int main(){
    Node* root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->leftchild->rightchild = new Node(5);

    cout << "preordertraversal "<< endl;
    preordertraversal(root);



   
}