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
        q1.push(value);
    }

    void dequeue(){

        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        };
        q2.pop();
        swap(q1,q2);

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