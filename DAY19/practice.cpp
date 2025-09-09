#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this ->next = NULL;
    };
};



class LinkedList{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList(){
        head=NULL;
        tail = NULL;
        size =0;
    }

    void insertatfirst(int value){
        Node* newnode = new Node(value);

        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode-> next = head;
            head = newnode;
        }
        size++;
    }


    void insertatLast(int value){
        Node* newnode= new Node(value);
        if(head == NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }



    int indexof(int value){
        int counter=0;
        Node* temp =head;
        while(temp != NULL){
            if(temp-> data == value){
                return counter;
            }
            temp = temp->next;
            counter++;
        }
        return -1;
    }


    int getValueatindex(int index){
        if(index < 0 || index > size){
            cout << "Invalid Index\n";
            return -1;
        }
        else{
            Node* temp =head;

            for(int i=0; i<index; i++){
                temp = temp->next;
            }
            return temp->data;
        }
    }



    void removefirst(){
        if(head == NULL){
            cout << "Linked List is empty\n";
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

    


    Node* getPreviousNode(Node* node){
        Node* current = head;

        while(current != NULL && current-> next != node){
            current = current->next;
        }

        return current;
    }


    void removelast(){
        if(head == NULL){
            cout << "Linked List is empty\n";
        }
        if(head== tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = getPreviousNode(tail);
            delete tail;
            tail = temp;
            tail->next = NULL;
            size--;
        }
    }



    void insertAtIndex(int value, int index){
        if(index =0 || index > size){
            cout <<"Invalid Index";
            return;
        }

        if(index =0){
            insertatfirst(value);
            return;
        }

        if(index = size-1){
            insertatLast(value);
            return;
        }

        Node* newnode= new Node(value);
        Node* current = head;
        for(int i=0; i<index-1; i++){
            current = current->next;
        }
        newnode -> next = current->next;
        current ->next = newnode;
        size++;
    }



    void deleteAt(int index){
        if(index < 0 || index > size){
            cout << "Invalid index\n";
            return;
        }
        Node* current = head;
        for(int i=0; i<index-1; i++){
            current = current ->next;
        }
        Node* temp = current ->next;
        current-> next = temp->next;
        delete temp;
        size--;
}




    void display(){
        if(head==NULL){
            cout << "Linked List is Empty";
            return;
        }
        else{
            Node* current = head;
            while(current != NULL){
                cout << current-> data<<" ";
                current = current->next;
            }
        }
    }

};




int main(){
    LinkedList list1;
    list1.insertatfirst(10);
    list1.insertatfirst(20);
    list1.insertatfirst(30);
    list1.insertatLast(40);



    list1.display();
    cout << endl;

    cout <<list1.indexof(10)<<endl;
    cout << list1.getValueatindex(3)<<endl;

    list1.removefirst();
    list1.removelast();

    list1.insertAtIndex(3, 1);

    list1.deleteAt(2);

    list1.display();

}