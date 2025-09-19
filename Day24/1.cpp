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

    void insertatindex(int index, int value)
    {
        if (index >= size || index < 0)
            cout << "Invalid index";
        return;

        Node *current = head;

        Node *newnode = new Node(value);

        int i = 0;
        while (i < index - 1)
        {
            current = current->next;
            i++;
        }
        newnode->next = current->next;
        current->next = newnode;

        size++;
    }

    void deleteatindex(int index)
    {
        if (index >= size || index < 0)
        {
            cout << "Invalid index";
            return;
        }

        else if (index == 0)
        {
            deleteatfront();
        }
        else if (index == size - 1)
            deleteatEnd();
        else
        {
            Node *current = head;
            int i = 0;
            while (i < index - 1)
            {
                current = current->next;
                i++;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
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
    // l1.deleteatfront();
    // l1.display();
    // cout << endl;
    // l1.deleteatEnd();
    // l1.display();
    // cout << endl;
    l1.deleteatindex(2);
    l1.display();
}