#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};

    int length = sizeof(arr)/sizeof(arr[0]);

    int first = arr[0];

    for(int i=0; i<length; i++){
        arr[i] = arr[i+1];
    }
    arr[length - 1] = first;


    for(int i=0; i<length; i++){
        cout << arr[i] << ' ';
    }

return 0;
}