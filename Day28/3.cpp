#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkbalancedexp(string expression){
    stack<char> chars;

    for(char ch: expression){
        if(ch=='('){
            chars.push(ch);
        }else if(ch == ')'){
            if(chars.empty()){
                return false;
            }
            chars.pop();
        }
    }

    return chars.empty();
}
int main(){
    cout << "Is Balanced : "<< (checkbalancedexp("(1+2)+ 3") ? "Balanced" : "Not Balanced")<< endl;
    cout << "Is Balanced : "<< (checkbalancedexp("(1+2)+ (3))") ? "Balanced" : "Not Balanced")<< endl;
}