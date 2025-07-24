#include <iostream>
using namespace std;


int main(){

    int arr[10] = {10,20,30,40,50};

    int capacity = 10;
    int length = 5;
    cout << "Enter the index number and the value";
    int index, value;
    cin >> index >> value;


    for(int i=index; i<10; i++){

        int temp = arr[i];
        arr[i] = value;
        value = temp;
    };

    for(int i=0; i<size(arr); i++){
        cout << arr[i]<<" ";
    }




    return 0;
}