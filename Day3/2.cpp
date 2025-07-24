#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<vector<int>> A = {{10,20,30}, {40,50}, {60}};

    for(int i=A.size() -1 ; i>=0; i--){

        for(int j=0; j<A[i].size(); j++){
            cout << A[i][j]<<endl;
        }

    }


}