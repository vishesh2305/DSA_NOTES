#include <iostream>
#include <string>
using namespace std;

int main(){
    string a = "masai";
    int len = a.length();

    for(int i=0; i<len; i++){
        string newstr = "";
        for(int j=i; j<len; j++){
            newstr += a[j];
            // for(auto x:newstr){
            //     cout << x << " ";
            // }
            cout << newstr;
            cout << endl;
        }
    }

}