// Compressed Sparse Row (CSR):

// -- CSR is a compact way to store a sparse matrix, optamized for fast row access.

// -- Instead of storing all elements (including zeros), we store only:

// 1. Non-zero elements

// 2. Column indices of those elements

// 3. Row pointers to know where each row starts in the non-zero list

// -- CSR (Compressed Sparse Row) enables fast operations on sparse matrices mainly by optimizing row-wise access and skipping zeros
// entirely.

// CSR Uses Three Arrays:

// 1. values[]
// 2. col_index[]
// 3. row_ptr[]

// Stores non-zero elements
// Stores column indices of non-zero elements
// Stores starting index of each row in values[]






#include <iostream>
#include <vector>
using namespace std;

int main(){

int matrix[4][5]= {
    {0,0,3,0,4},
    {0,0,5,7,0},
    {0,0,0,0,0},
    {0,2,6,0,0}
    };


    vector<int> values;
    vector<int> col_indexes;
    vector<int> row_ptr;

    row_ptr.push_back(0);

    int non_zero_count =0;
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            if(matrix[i][j] != 0){
                values.push_back(matrix[i][j]);
                col_indexes.push_back(j);
                non_zero_count++;
            }
        }
        row_ptr.push_back(non_zero_count);
    }

    cout << "Values array"<<endl;
    for(int i:values){
        cout << i << " ";
    }

    cout << endl;

    cout << "ColINdex array"<<endl;
    for(int i:col_indexes){
        cout << i << " ";
    }

    cout << endl;

    
    cout << "RowPtr array"<<endl;
    for(int i:row_ptr){
        cout << i << " ";
    }

    cout << endl;



}