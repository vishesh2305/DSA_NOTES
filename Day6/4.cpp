#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int arr[] = {10,20,30,20,10,0,2,0,5,8};

    int length = sizeof(arr)/sizeof(arr[0]);

    int start =0;
    int end = length - 1;

    while(start < end){
        if(arr[start] == 0){
            start++;
        }else if(arr[end] != 0){
            end--;
        }else{
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    };
    
    for(int i:arr){
        cout << i << " ";
    };



    return 0;
}