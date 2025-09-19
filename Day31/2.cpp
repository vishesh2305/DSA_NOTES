#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> NGE(vector<int>& arr){
    vector<int> result(arr.size());
    stack<int> st;

    for(int i=arr.size() -1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            result[i] = -1;
        }else{
            result[i] = st.top();
        }
        st.push(arr[i]);
    }

    return result;
}


int main(){

    vector<int> arr = {4,5,2,25};
    vector<int> result =  NGE(arr);

    for(int i=0; i<result.size(); i++){
        cout << result[i]<<" ";
    }
    cout << endl;

}