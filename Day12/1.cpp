#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    
    int length = 3;
    int count = arr.size() - length + 1;

    for(int i=0; i<count; i++){
        vector<int> temp;
        for(int j=i;j<arr.size(); j++){
            temp.push_back(arr[j]);

            if(temp.size() == length){
                for(int k=0; k<temp.size(); k++){
                    cout << temp[k]<< " ";
                }
                cout << endl;
            }

        };
    }
}