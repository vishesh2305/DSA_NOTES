#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 7;
    int maxlen = 0;

    for(int i=0; i<arr.size(); i++){
        int sum =0;
        for(int j=1; j<arr.size(); j++){
            sum += arr[j];

            if(sum <=k){
                int length = j -i +1;
                maxlen= max(maxlen, length);
            }
        }
    }
    cout << maxlen<<endl;
}