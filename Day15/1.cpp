#include <iostream>
#include <vector>
using namespace std;


vector<int> mergedarr(vector<int> arr1, vector<int> arr2){
    vector<int> result;
    int i=0;
    int j=0;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] <arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }else{
            result.push_back(arr2[j]);
            j++;
        }
    }

        while(i < arr1.size()){
        result.push_back(arr1[i]);
        i++;
    };

    while(j < arr2.size()){
        result.push_back(arr2[j]);
        j++;
    }


    return result;
}

int main(){
        vector<int> arr1={4,6,8,12,15};
    vector<int> arr2={3,4,9,18,20};

    vector<int> vec = mergedarr(arr1, arr2);

        for(auto i: vec){
        cout << i << " ";
    };

    return 0;
}