#include <iostream>
using namespace std;

void insertAtIndex(int arr[], int &n, int index, int value, int capacity){

    if(n>=capacity){
        cout << "Array is full /"<<endl;
        return;
    }
    if(index > n || index < 0){
        cout << "Invalid Index. "<<endl;
    }

    for(int i=n; i>index; i--){
        arr[i] = arr[i-1];

    }
    arr[index] = value;
};

int main(){

    int n=10;
    int arr[10] = {10,20,30,40,50};
    int cap = 10;
    int len = 5;
    cout << "Enter the index number and the value";
    int index,value;
    cin >> index>>value;
    insertAtIndex(arr, cap,value,len,cap);


    return 0;

}