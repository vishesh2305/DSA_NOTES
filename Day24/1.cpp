#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
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
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    }

    void insertatfist(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = newnode;
        }
        else
        {

            newnode->next = head;
            head = newnode;
            tail->next = head;

            size++;
        };
    }

    void display()
    {
        Node *current = head;
        if (head == NULL)
            return;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
    }

    void deleteatfront()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            head = tail = NULL;
            tail->next = head;
        }
        Node *current = head;
        head = head->next;
        delete current;
        tail->next = head;
    }

    void deleteatEnd()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            head = tail = NULL;
            tail->next = head;
        }
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = head;
    }
};

int main()
{
    LinkedList l1;
    l1.insertatfist(10);
    l1.insertatfist(20);
    l1.insertatfist(30);
    l1.insertatfist(40);
    l1.insertatfist(50);
    l1.insertatfist(60);
    l1.display();
    cout << endl;
    l1.deleteatfront();
    l1.display();
    cout << endl;
    l1.deleteatEnd();
    l1.display();
}