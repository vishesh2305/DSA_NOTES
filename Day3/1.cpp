#include <iostream>
using namespace std;


int main(){

    int arr[8] = {10,20,30,40,50,60,70,80};

    int n;
    cout << "Enter the index from which you want to retrieve the element (**^<@>^**) : "; cin >> n;

    if(n > size(arr)){

        cout << "Please enter a valid index ^_&\n";

    }else{
        cout << arr[n];
    }

    return 0;


    
};
