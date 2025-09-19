#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

class StackArray
{
private:
    vector<int> items;
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
    bool ifFull()
    {
        return top == MAX - 1;
    }

    void push(int item)
    {
        if (top == -1)
        {
            cout << "Empty Stack \n";
            return;
        }
        items.push_back(item);
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Overflow\n";
            return -1;
        }
        int topitem = items.back();
        items.pop_back();
        return topitem;
    }

    void display()
    {
        if (items.empty())
        {
            cout << "Stack is empty !\n";
            return;
        };
        for (int i = items.size() - 1; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    StackArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    s1.display();

    s1.pop();

    s1.display();

    return 0;
};