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


class LinkedListStack{
    private:
    Node* top;
    int size;

    public:
    LinkedListStack(){
        top = NULL;
        size =0;
    }


    bool isempty(){
        return size==0;
    }



    void push(int item){
        Node* newnode = new Node(item);
        newnode->next = top;
        top = newnode;
        size++;
    }



    void pop(){
        if(isempty()){
            cout << "Empty\n";
            return;
        }else{
            Node* curr = top;
            cout << "Popped item: {"<<curr->data<<"}"<<endl;
            top = top->next;
            delete curr;
        }
        size--;
    }


    void peek(){
        if(isempty()){
            cout << "Empty\n";
            return;
        }
        cout << top->data<<endl;
    }



    void display(){
        if(top == NULL){
            cout << "Empty\n";
        }
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int getsize(){
        return size;
    }





};



int main(){
    LinkedListStack l1;

    l1.push(10);
    l1.push(20);
    l1.push(30);
    l1.push(40);

    l1.display();

    while(!l1.isempty()){
        l1.pop();
    }



}