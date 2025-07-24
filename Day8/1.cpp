#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int arr[] = {10,20,30,20,30,50};

    int length = sizeof(arr)/sizeof(arr[0]);
    
    unordered_map<int, int> m;

    // for(int i=0; i<length; i++){
    //     int value = arr[i];

    //     if(m.find(value) != m.end()){
    //         m[value] = m[value] + 1;
    //     }else{
    //         m[value] = 1;
    //     }
    // }


    for(int i=0; i<length; i++){
        m[arr[i]]++;
    }

    for(auto& p:m){
        cout << "Element: "<< p.first<< " Frequency: "<<p.second<<endl;
    }


    return 0;
}