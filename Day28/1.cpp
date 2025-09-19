#include <iostream>
#define Max 10
using namespace std;



class StackArray{

    private:
    int items[Max];
    int top;
public:
StackArray(){
    top = -1;
}

bool isEmpty(){
    return top==-1;
}

bool isFull(){
    return top == Max-1;
}

void push(int item){
    if(isFull()){
        cout << "Stack Overflow";
        return;
    }
    items[++top] = item;
};

int pop(){
    if(isEmpty()){
        cout << "Empty";
        return -1;
    }
    return items[top--];
}

int peek(){
    if(top == -1){
        cout << "empty";
        return -1;
    }
    return items[top];
}


void display(){
    if(isEmpty()){
        cout << "Empty";
        return;
    }
    for(int i=top; i>=0; i--){
        cout << items[i] << " ";
    }
    cout << endl;
};

};


int main(){


    StackArray a1;
    a1.push(10);
    a1.push(20);
    a1.push(30);
    a1.push(40);
    a1.push(50);
    a1.push(60);

    a1.display();

    a1.pop();

    a1.display();

    a1.peek();

    a1.display();

    a1.push(100);

    a1.display();


};