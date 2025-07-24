#include <iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,20,10,0,2,0,5,8};

    int length = sizeof(arr)/sizeof(arr[0]);

    int* copy = new int[length];

    int index=0;
    for(int i=0; i<length; i++){
        if(arr[i] == 0){
            copy[index] = arr[i];
            index++;
        }
    };
    for(int i=0; i<length; i++){
        if(arr[i] != 0){
            copy[index] = arr[i];
            index++;
        }
    };

    for(int i =0; i<length; i++){
        cout << copy[i]<<" ";
    }

    delete[] copy;

    return 0;
}