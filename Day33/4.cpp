#include <iostream>
#define MAX 10
using namespace std;

class linearQueuee
{
    int front, rear, size;
    int *arr;

public:
    linearQueuee()
    {
        size = 0;   
        arr = new int[MAX];
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX;
    }

    void insertFront(int element)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        front=(front-1+MAX)%MAX;
        arr[front] = element;
        size++;
    }
    void insertRear(int element)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        rear=(rear+1)%MAX;
        arr[rear] = element;
        size++;
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty|n";
            return -1;
        }
        int deqitem = arr[front];
        cout << "Removed: " << deqitem << endl;
        front=(front+1)%MAX;
        size--;
        return deqitem;
    }
    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty|n";
            return -1;
        }
        int deqitem = arr[rear];
        cout << "Removed: " << deqitem << endl;
        rear=(rear-1+MAX)%MAX;
        size--;
        return deqitem;
    }

    int getsize()
    {
        return size;
    }

    // getting the front item
    int peekFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty \n";
            return -1;
        }
        return arr[front];
    }
    // getting the rear item
    int peekRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty \n";
            return -1;
        }
        return arr[rear];
    }

    void display()
    {
        // for (int i = front; i <= rear; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        for (int i = 0; i < size; i++)
        {
            int index=(front+i)%MAX;
            cout << arr[index] << " ";
        }
    }
};

int main()
{
    linearQueuee q1;
    q1.insertFront(35);

    q1.display();

}