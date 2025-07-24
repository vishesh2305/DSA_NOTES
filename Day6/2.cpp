#include <iostream>
using namespace std;

int main(){

    int arr[] = {10,20,30,10};

        int length = sizeof(arr)/sizeof(arr[0]);

        int start = 0;
        int end = length - 1;


        bool flag = true;
        while(end > start){
            if(arr[start] != arr[end]){
                flag = false;
                break;
            }
            start++;
            end--;
        };

        if(flag){
            cout << "Palindrome";
        }else{
            cout << "No";
        }


        return 0;
}