#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this-> data = data;
        this -> next = NULL;
    }
};

class LinkedList{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList(){
        head= NULL;
        tail = NULL;
        size =0;
    }


    void insertatFirst(int value){
        Node *newnode = new Node(value);
        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode->next= head;
            head = newnode;
        }
        size++;
    }


    void insertatLast(int value){

        Node* newNode = new Node(value);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next= newNode;
            tail = newNode;
        }

    }



    int indexof(int value){
        int counter=0;
        Node *temp = head;
        while(temp != NULL){
            if(temp->data==value){
                return counter;
            }
            temp = temp-> next;
            counter++;
        }
        return -1;
    }


    int getvalueatindex(int index){
        Node* temp =head;

        if(index <0 || index > size-1){
            cout << "Invalid index\n";
            return -1;
        }

        for(int i=0;i<index; i++){
            temp = temp->next;
        }

        return temp-> data;
    }


    void removefirst(){
        if(head == NULL){
            cout << "Linked List is Empty";
        }

        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = head;
            head = temp-> next;
            delete temp;
        }
        size--;
    }

    void removeLast(){
        if(head == NULL){
            cout << "Linked list is empty";
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = head;
            while(temp->next != tail){
                temp= temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            size--;
        }
    }



    void insertAt(int index, int value){
        if(index < 0 || index > size){
            cout << "Error, Invalid Index\n";
            return;
        }

        if(index ==0){
            insertatFirst(value);
            return;
        }

        if(index == size){
            insertatLast(value);
            return;
        }

        Node* newNode= new Node(value);
        Node* current=head;

        for(int i=0; i<index-1; i++){
            current = current-> next;
        }

        newNode -> next = current -> next;

        current->next = newNode;

        size++;

    }



    void deleteAt(int index){
        Node* current =head;
        for(int i=0; i<index-1;i++){
            current= current ->next;
        }
        Node* temp = current->next;
        current-> next = temp-> next;
        delete temp;

        size--;
    }

    void display(){
        if(head == NULL){
            cout << "Linked list is empty";
            return;
        }
        Node *current= head;
        while(current != NULL){
            cout << current-> data<<"->";
            current = current->next;
        }
    }
};


int main(){
    LinkedList l1;
    l1.insertatFirst(10);
    l1.insertatFirst(10);
    l1.insertatFirst(10);
    l1.insertatFirst(10);
    l1.insertatLast(20);
    l1.removeLast();
    l1.insertAt(2, 3);

    l1.display();
    cout << "\n";
    cout << l1.indexof(10);
    cout << l1.getvalueatindex(2);
}