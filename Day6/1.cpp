#include <iostream>
using namespace std;

int main(){

    int arr[] = {10,20,30,10};

    int length = sizeof(arr)/sizeof(arr[0]);

    int rev[length];

    for(int i=0; i<length; i++){
        rev[i] = arr[length -i - 1];
    }

    bool flag = true;
    for(int i=0; i<length; i++){
        if(arr[i] != rev[i]){
            flag = false;
            break;
        }
    };

    if(flag){
        cout << "It is a palindrome";
    }else{
        cout << "Not a Palindrome";
    }

    return 0;
}