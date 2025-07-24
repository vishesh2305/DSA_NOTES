#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int arr[] =  {10,20,30,40,2,5,7,9,8,7,0,9,2,5,2,2,5,5};

    int length = sizeof(arr)/sizeof(arr[0]);

    set<int> s;
    for(int i=0; i <length; i++){
        s.insert(arr[i]);
    };

    int value = 5;

    if(s.find(value) != s.end()){
        cout << "Element present";
    }
    else{
        cout << "Element does not exist";
    }

    for(int i:s){
        cout << i<<" ";
    }

    return 0;
}