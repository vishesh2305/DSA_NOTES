// Circular Linked List


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        size =0;
    }

    void insertatBeginning(int value){
        Node* newnode = new Node(value);

        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
        size++;
    }


    void insertAtEnd(int value){
        Node* newnode = new Node(value);
        
        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }else{
            tail->next = newnode;
            tail=newnode;
            tail->next = head;
        }
        size++;
    }

    void display(){
        Node* current = head;

        if(head == NULL) return;

        do{
            cout << current->data <<" ";
            current = current->next;
        }while (current != head);
    }
};