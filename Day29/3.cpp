#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;



bool isleftbracket(char ch){
    return (ch =='(' || ch == '{' || ch =='<' || ch == '[');
}

bool checkexp(string s){
    stack<char> chars;

    unordered_map<char, char> brackets = {
        {')', '('},
        {'>', '<'},
        {'}', '{'},
        {']', '['}
    };

    for (char c: s){
        if(isleftbracket(c)){
            chars.push(c);
        }else if(brackets.find(c) != brackets.end()){
            if(chars.empty() || chars.top() != brackets[c]){
                return false;
            }
            chars.pop();
        }
    }
    return chars.empty();
    
}


int main(){
        cout << "Is Balanced : "
         << (checkexp("(2+3){30832}<130>[13030]") ? "Balanced" : "Not Balanced") << endl;

    cout << "Is Balanced : "
         << (checkexp("<(1+2)}+ (3))") ? "Balanced" : "Not Balanced") << endl;
}