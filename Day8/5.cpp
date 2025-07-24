#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
using namespace std;
    //sparce matris-----------most of the elements are zero--------------

    //1.using Triplets --COO representation----Coordinate list
    //2.CSR--Compressed Sparce Row.
    //3.CSC--Compressed Sparce Columns

struct Triplet {
    int row, col, value;
};

vector<Triplet> getTripletMatrix(vector<vector<int>>& matrix) {
    vector<Triplet> result;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                result.push_back({i, j, matrix[i][j]});
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> v = {
        {0, 0, 0, 0, 1},
        {0, 2, 0, 0, 3},
        {0, 0, 0, 0, 0},
        {0, 4, 0, 5, 0}
    };
//triplet represesntation-----------------------------------------
    vector<Triplet> vec = getTripletMatrix(v);
    for (auto& t : vec) {
        cout << t.row << " " << t.col << " " << t.value << endl;
    }

    int maxrow=0;
    int maxcol=0;

    for(auto& t:vec){
        maxrow=max(maxrow,t.row);
        maxcol=max(maxcol,t.col);
    }
    int rows=maxrow+1;
    int cols=maxcol+1;
    vector<vector<int>> rebuild(rows,vector<int>(cols,0));


    for(auto& t:vec){
        rebuild[t.row][t.col] = t.value;
    }


    cout << "Original Matrix"<<endl;
    for(auto& row:rebuild){
        for(auto& v:row){
            cout << v <<" ";
        }
        cout << endl;
    }
    







    return 0;
}
// --------------convert the triplet representation to the orijinal sparce matrix-----HW------------------------