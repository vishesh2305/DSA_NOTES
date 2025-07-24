#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arraySum(vector<vector<int>> &A, vector<vector<int>> &B, int n){

    vector<vector<int>> result(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;

};

int main(){

    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    cout << "Enter the Elements of First Array : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    };

        vector<vector<int>> B(n, vector<int>(n));
        cout << "Enter the Elements of Second Array : ";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> B[i][j];
        }
    };

    vector<vector<int>> result(n, vector<int>(n));

    cout << "Sum of two Arrays is : "; 
    cout << endl;
    result = arraySum(A, B, n);

        // for(int i=0; i<n; i++){
        // for(int j=0; j<n; j++){
        //     cout << result[i][j]<< " ";
        // }
        // cout << endl;
    // };

    // for(vector<int> &v: result){
    //     for(int i: v){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }


        for(auto &v: result){
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;
    }
return 0;
}


