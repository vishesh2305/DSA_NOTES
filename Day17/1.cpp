#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
   

    ~LinkedList(){
        Node* currentNode = head;
        while(currentNode != NULL){
            Node* nextNode = currentNode-> next;
            delete currentNode;
            currentNode = nextNode;
        }
        head = NULL;
    }
    
    void insertAtBeginning(int value){
        Node* newNode= new Node(value);
        
        if(head == NULL){
            head = newNode;
        }else{
            newNode-> next = head;
            head = newNode;
        }
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout << endl;
    }


    void insertAtLast(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = newNode;
        }else{
            Node* currentNode =head;
            while(currentNode-> next != NULL){
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    // all remaining functionalities will go under this public
    
};
int main(){
    LinkedList l1;
    l1.insertAtBeginning(50);
    l1.insertAtBeginning(40);
    l1.insertAtBeginning(30);
    l1.insertAtBeginning(20);
    l1.insertAtBeginning(10);
    l1.insertAtLast(80);
    l1.display();
}