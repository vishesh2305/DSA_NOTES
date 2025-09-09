#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    };
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void insertAtFront(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    void rotatingDLL(int N)
    {
        if (head == NULL || N <= 0 || N % size == 0) return;

        N = N%size;

        Node* current = head;
        for(int i=0; i<N; i++){
            current = current->next;
        }

        Node* newHead = current->next;
        newHead->prev = NULL;
        current->next = NULL;

        tail->next = head;
        head->prev= tail;

        head= newHead;
        tail=current;
    }
};

int main()
{
}