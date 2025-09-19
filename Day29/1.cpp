#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkexp(string expression)
{
    stack<char> chars;
    for (auto ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<')
        {
            chars.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}' || ch == '>')
        {
            if (chars.empty())
            {
                return false;
            }
            char top = chars.top();

            if (ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '>' && top != '<' || ch == '}' && top != '{')
            {
                return false;
            }

            chars.pop();
        }
    }
    return chars.empty();
}
int main()
{
    cout << "Is Balanced : "
         << (checkexp("(2+3){30832}<130>[13030]") ? "Balanced" : "Not Balanced") << endl;

    cout << "Is Balanced : "
         << (checkexp("<(1+2)}+ (3))") ? "Balanced" : "Not Balanced") << endl;
}