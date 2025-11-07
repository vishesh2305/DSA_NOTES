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