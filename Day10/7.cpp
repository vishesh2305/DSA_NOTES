#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s){
    int slen = s.length();

    string newstr = "";

    for(int i=slen - 1; i >=0; i--){
        newstr+= s[i];
    };
    if(s == newstr){
        return true;
    }else{
        return false;
    }

}

int main(){

    string s = "thisracecarisgood";

    int len = s.length();


    int result=0;
    for(int i=0; i<len; i++){
        string temp="";
        for(int j=i ; j<len; j++){
            temp += s[j];

            if(isPalindrome(temp)){
                int length = temp.size();
                if(length > result){
                    result = length;
                }
            }
        };
    }
    cout << result;

}