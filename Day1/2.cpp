#include <iostream>
using namespace std;

int sumofarray(int n, int arr[]){
    int sum =0;

    for(int i=0; i <n; i++){
        sum += arr[i];
    };
    return sum;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << sumofarray(n, arr);
};