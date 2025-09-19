#include <iostream>
#include <string>
#include <stack>
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
            while (!st.empty() && precendence(st.top()) >= precendence(ch))
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

int main()
{

    string str = "C*(B+A)";

    cout << infixtopostfix(str);
    return 0;
}