#include <iostream>
#include <vector>
#define MAX 10
using namespace std;



class CircularQueue{
    int front , rear,size;
    int* arr;
    public:
    CircularQueue(){
        size =0;
        front =0;
        arr = new int[MAX];
        rear = -1;
    }

    bool isempty(){
        return size==0;
    };

    bool isfull(){
        return size==MAX;
    };

    void enqueue(int element){
        if(isfull()){
            cout << "queue is full"<<endl;
            return;
        }
        else{
            rear= (rear+1) % MAX;
            arr[rear] = element;
            size++;
        }
    }

    void dequeue(){
        if(isempty()){
            cout << "Queue is empty"<<endl;
            return;
        }
        int value = arr[front];
        front = (front +1)%MAX;
        size--;
    }

    void display(){
        if(isempty()){
            cout << "Queue is empty"<< endl;
            return;
        }

        for(int i=0; i<size; i++){
            int index = (front+i)% MAX;
            cout << arr[index]<< " ";
        }
        cout << endl;
    }




};


int main(){
    CircularQueue c1;
    c1.enqueue(10);
    c1.enqueue(20);
    c1.enqueue(30);
    c1.enqueue(40);
    c1.enqueue(50);
    c1.display();
    c1.dequeue();
    c1.display();

    return 0;
}