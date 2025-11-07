#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class CLL
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    CLL()
    {
        size = 0;
        head = tail = NULL;
    }

    void insertatFront(int value)
    {

        Node *newnode = new Node(value);

        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
        size++;
    }

    void insertatEnd(int value)
    {
        Node *newnode = new Node(value);

        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
        size++;
    };

    void display()
    {
        Node *current = head;
        while (true)
        {
            cout << current->data << "->";
            current = current->next;

            if (current == head)
            {
                break;
            }
        }
        cout << endl;
    }

    void deleteatFront()
    {
        if (head == NULL)
            return;

        if (head->next == head)
        {
            delete head;
            return;
        }
        else
        {

            Node *temp = head;
            head = temp->next;
            delete temp;
            tail->next = head;
        }
        size--;
    }

    void deleteatEnd()
    {
        if (head == NULL)
            return;

        if (head->next == head)
        {
            delete head;
            return;
        }
        else
        {

            Node *temp = tail;
            Node *curr = head;
            while (curr->next != tail)
            {
                curr = curr->next;
            }
            curr->next = head;
            tail = curr;
            delete temp;
        }
        size--;
    }

    void deleteatIndex(int index)
    {
        if (head == NULL)
            return;

        if (index < 0 || index > size - 1)
        {
            cout << "Invalid Index" << endl;
            return;
        };

        if (index == 0)
        {
            deleteatFront();
            return;
        }

        else if (index == size - 1)
        {
            deleteatEnd();
            return;
        }

        Node *curr = head;

        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        };

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
};

int main()
{
    CLL c1;
    c1.insertatEnd(10);
    c1.insertatEnd(20);
    c1.insertatEnd(30);
    c1.insertatEnd(40);
    c1.insertatEnd(50);
    c1.insertatEnd(60);

    c1.display();

    c1.deleteatFront();

    c1.display();
    c1.deleteatEnd();

    c1.display();


    c1.deleteatIndex(2);

    c1.display();
}