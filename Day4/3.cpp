#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {10,20,30,40,50};
    cout << "Enter the index number and the value";
    int index;
    cin >> index;
    if(index < 0 || index > arr.size()){
        cout << "Invalid Index "<<endl;
    } else{
        // arr.push_back(0);
        // for(int i= arr.size() -1; i> index; i--){
        //     arr[i] = arr[i-1];
        // }
        // arr[index] = 0;
        arr.insert(arr.begin()+index, 0);
    }
        for(int i=0; i<arr.size(); i++){
        cout << arr[i]<<" ";
    }
    return 0;
}