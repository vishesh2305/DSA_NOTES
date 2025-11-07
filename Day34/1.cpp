#include <iostream>
#include <queue>
#define MAX 10
using namespace std;



class Element{
    public:
    int item;
    int priority;
};


class ArrayPriorityQueue{
    private:
    Element arr[MAX];
    int size;
    public:
    ArrayPriorityQueue(){
        size =0;
    };

    bool isEmpty(){
        return size==0;
    };

    bool isFull(){
        return size>=MAX;
    };

    void enqueue(int item, int priority){
        
        if(isFull()){
            cout << "Already Full\n";
            return;
        }else{

        arr[size].priority = priority;
        arr[size].item = item;
        size++;
        };
    }



    void dequeue(){
        if(isEmpty()){
            cout << "Already Empty\n";
            return;
        }else{
            int maxprior =arr[0].priority;
            int index=0;
            for(int i=1; i<size; i++){
                if(arr[i].priority > maxprior){
                    maxprior = arr[i].priority;
                    index = i;
                };
            };

            
            while(index<size){
                arr[index] = arr[index+1];
                index++;
            }
            size--;
        }
    }

    void display(){
        for(int i=0; i<size; i++){
            cout << arr[i].item<<" ";
        }
        cout << endl;
    }



};


int main(){

    ArrayPriorityQueue a1;

    a1.enqueue(10, 50);
    a1.enqueue(20, 40);
    a1.enqueue(30, 30);
    a1.enqueue(40, 20);
    a1.enqueue(50, 10);

    a1.display();

    a1.dequeue();
    a1.display();

}