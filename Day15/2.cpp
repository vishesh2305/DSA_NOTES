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


vector<int> mergeSort(vector<int> arr){

    if(arr.size() <=1){
        return arr;
    }
    int mid = arr.size()/2;

    // vector<int> left;
    // vector<int> right;
    // for(int i=0; i<mid; i++){
    //     left.push_back(arr[i]);
    // }

    // for(int i=mid; i<arr.size(); i++){
    //     right.push_back(arr[i]);
    // }



    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());


    left = mergeSort(left);
    right = mergeSort(right);



    return mergedarr(left, right);
}


int main(){
    vector<int> arr1={8,2,9,6,3,6,0,6,-1,4,3};

    vector<int> r = mergeSort(arr1);



    for(int i=0; i<r.size(); i++){
        cout << r[i]<<" ";
    }
    return 0;
}