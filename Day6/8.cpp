#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {10,0,20,30,40,50,60,80,70,100};

    int target = 100;
    int length = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+length);

    int start=0;
    int end = length -1;

while (start < end) {
    int sum = arr[start] + arr[end];
    if (sum == target) {
        cout << arr[start] << " , " << arr[end] << endl;
        start++;
        end--;
    } else if (sum < target) {
        start++;
    } else {
        end--;
    }
}



}