#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int arr[] = {10,20,30,40,2,5,7,9,8,7,0,9,2,5,2,2,5,5};
    int length = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int,int>> vec;

    for(int i=0; i<length; i++){
        vec.push_back({arr[i], i});
    };

    for(auto i:vec){
        cout << "Value : " <<i.first<<"at the index "<<i.second<< endl;
    }

    // pair<int, string> p = {1,"Hello"};
    // cout << p.first<<endl;
    // cout << p.second<<endl;

    return 0;
}