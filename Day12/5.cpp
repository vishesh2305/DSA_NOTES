#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {10,5,2,7,1,9};

    int k = 15;

    int start = 0;
    int currentsum=0;
    int maxlen = 0;

    for(int i=0; i<arr.size();i++){
        currentsum+= arr[i];

        while(currentsum > k && start <= i){
            currentsum -= arr[start];
            start++;
        }

        if(currentsum == k){
            maxlen = max(maxlen, i - start + 1);
        }
    }
}