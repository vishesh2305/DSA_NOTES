#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertBST(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }

    if (value < root->value)
    {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insertBST(root->right, value);
    }
    return root;
};

void inorder(Node *root)
{

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->value << " ";

    inorder(root->right);
}

bool findIterative(Node *root, int key)
{
    Node *current = root;
    while (current != NULL)
    {
        if (key == current->value)
        {
            return true;
        };
        if (key < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
};

Node *searchright(Node *root)
{
    Node *current = root;
    current = current->right;
    return current;
};

Node *searchleft(Node *root)
{
    Node *current = root;
    current = current->left;
    return current;
}

bool findrecursion(Node *root, int key)
{

    if (root == NULL)
    {
        return false;
    };

    if (root->value == key)
    {
        return true;
    }
    else if (key < root->value)
    {
        return findrecursion(root->left, key);
    }
    else
    {
        return findrecursion(root->right, key);
    }
}

int MinBSR(Node *root)
{
    if (root == NULL)
        return -1;
    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    };
    return current->value;
}

int MaxBSR(Node *root)
{
    if (root == NULL)
        return -1;
    Node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    };
    return current->value;
}

bool isValidBST(Node *root, int minVal = INT_MIN, int maxVal = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->value <= minVal || root->value >= maxVal)
    {
        return false;
    }
    return isValidBST(root->left, minVal, root->value) && isValidBST(root->right, root->value, maxVal);
}


Node* minValueNode(Node* root){

    if(root == NULL){
        return NULL;
    };
    
    Node* current = root;

    while(current->left != NULL){
        current = current->left;
    };

    return current;

}

Node* deleteBSTNode(Node* root, int key){

    if(root == NULL) return root;

    if(key < root->value){
        root->left = deleteBSTNode(root->left, key);
    }

    else if(key > root->value){
        root->right = deleteBSTNode(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->value = temp->value;

        root->right = deleteBSTNode(root->right, temp->value);

    }
}

int main()
{
    Node *root = NULL;

    int values[] = {10, 20, 40, 50, 30};

    for (int i : values)
    {
        root = insertBST(root, i);
    }
    cout << "Printing Inorder\n";
    inorder(root);

    return 0;
};