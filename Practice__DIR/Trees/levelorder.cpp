#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root){



    int data;
    cout << "Enter the data ";
    cin >> data;


    if(data == -1) return NULL;

    root = new node(data);

    cout << "Enter the value of left node of root "<< data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the value of right node of root "<< data << endl;
    root->right = buildtree(root->right);

    return root;
}


void levelordertraversal(node* root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout << temp ->data << " ";
        q.pop();

        if(temp == NULL){
            cout << endl;
        }

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    levelordertraversal(root);
}