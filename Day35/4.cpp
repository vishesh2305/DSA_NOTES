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


class StackusingQueue{
    private:
    queue<int> q1, q2;
    public:

    void enqueue(int value){
        q2.push(value);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        };

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void dequeue(){
        q1.pop();
    };

    int peekfront(){
        return q1.front();
    };

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