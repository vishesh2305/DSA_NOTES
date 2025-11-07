#include<iostream>
#include<algorithm>
#include<vector>
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

class CLL{
private:
	   Node* head;
   	   Node* tail;
  	   int size;
public:
	CLL(){
		head = NULL;
       	tail = NULL;
        size = 0;
	}
    void insertAtFront(int value){
        Node* newnode=new Node(value);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
        }
        else{
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
        size++;
        
    }
    void insertAtEnd(int value){
        Node* newnode=new Node(value);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
        size++;
    }

     void display(){
        if(head==NULL){
            cout<<"CLL khali hai ";
        }
        Node* temp=head;
        // cout<<temp->data<<" -> ";
        do{
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }while(temp!=head);
            cout<<"(back to head)"<<endl;
        
    }
    void displayy(){
        Node* current=head;
        while(true){
            cout<<current->data<<" -> ";
            current=current->next;
            if(current==head){
                break;
            }
        }
        cout<<"(back to head)"<<endl;
    }


    void deleteAtFront(){
        if(head==NULL){
            cout<<"cll khali hai";
            return ;
        }
        if(head->next==head){
            delete head;
            return ;
        }
        else{
        Node* temp=head;
        head=head->next;
        tail->next=head;
        delete temp;
        }
        size--;
    }
    

    void deleteAtEnd(){
        Node* temp=tail;
        Node* curr=head;
        while(curr->next !=tail){
            curr=curr->next;
        }
        if(head==NULL){
                cout<<"cll khali hai";
                return ;
        }
        if(head->next==head){
            delete head;
            return ;
        }
        else{
            curr->next = head;
            delete tail;
            tail = curr;
        }
        size--;
    }


void deleteAtPostion(int index) {
    if (head == NULL) {
        cout << "CLL khali hai";
        return;
    }

    if (index < 0 || index >= size) {  // fixed condition
        return;
    }

    if (index == 0) {
        deleteAtFront();
        return;
    }

    if (index == size - 1) {
        deleteAtEnd();
        return;
    }

    Node* curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = temp->next; 
    delete temp;

    size--;
}



// JOSPHEUS PROBLEM














};
int main(){
    CLL l1;
    l1.insertAtFront(1);
    l1.insertAtFront(2);
    l1.insertAtFront(3);
    l1.displayy();
    l1.deleteAtPostion(1);
    l1.display();
    // cout<<endl;
    // l1.deleteAtFront();
    // l1.display();
    // cout<<endl;
    // l1.deleteAtEnd();
    // l1.display();

}