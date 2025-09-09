#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[7] = {7,8,2,6,5,1,3};
    for(int i=0; i<6; i++){
        int smallelindex = i;
        for(int j=i+1; j<7; j++){

            if(arr[j] < arr[smallelindex]){
                smallelindex = j;
            };

        };
        if(smallelindex != i){
        swap(arr[i], arr[smallelindex]);
        };
    };

    for(int i=0;i<7; i++){
        cout << arr[i]<<" ";
    }

}