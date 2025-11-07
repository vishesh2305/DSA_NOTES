#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = right = NULL;
    }
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
};
vector<int> BFS(Node *root)
{
    queue<Node *> q;
    vector<int> result;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        result.push_back(curr->value);
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    };
    return result;
}
int main()
{
    Tree t;
    t.root = new Node(1);
    t.root->left = new Node(2);
    t.root->right = new Node(3);
    t.root->left->left = new Node(4);
    t.root->left->right = new Node(5);
    vector<int> abc = BFS(t.root);
    for (int i = 0; i < abc.size(); i++)
    {
        cout << abc[i] << " ";
    }
    cout << endl;
    return 0;
}