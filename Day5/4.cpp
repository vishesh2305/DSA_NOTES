#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,60,48,693,46};

    int length = sizeof(arr) / sizeof(arr[0]);
    // reverse(arr, arr+length);

    if()

    for(int i=0; i<length/2;i++){
        int temp = arr[i];
        arr[i] = arr[length - i -1];
        arr[length - i - 1] = temp;
    };

    for(int i=0; i<length; i++){
        cout << arr[i] << " ";
    }

    return 0;
}