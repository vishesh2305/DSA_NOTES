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

    ~LinkedList()
    {
        Node *currentNode = head;

        while (currentNode != NULL)
        {
            Node *nextNode = currentNode->next;

            delete currentNode;

            currentNode = nextNode;
        }
        head = NULL;
    }

    // Inserting at beginning
    void insertAtBeginning(int value)
    {

        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // traverse each node and Print each node value
    void display()
    {

        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL";
    }

    // Inserting at the end
    void insertAtLast(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    int getsize()
    {
        cout << size << endl;
        return size;
    }

    // Getting the index of an element
    int indexOf(int value)
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return counter;
            }
            temp = temp->next;
            counter++;
        }
        return -1;
    }

    // Checking any value is there or not ?
    bool contains(int value)
    {
        // Node* temp = head;
        // while(temp != NULL){
        //     if(temp->data == value){
        //         return true;
        //         break;
        //     }
        //     temp = temp->next;

        // }
        // return false;

        return indexOf(value) != -1;
    }

    int getValueatIndex(int index)
    {
        Node *temp = head;
    //     for (int i = 0; i < index; i++)
    //     {
    //         if (temp == NULL)
    //         {
    //             cout << "Invalid Index\n";
    //             break;
    //         }
    //         else
    //         {
    //             temp = temp->next;
    //             if (i == index - 1)
    //             {
    //                 cout << "Element at index is : " << temp->data << endl;
    //             }
    //         }
    //     }
    // }

    if(index < 0 || index > size-1){
        cout << "Invalid Index\n";
        return -1;
    }

    for(int i=0; i<index; i++){
        temp = temp->next;
    }

    return temp->data;

}



void removeFirst(){
    if(head == NULL){
        cout << "Empty Linked List\n";
    }
    if(head == tail){
        delete head;
        head = tail = NULL;
    }
    else{
        Node* temp = head;
        head = temp->next;
        delete temp;
    };





}

};
int main()
{
    LinkedList ll;
    ll.insertAtBeginning(50);
    ll.insertAtBeginning(60);
    ll.insertAtBeginning(70);
    ll.insertAtBeginning(40);
    ll.insertAtBeginning(30);
    ll.insertAtBeginning(20);
    cout <<ll.getValueatIndex(2)<<endl;
    ll.insertAtLast(80);
    ll.removeFirst();
    cout << ll.indexOf(40) << " is the index" << endl;
    cout << ll.contains(400) << endl;
    ll.getsize();
    ll.display();
};