#include <iostream>
#include <vector>
using namespace std;



void processCSR(vector<vector<int>>& matrix, vector<int>& values, vector<int>& col_index, vector<int>& row_ptr){


    int rows = matrix.size();
    int cols = matrix[0].size();

    row_ptr.push_back(0);
    int non_zero_count=0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != 0){
                values.push_back(matrix[i][j]);
                col_index.push_back(j);
                non_zero_count++;
            }
        }
        row_ptr.push_back(non_zero_count);
    }


}


int main(){

        vector<vector<int>> v = {
        {0, 0, 0, 0, 1},
        {0, 2, 0, 0, 3},
        {0, 0, 0, 0, 0},
        {0, 4, 0, 5, 0}
    };

    vector<int> values;
    vector<int> row_ptr;
    vector<int> col_index;

    processCSR(v,values, col_index, row_ptr);

    cout << "Values "<<endl;

    for(int i: values) cout << i<<" ";
    cout <<endl;



    cout << "col_index "<<endl;

    for(int i: col_index) cout << i<<" ";
    cout <<endl;


        cout << "Row_ptr "<<endl;

    for(int i: row_ptr) cout << i<<" ";
    cout <<endl;



    cout << "Generating Original Sparse Matrix from the CSR representation";

    // num of rows = row_ptr.size() -1;
    // no of col = max col index + 1;


    int rows = row_ptr.size() -1 ;
    int maxcols = 0;
    for(int i:col_index){
        if(i > maxcols){
            maxcols = i;
        }
    }

    int cols = maxcols + 1;

    vector<vector<int>> rebuild(rows, vector<int>(cols,0));


    for(int i=0; i<rows; i++){
        int start = row_ptr[i];
        int end = row_ptr[i+1];

        for(int j=start; j<end; j++){
            int val = values[j];
            int col = col_index[j];
            rebuild[i][col] = val;
        }
    }


    for(auto& row: rebuild){
        for(int v: row){
            cout << v<< " ";
        }
        cout <<endl;
    }
    return 0;


}