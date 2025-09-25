#include <iostream>
#include <vector>
#include <array>
#define MAX 10
using namespace std;
class LinearQueue{
    int front,rear,size;
    int *arr;

    public:
    LinearQueue(){
        size=0;
        arr=new int[MAX];
        front=0;
        rear=-1;
    }

    bool isempty(){
        return size==0;
    }

    bool isfull(){
        return size==MAX;
    }


    void enqueue(int element){
        if(isfull()){
            cout<<"queue is full"<<endl;
            return;
        }
        else{
        rear=(rear+1)%MAX;
        arr[rear]=element;
        size++;
        }
    }

    //similar to pop in stack instead it is removing from front 
    void dequeue(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        int val=arr[front];
        front=(front+1) % MAX;
        size--;
    }

    void display(){
        if(isempty()){
            cout << "queue is empty" << endl;
            return;
        }
        for(int i = 0; i < size; i++){
            int index = (front + i) % MAX;
            cout << arr[index] << " ";
        }
        cout << endl;
    }


};




int main(){ 
    LinearQueue l1;
    l1.enqueue(5);
    l1.enqueue(10);
    l1.enqueue(15);
    l1.enqueue(20);
    l1.dequeue();
    l1.display();
    l1.enqueue(21);
    l1.display();
    l1.dequeue();
    l1.display();


    return 0;
}