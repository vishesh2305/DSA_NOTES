#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int floorSqurareRoot(int num){
    int i=1;

    while((long long) i* i <=num){
        i++;
    }

    return i-1;
}


int main(){

    int result = floorSqurareRoot(10);
    cout << result ; 
}