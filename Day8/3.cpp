#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[][4]={
        {0,0,1,0},
        {0,2,0,0},
        {0,3,4,0}
    };

    // The above matrix is a sparse matrix.

    // We can perform operation on it using : 
    // 1. Using triplet --COO representation
    // 2. CSR --Compressed Sparce row
    //3. CSC -- Compressed sparce columns



    int rows = sizeof(arr)/sizeof(arr[0]);

    int columns = sizeof(arr[0])/sizeof(arr[0][0]);

    int non_zero_count = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(arr[i][j] != 0){
                non_zero_count++;
            }
        }
    };


    int tripleMatrix[non_zero_count][3];


    int idx =0;


    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){

            if(arr[i][j] != 0){

                tripleMatrix[idx][0] = i;
                tripleMatrix[idx][1] = j;
                tripleMatrix[idx][2] = arr[i][j];

                idx++;

            }

        }
    };



    // Print the tripletMatrix

    cout << "Row     Col     value"<<endl;
        for(int i=0; i<non_zero_count; i++){
            cout << tripleMatrix[i][0]<<"     "<< tripleMatrix[i][1]<< "     "<< tripleMatrix[i][2]<<endl;
    };










}