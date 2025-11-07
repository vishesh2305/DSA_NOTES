#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }




};

class Tree{
    public:
    node* root;

    Tree(){
        root == NULL;
    }
};


bool find(node* root , int value){
    if(root == NULL) return false;

    if(root->data == value) return true;

    return find(root->left,value ) || find(root->right , value);
}



int main(){
    Tree t;

    t.root = new node(1);
    t.root->left = new node(20);
    t.root->right = new node(50);
    t.root->left->left=new node(30);
    t.root->left->right=new node(40);
    t.root->right->right = new node(60);
    t.root->right->right->left = new node(70);
    t.root->right->right->right = new node(90);

    cout << find(t.root, 400);  // 0 or 1 // true or false

    return 0;
}