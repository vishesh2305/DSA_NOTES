// jospehues
#include <iostream>


using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* getLLNodes(int num){
    if(num<=0){
        return NULL;
    }
    Node* head=new Node(1);
    Node* tail=head;
    for(int i=2;i<=num;i++){
        tail->next=new Node(i);
        tail=tail->next;
    }
    tail->next=head;
    return head;
}

int main(){
    Node* head=getLLNodes(10);
    Node* curr=head;
    do{
        cout<<curr->data<<" -> ";
        curr=curr->next;

    }while(curr!=head);
    cout<<"NULL";

}