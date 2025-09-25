#include <iostream>
#define MAX 10
#include <queue>
using namespace std;


int main(){
    queue<int> q;

    q.push(10); 
    q.push(20); 
    q.push(30); 
    q.push(40); 
    q.push(50);
    cout << "Size is : "<< q.size()<<endl;
    cout << q.front()<<endl;
    cout << q.back() << endl;
    q.pop();
    cout << "Size is : "<< q.size()<<endl;
    cout << q.front()<<endl;
    cout << q.back() << endl;
}