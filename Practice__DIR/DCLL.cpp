#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    };
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
    };

    void insertatFront(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
            tail->prev = head;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            tail->next = head;
            head->prev = tail;
        }
        size++;
    }

    void insertatEnd(int value)
    {
        Node *newnode = new Node(value);

        if (head == NULL)
        {
            head = tail = newnode;
            tail->prev = head;
            tail->next = head;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
            head->prev = tail;
        }
        size++;
    }

    void displayForward()
    {
        if (head == NULL)
        {
            cout << "CLL IS EMPTY (Thengaa)!" << endl;
            return;
        }
        else
        {
            Node *current = head;
            do
            {
                cout << current->data << "->";
                current = current->next;
            } while (current != head);

            cout << endl;
        }
    }

    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "CLL IS EMPTY (Thengaa)!" << endl;
            return;
        }else{
            Node* current = tail;
            do{
                cout << current->data << "->";
                current = current ->prev;
            }while(current != tail);
            cout << endl;
        }
    }


    void deleteatFront(){
        if(head == NULL){
            cout << "CLL Khali Hai "<<endl;
            return;
        }

        Node* temp = head;
        head = temp->next;
        delete temp;
        tail->next = head;
        head->prev = tail;
        size--;
    };

    void deleteatEnd(){
                if(head == NULL){
            cout << "CLL Khali Hai "<<endl;
            return;
        }


        Node* temp = tail;
        tail = temp->prev;
        delete temp;
        tail->next = head;
        head->prev = tail;
        size--;
    }


    void deleteatIndex(int index){
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

        else{
            Node* current = head;

            for(int i=0; i<index-1; i++){
                current = current->next;
            };

            Node* temp = current->next;

            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
        }
        size--;
    }


};