#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};

    int length = sizeof(arr)/sizeof(arr[0]);

    int last = arr[length -1];
    for(int i=length - 1; i>0; i--){
    arr[i] = arr[i-1];
    }
    arr[0] = last;

    for(int i:arr){
        cout << i << " ";
    }



    return 0;
};