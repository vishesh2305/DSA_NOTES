#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int arr[] = {10,20,75,30,40,50,80};

    int largestel = arr[0];
    int secondlg = arr[0];

    for(int i=0; i<size(arr); i++){

        if(arr[i] > largestel){
            secondlg = largestel;
            largestel = arr[i];
        } else if(arr[i] > secondlg && arr[i] != largestel){
            secondlg = arr[i];
        };
    };

    // for(int i=0; i<size(arr) - 1; i++){
    //     if(arr[i] > secondlg && arr[i] != secondlg){
    //         if(arr[i] > secondlg){
    //             secondlg = arr[i];
    //         }
    //     }
    // }

    if(secondlg >=0){
        cout << secondlg;
    }else{
        cout << "All elements are equal";
    }




return 0;
}