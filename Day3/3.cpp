#include <iostream>
#include <vector>
using namespace std;

int main(){

    int arr[10] = {2,4,6,2,7,24,7,2,0,1};


    int largestel = arr[0];
    int smallel = arr[0];

    for(int i=0; i < size(arr) -1; i++){


        if(arr[i] > largestel){
            largestel = arr[i];
        };
        if(arr[i] < smallel){
            smallel = arr[i];
        }


    }
    cout << largestel<<endl;
    cout << smallel << endl;


    return 0;

}