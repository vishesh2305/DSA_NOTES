#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};


class DoubleLL{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    DoubleLL(){
        head = tail = NULL;
        size=0;
    };

    ~DoubleLL(){
        while(head!=NULL){
            deleteatFront();
        }
    };


    void insertAtFront(int value){
        Node* newnode= new Node(value);
        if(head ==NULL){
            head = tail = newnode;
        }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }


    void deleteatFront(){
        if(head == NULL){
            cout <<"Linked List is Empty\n";
            return;
        }else if(head==tail){
            head=tail=NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
        size--;
    };

    void insertatEnd(int value){
        Node* newnode = new Node(value);

        if(head == NULL){
            head = tail = newnode;
        }else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            newnode->next = NULL;
        }
        size++;
    }

    void deleteAtEnd(){
        if(head == NULL){
            cout << "Empty Linked List\n";
            return;
        }else if(head == tail){
            head = tail = NULL;
        }else{
            tail = tail->prev;
            tail->next=NULL;
        }
        size--;
    }


    void getValueatIndex(int index){
        if(head == NULL){
            cout << "Empty Linked List\n";
            return;
        }else if(index >=size){
            cout << "Out of Index\n";
            return;
        }else{
            if(size/2 > index){
                Node* current = head;
                for(int i=0; i<index; i++){
                    current = current->next;
                };
                cout << current->data << endl;
            }
            else{
                int newidx = size-index;
                Node* current = tail;
                for(int i=size-1; i>=index; i--){
                    current=current->prev;
                }
                cout << current->data << endl;
            }
        }
    }


    void insertAtPosition(int value, int idx){
        if(idx > size-1){
            cout << "Invalid Index\n";
            return;
        }else if(idx ==0){
            insertAtFront(value);
        }else if(idx == size-1){
            insertatEnd(value);
        }
        else{
            Node* current = head;
            Node* newnode= new Node(value);
            for(int i=0; i<idx; i++){
                current= current->next;
            }
            Node* temp = current->next;
            current ->next->prev = newnode;
            current->next = newnode;
            newnode->prev = current;
            newnode->next = temp;
            size++;
        }
    }


    void deleteAtPosition(int idx){
        if(idx > size-1){
            cout << "Invalid Index\n";
            return;
        }else if(idx ==0){
            deleteatFront();
        }else if(idx == size-1){
            deleteAtEnd();
        }else {
            Node* current = head;
            for(int i=0; i<idx; i++){
                current = current->next;
            }
            Node* temp = current->next;

            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
        }
    }





};