#include <iostream>
using namespace std;

int main(){
    int arr[][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int rows = sizeof(arr)/sizeof(arr[0]);

    int columns = sizeof(arr[0])/sizeof(arr[0][0]);

    for(int i=0; i<columns; i++){
        for(int j=0; j<rows; j++){
            cout << arr[j][i]<<" ";
        }
    }


}