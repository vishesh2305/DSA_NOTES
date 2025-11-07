#include <iostream>
#include <queue>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root){

    int data;
    cout << "Enter the data "<< endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root = new node(data);
  

    cout << "Enter data for inserting in left of "<< data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in Right of "<< data << endl;
    root->right = buildtree(root->right);
    return root;
    
}


void levelOrderTraversal(node* root){

    if(root == NULL) return;
    queue<node*> q;
    q.push(root);

        while(!q.empty()){
            node* temp = q.front();
            cout << temp->data<< " ";
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }



int main(){


    node* root = NULL;
    root = buildtree(root);


    levelOrderTraversal(root);

    return 0;

}