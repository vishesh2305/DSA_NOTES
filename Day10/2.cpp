#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr= {1,2,3,4,5};
    for(int i=0; i<arr.size(); i++){
        vector<int>temp;

        for(int j=i; j<arr.size(); j++){
            temp.push_back(arr[j]);
            for(int x: temp){
                cout << x << " ";
            }
            cout << endl;
        }

    }

    
    return 0;
}