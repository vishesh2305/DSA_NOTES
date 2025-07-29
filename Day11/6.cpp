#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    sort(arr.begin(), arr.end());

    int sum =0;
    vector<int> temp;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>=0){
            for(int j= i; j<arr.size(); j++){
                sum += arr[j];
                temp.push_back(arr[j]);
            }
            break;
        }
    }
    for(auto i: temp){
        cout << i<< " ";
    }
    cout << " & sum is : "<< sum <<endl;


}