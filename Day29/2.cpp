#include <iostream>
#include <string>
#include <stack>
using namespace std;



bool isleftbracket(char ch){
    return (ch =='(' || ch == '{' || ch =='<' || ch == '[');
}



bool isrightbracket(char ch){
    return (ch ==')' || ch == '}' || ch =='>' || ch == ']');
}


bool isBalanced(char left, char right){
    if(left == '(' && right == ')') return true;
    else if(left == '{' && right == '}') return true;
    else if(left == '[' && right == ']') return true;
    else if(left == '<' && right == '>') return true;
    return false;
}

bool checkexp(string expression){
    stack<char> chars;

    for(auto ch : expression){

        if(isleftbracket(ch)){
            chars.push(ch);
        }else if(isrightbracket(ch)){
            if(chars.empty()) return false;

            char top = chars.top();
            if(!isBalanced(top, ch)) return false;

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