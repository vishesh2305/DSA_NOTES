#include <iostream>
using namespace std;



class Node{
    public:
    int data;
    int priority;
    Node* next;
    public:
    Node(int data, int priority){
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    };
};


class ProrityQueueLinkedList{
    Node* front;
    Node* rear;
    int size;
    public:
    ProrityQueueLinkedList(){
        front = rear = NULL;
        size =0;
    };

    bool isEmpty(){
        return size==0;
    };

    
    void enqueue(int val, int prior){

            Node* current = new Node(val, prior);

            if(isEmpty()){
                front = current;
            }
            else if(prior > front->priority){
                current->next = front;
                front = current;
            }
            else{
                Node* temp = front;
                while(temp->next != NULL &&  temp->next->priority >= prior){
                        temp = temp->next;
                    };
                    current->next = temp->next;
                    temp->next = current;
            }
            size++;
            

    }


    void display(){
        Node* current = front;
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};


int main(){
    ProrityQueueLinkedList pq;
    pq.enqueue(10, 50);
    pq.enqueue(20, 40);
    pq.enqueue(30, 30);
    pq.enqueue(40, 20);
    pq.enqueue(50, 10);

    pq.display();
}