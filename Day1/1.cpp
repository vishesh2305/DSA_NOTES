#include <iostream>
using namespace std;
int foundarr(int n,int arr[], int target){
    for(int i=0; i < n; i++){
        if(arr[i] == target){
            return i;
        };
    };
    return -1;
};
int main(){
    int arr[5] = {3,1,4,7,5};
    cout<<foundarr(5, arr,7);
    return 0;
}