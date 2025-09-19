#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10
using namespace std;

class StackArray
{
private:
    int items[MAX];
    int top;

public:
    StackArray()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX-1;
    }

    void push(int item)
    {
        if(isFull()){
            cout <<"Stack Overflow ! \n";
            return;
        }

        items[++top] = item;
    }


    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty !\n";
            return -1;
        };
        return items[top--];
    }



    // peek or top function
    int peek(){

        if(top==-1){
            cout << "Stack is empty !\n";
            return -1;
        }
        return items[top];

    }

    void display(){
        if(isEmpty()){
            cout << "Stack is Empty !\n";
            return;
        }

        for(int i=top; i>=0; i--){
            cout << items[i]<<" ";
        }

        cout << endl;

    }


    int getsize(){
        int count =0;
        for(int i=0; i<=top; i++){
            count+=1;
        }
        return count;
    }

};

int main() {

    StackArray s1;

    s1.push(50);
    s1.push(40);
    s1.push(30);
    s1.push(20);
    s1.push(10);
    s1.push(0);

    s1.display();

    cout << "Poped out one element from stack is : " << s1.pop()<< endl;
    cout << "Poped out one element from stack is : " << s1.pop()<< endl;
    cout << "Poped out one element from stack is : " << s1.pop()<< endl;
    cout << "Poped out one element from stack is : " << s1.pop()<< endl;

    s1.display();


    cout << "Number of elements in the stack is : "<< s1.getsize()<<endl;

    return 0;
};