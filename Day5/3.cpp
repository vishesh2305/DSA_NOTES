#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    vector<int> arr = {10,20,40,30,69,197,5602,209,238};

    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }


return 0;
}