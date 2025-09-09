#include <iostream>
using namespace std;

int main(){
    int arr[7] = {7,8,2,6,5,1,3};

    for(int i=1;i<7; i++){
        int key = arr[i];

        int j = i-1;


        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }


        arr[j+1] = key;
    
    };


    for(int i=0; i<7; i++){
        cout << arr[i]<< " ";
    }
return 0;
}