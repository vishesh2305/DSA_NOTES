#include <iostream>
#include <string>
using namespace std;


int main(){
 
    string s = "abcde";

    int index = 2;

    int count = s.size() - index;
    cout << "Number of substring starting with index "<< index << " is "<< count << endl;

    for(int i=index;i<s.size(); i++){
        cout << s.substr(index, i - index + 1)<< endl;
    }
    
}