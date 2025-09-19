// doubly circular
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Node{
public:
	int data;
	Node* next;
    Node* prev;
	Node(int data){
		this->data = data;
		this->next = NULL;
        this->prev=NULL;
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
            tail->prev=head;
        }
        else{
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
            head->prev=tail;
            tail->next=head;
        }
        size++;
    }
    void insertAtend(int value){
        Node* newnode=new Node(value);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
            tail->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            tail->next=head;
            head->prev=tail;
        }
        size++;
    }
    void displayforward(){
        if(head==NULL){
            cout<<"cdll khalli hai thengaaaa!!!!"<<endl;
            return ;
        }
        Node* curr=head;
        cout<<"(point to tail) ";
        do{
            cout<<curr->data<<" <-> ";
            curr=curr->next;

        }while(curr!=head);
        cout<<"(point to head)";

    }
    void displaybackward(){
        if(head==NULL){
            cout<<"cdll khalli hai thengaaaa!!!!"<<endl;
            return ;
        }
        Node* curr=tail;
        cout<<"(point to tail) ";
        do{
            cout<<curr->data<<" <-> ";
            curr=curr->prev;

        }while(curr!=tail);
        cout<<"(point to head)";

    }
    void deleteAtfront(){
        if(head==NULL){
            return ;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            head=head->next;
            delete temp;
            tail->next=head;
            head->prev=tail;
        }
        size--;
    }
    void deleteAtend(){
        if(head==NULL){
            return ;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=tail;
            tail=tail->prev;
            delete temp;
            tail->next=head;
            head->prev=tail;
        }
        size--;
    }
};
int main(){
    CLL d1;
    d1.insertAtFront(50);
    d1.insertAtFront(40);
    d1.insertAtFront(30);
    d1.insertAtFront(20);
    d1.insertAtFront(10);

    d1.displayforward();
    cout<<endl;
    d1.deleteAtfront();
    d1.displayforward();
    cout<<endl;
    d1.deleteAtend();
    d1.displayforward();
    // d1.displaybackward();
    return 0;


}