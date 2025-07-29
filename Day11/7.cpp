#include <iostream>
#include <vector>
using namespace std;
int main (){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int currentSum =0;
    int maxsum = INT_MIN;
    int start = 0;
    int end = 0;
    int x =0;
    for(int i=0; i<size; i++){
        currentSum += arr[i];
        if(currentSum >maxsum){
            maxsum = currentSum;
            start = x;
            end = i;
        }else if (currentSum < 0){
            currentSum =0;
            x=i+1;
        };
    };
    for(int i=start; i<end; i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
    cout << maxsum;
}