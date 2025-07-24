#include <iostream>
using namespace std;

int main(){

    int arr[10] = {10,20,30,40,50};
    int capacity = 10;
    int length = 5;
    int index=1;
    int value = 15;

    for(int i=length; i > index; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = value;
    length++;

    for(int i=0; i<length; i++){
        cout <<arr[i] << " ";
    }

    return 0;
}