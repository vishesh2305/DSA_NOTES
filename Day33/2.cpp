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

class Queue{
    Node* front;
    Node* rear;
    int size;
    public:
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    };


    bool isEmpty(){
        return size==0;
    }

    void enqueue(int value){
        Node* node = new Node(value);
        if(front == NULL){
            front = rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
        size++;
    }

    void dequeue(){
        Node* temp = front;

        if(front == NULL){
            cout << "Empty Queue"<<endl;
            return;
        }
        else{
            front = front->next;
            delete temp;
            size--;
        }

        if(front == NULL){
            rear = NULL;
            return;
        }
    }


    void display(){
        if(isEmpty()){
            cout << "Queue is empty"<< endl;
            return;
        }

        Node* current = front;
        
        for(int i=0; i<size;i++){
            cout << current->data<<" ";
            current = current->next;
        }
        cout << endl;

    }


    


};



int main(){
    Queue c1;
    c1.enqueue(10);
    c1.enqueue(20);
    c1.enqueue(30);
    c1.enqueue(40);
    c1.enqueue(50);
    c1.display();

    return 0;
}