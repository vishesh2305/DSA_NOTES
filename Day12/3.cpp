#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int main(){
    vector<int> arr = {2,3,4,5,6,1,2,3};

    int length = 4;

    int arrcount = arr.size() - length + 1;   

    int count = 0;

    for(int i=0; i<length; i++){
        unordered_set <int> s;

        for(int j=i; j<i+length; j++){
            s.insert(arr[j]);
        }
        cout << s.size()<< " ";

    }

    return 0;
}