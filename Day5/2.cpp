#include <iostream>
using namespace std;


int main(){

    int arr[5] = {10,20,30,40,50};
    int capacity = 5;
    int length = 5;

    int index = 2;
    // cout << "Enter the index to delete ";
    // cin >> index;

    for(int i=index; i<length; i++){
        arr[i] = arr[i+1];
    };

    length--;
    for(int i=0;i<length; i++){
        cout << arr[i] << " ";
    }

    return 0;

}