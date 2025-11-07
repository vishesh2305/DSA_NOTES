#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


void reverseQueue(queue<int>& q){
    stack<int> result;

    while(!q.empty()){
        result.push(q.front());
        q.pop();
    };

    while(!result.empty()){
        cout << result.top()<< endl;
        result.pop();
    };

}


class QUsingStack{
    private:
    stack<int> s1, s2;
    public:
    bool isEmpty(){

    }

    int rear;
    void enqueue(int item){
        stack<int> s1;
        stack<int> s2;
        s1.push(item);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(item);
        rear = item;
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    

    void dequeue(){
        s1.pop();
    };

    void peekfront(){
        cout <<s1.top()<< endl;
    }

    void peekrear(){
        cout << rear<<endl;
    }





};


int main(){

    queue<int> q;
    q.push(10);
    q.push(40);
    q.push(20);
    q.push(60);
    q.push(30);
    q.push(50);


    reverseQueue(q);

};