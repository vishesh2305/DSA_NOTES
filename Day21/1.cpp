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
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtBegining(int value)
    {
        Node *newnode = new Node(value);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        size++;
    };


    void createCycle(){
        Node* temp = head;

        while(temp->next != NULL){
                temp = temp->next;
        }
        temp ->next = head;
        }

    bool DetectCycle(){
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast-> next -> next;
            slow = slow->next;
            if(fast == slow ){
                return true;
            }
        }

        return false;
    }


    Node* DetectCycleStarts(){
        Node* fast = head;
        Node* slow = head;

        while(fast != NULL && fast-> next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow=head;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }



    int getCycleStartNodeValue(){
        Node* startCycleNode= DetectCycleStarts();

        return startCycleNode -> data;
    }


    void breakCycle(){
        Node* StartingNode= DetectCycleStarts();
        Node* temp = StartingNode;
        while(temp->next != StartingNode){
            temp= temp->next;
        }
        temp->next = NULL;
    }




    void display()
    {
        if (head == NULL)
        {
            cout << "Invalid Index\n";
        }
        else
        {
            Node *current = head;

            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
    }
};

int main()
{


    LinkedList l1;
    l1.insertAtBegining(10);
    l1.insertAtBegining(20);
    l1.insertAtBegining(30);
    l1.insertAtBegining(24);
    l1.insertAtBegining(65);
    l1.insertAtBegining(24);
    l1.insertAtBegining(25);
    // l1.createCycle();
    cout << l1.DetectCycle();
}