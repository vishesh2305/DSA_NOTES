#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value){
        this->value = value;
        left = right = NULL;
    }
};


class Tree{
    public:
    Node* root;
    Tree(){
        root = NULL;
    }
};


void arraytotree(vector<int> &arr, int i){

    if(i > arr.size()) return NULL;


    Node* root = new Node(arr[i]);

    root->left = arraytotree(arr, 2*i + 1);
    root->right = arraytotree(arr, 2*i + 2);

    return root;



}




