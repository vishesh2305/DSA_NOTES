#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(){
        int arr[] =  {10,20,30,40,2,5,7,9,8,7,0,9,2,5,2,2,5,5};

    int length = sizeof(arr)/sizeof(arr[0]);

    unordered_set<int> s;

    for(int i=0; i<length; i++){
        s.insert(arr[i]);
    }

    for(int i:s){
        cout << i<<" ";
    };

}