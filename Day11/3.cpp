#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,4,5};
    

    int len = arr.size();

    for(int i=0; i<len; i++){
        vector<int> temp;
        int sum =0;
        for(int j=i; j<len; j++){
            temp.push_back(arr[j]);

            sum += arr[j];
            for(auto x : temp){
                cout << x << " ";
            }
            cout <<" ==> " <<sum<<endl;
            cout << endl;
        }
    }

}