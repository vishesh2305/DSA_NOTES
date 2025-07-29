#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;
    int count = arr.size() - k + 1;
    cout << "Number of sub array of length "<< k <<"Will be "<< count << endl;
    for(int i=0; i<count; i++){
        vector<int> temp;
        for(int j=i; j<i+k; j++){
            cout << arr[j]<< " ";
        }
        cout << endl;
    }
}