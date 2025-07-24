#include <iostream>
#include <vector>
using namespace std;


struct Triplet{
    int row, col, value;
};

void processSparseInTriplet(vector<vector<int>>& vec){

    vector<Triplet> triplet;

    int rows = vec.size();
    int cols = vec[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(vec[i][j] != 0){
                triplet.push_back({i,j,vec[i][j]});
            }
        }
    };

    cout <<"Row    Col    Value"<<endl;
    for(auto& t:triplet){
        cout << t.row<<"    "<<t.col<<"    "<<t.value<<"    "<<endl;
    }

};


int main(){


    vector<vector<int>> arr = {
        {1,0,0,2},
        {0,0,3,0},
        {0,0,5,0},
    };
    processSparseInTriplet(arr);
return 0;
}