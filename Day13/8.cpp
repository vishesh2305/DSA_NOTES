#include <iostream>
#include <vector>
using namespace std;


int findsqroot(int n){
    int low = 1;
    int high = n;
    int result = -1;



    while(low <= high){
        int mid = low + (high - low)/2;

        if((long long)mid*mid <= n){
            result = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return result;
}

int main(){

    int n=625;

    int result = findsqroot(n);
    cout << result;
}