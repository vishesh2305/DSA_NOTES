#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> arr = {2,3,4,5,6,1,2,3};

    int length = 4;

    int count = arr.size() - length + 1;    
    int windowssum = 0;

    for(int i=0; i<length;i++){
        windowssum += arr[i];
    };
    int maxsum = windowssum;

    for(int i=length; i < arr.size(); i++){
        windowssum += arr[i] - arr[i-length];
        maxsum = max(maxsum, windowssum);
    }

    cout << "Maximum sum of subarray of size "<< length << " is : "<< maxsum << endl; 

}