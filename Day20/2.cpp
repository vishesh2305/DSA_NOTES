#include <iostream>
#include <vector>
#include <algorithm>
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

    void insertSorted(int value)
    {

        Node *newnode = new Node(value);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else if (value <= head->data)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL && current->next->data < value)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
            if (newnode->next == NULL)
            {
                tail = newnode;
            }
        }
        size++;
    }

    void reverseList()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;

        tail = head;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    Node *findMiddle2()
    {
        if (head == NULL)
        {
            return NULL;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void findmid()
    {
        Node *temp = head;

        int mid = size / 2;

        for (int i = 0; i < mid; i++)
        {
            temp = temp->next;
            if (i == mid - 1)
            {
                cout << temp->data << " ";
                return;
            }
        }
    }




    bool isPalindrome(){

        if(head == NULL || head-> next == NULL){
            return true;
        }

        vector<int> arr;

        Node* temp= head;

        while(temp!=NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int i=0;
        int j = arr.size() - 1;

        while(i<j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
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
    l1.insertAtBegining(40);
    l1.insertAtBegining(50);
    l1.insertAtBegining(90);
    l1.insertAtBegining(90);

    l1.findmid();
    cout << endl;

    l1.display();
}