#include <iostream>
#include <algorithm>
using namespace std;



class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

};



class LinkedList{
    private:
    Node* head;
    Node* tail;
    int size;


    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size=0;
    }


    void insertAtBegining(int value){
        Node* newnode = new Node(value);

        if(head == NULL){
            head = tail = newnode;
        }else{
        newnode-> next = head;
        head = newnode;
    }
    size++;
    };


    int* toArray(){
        int* arr = new int[size];
        Node* current = head;
        int i=0;
        while(current != NULL){
            arr[i++] = current-> data;
            current = current-> next;
        }
        return arr;
    }


    void sortLinkedList(){
        int* arr = toArray();
        int i=0;
        sort(arr, arr+size);
        Node* current = head;
        while(current != NULL){
            current -> data = arr[i++];
            current = current-> next;
        }
    }


    



    void display(){
        if(head == NULL){
            cout << "Invalid Index\n";
        }else{
            Node* current = head;

            while(current != NULL){
                cout << current -> data<< " ";
                current = current -> next;
            }
        }
    }


};


int main(){
LinkedList l1;
    l1.insertAtBegining(10);
    l1.insertAtBegining(30);
    l1.insertAtBegining(20);
    l1.insertAtBegining(70);
    l1.display();
    cout << endl;

    l1.sortLinkedList();

    l1.display();
}