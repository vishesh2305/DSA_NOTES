#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){



    vector<int> arr = {2,3,4,5,6,1,2,3};

    int length = 4;

    unordered_map<int,int> m;

    for(int i=0; i<arr.size();i++){

        m[arr[i]]++;

        // if(m.find(arr[i]) != m.end()){
        //     m[arr[i]] = m[arr[i]] + 1;
        // }else{
        //     m[arr[i]] = 1;
        // }
    }

    for(int i=length; i<arr.size(); i++){
        m[arr[i-length]]--;
        if(m[arr[i-length]] == 0){
            m.erase(arr[i-length]);
        }
        m[arr[i]]++;

        cout << m.size()<< " ";

    }
}