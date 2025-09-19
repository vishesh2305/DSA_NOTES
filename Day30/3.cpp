#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precendence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

string infixtopostfix(string exp)
{
    stack<char> st;
    string result = "";

    for (auto ch : exp)
    {
        if (isalnum(ch))
        {
            result += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            };
        }
        else
        {
            while (!st.empty() &&( precendence(st.top()) > precendence(ch) || precendence(st.top()) == precendence(ch) && ch != '^'))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}


string infixtoprefix(string exp){
    reverse(exp.begin(), exp.end());
    for(auto &ch:exp){
        if(ch == ')'){
            ch = '(';
        }else if(ch == '('){
            ch = ')';
        }
    };
    string a = infixtopostfix(exp);
    reverse(a.begin(), a.end());
    return a;
}

int applyOp(int a, int b, char op) {
switch(op) {
case '+': return a + b;
case '-': return a - b;
case '*': return a * b;
case '/': return a / b; // assume b # 0
case '%': return a % b;
case '^': return pow(a, b);

return 0;
}
};



int evaluatePostfix(string exp){
    stack<int> st;
    for(auto ch: exp){
        int sum =0;
        if(isdigit(ch)){
            st.push(ch-'0');
            sum += ch;
        }

        else{
            int val1= st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            int result = applyOp(val2,val1, ch);
            st.push(result);
        }

    }
    return st.top();
}
int main()
{
    string str = "A^(B^C)";
    cout << infixtopostfix(str)<<endl;
    cout << infixtoprefix(str)<<endl;
    return 0;
}