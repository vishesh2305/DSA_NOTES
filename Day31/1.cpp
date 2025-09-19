#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int applyOp(int a, int b, string op)
{
   if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    if (op == "%") return a % b;
    if (op == "^") return pow(a, b);
    return 0;
}

int evaluatepostfix(vector<string> exp)
{
    stack<int> t;
    for (auto ch : exp)
    {
        if (isdigit(ch[0]) || (ch.size() > 1 && isdigit(ch[1])))
        {
            t.push(stoi(ch));
        }
        else
        {
            int val2 = t.top();
            t.pop();
            int val1 = t.top();
            t.pop();

            int result = applyOp(val1, val2, ch);
            t.push(result);
        }
    }
    return t.top();
}
int main()
{
    vector<string> exp = {"23","1","*","9","+","5","-"};
    int a=evaluatepostfix(exp);
    cout << "Postfix Evaluation Result: " << a << endl;
    return 0;
}