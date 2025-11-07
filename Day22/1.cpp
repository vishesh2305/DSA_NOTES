#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data =data;
        this->next=NULL;
        this-> prev=NULL;
    }
};


class DoubleLinkedList{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    DoubleLinkedList(){
        head = tail=NULL;
        size=0;
    }

    ~DoubleLinkedList(){
        while(head != NULL){
            deleteatFront();
        };
    }

    void insertAtFront(int value){
        Node* newnode= new Node(value);
        if(head == NULL){
            head=tail=newnode;
        }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    };


    void displayForward(){

        if(head == NULL) return;
        
        Node* current = head;


        while(current != NULL){
            cout << current -> data <<" ";
            current = current -> next;
        }
        cout << endl;
    };


    void displayBackward(){
        if(tail==NULL) return;

        Node* current = tail;
        while(current != NULL){
            cout << current->data << " ";
            current = current -> prev;
        }
                cout << endl;

    };



    void deleteatFront(){
        if(head == NULL) return;

        Node* current = head;

        if(head == tail){
            head=tail=NULL;
        }
        else{
            head=head->next;
            head->prev = NULL;
        }
        delete current;
        size--;
    }



    void insertAtEnd(int value){
        Node* newnode= new Node(value);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev=tail;
            tail= newnode;
        }
        size++;
    }


    void deleteAtEnd(){
        if(head==NULL) return;

        if(head== tail){
            head=tail=NULL;
        }else{

        tail = tail->prev;
        tail->next = NULL;
    }
    size--;
    }





    int getValueatIndex(int index){
        if(head==NULL) return -1;

        if(index < 0 || index >= size){
            cout << "out of Bound\n";
            return -1;
        }else{
            Node* temp;
            int mid = size/2;
            if(index > mid){
                temp = tail;
                for(int i=size-1; i>index; i--){
                    temp = temp->prev;
                }
            }else{
                temp =head;
                for(int i=0; i<index; i++){
                    temp = temp->next;
                }
            }
            return temp->data;
        }
    }



    void insertAtPosition(int index, int value){
        if(index < 0 || index > size){
            cout << "Out of Bound\n";
        }
        else if(index == 0){
            insertAtFront(value);
        }else if(index == size){
            insertAtEnd(value);
        }else{
            Node* newnode = new Node(value);
            Node* current = head;
            for(int i=0; i<index; i++){
                current = current ->next;
            }
            Node* previous = current->prev;
            previous->next= newnode;
            newnode->prev = previous;
            newnode->next = current;
            current->prev = newnode;

            size++;
        }
        
    }




    void deleteAtPosition(int index){
        if(index ==0){
            deleteatFront();
        }else if(index == size-1){
            deleteAtEnd();
        }else{
            Node* current = head;


            for(int i=0; i<index;i++){
                current = current->next;
            }
            Node* previous = current->prev;
            Node* next = current ->next;


            previous->next = next;
            next->prev = previous;
            delete current;
        }

    }

void reverseDLL() {
    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev; 
    }
}



};

int main(){
    DoubleLinkedList dl;
    dl.insertAtFront(10);
    dl.insertAtFront(30);
    dl.insertAtFront(20);
    dl.insertAtFront(50);
    dl.insertAtFront(40);
    dl.insertAtFront(60);

    dl.insertAtPosition(2,69);
    dl.displayForward();


    dl.deleteAtPosition(3);

    dl.displayForward();
    // dl.displayBackward();

    dl.reverseDLL();

    dl.displayForward();




    // cout << dl.getValueatIndex(2);




    return 0;



};