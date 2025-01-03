#include <iostream>
using namespace std; 

void triple(int arr[], int size){
    for(int i = 0; i < size; i++)
    arr[i] += 3; 
}
void fillMatrix(int matrix[][3], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){
        for(int j =0; j < numCols; j++){

        }
    }

}
int main(){
    int matrix[3][3]; 
    int arr[] = {1,2,3};
    int size = 3; 

    for(int i : arr){
        cout<<i<<endl; 
    }
}
//always take reference of an array they can be huge and several megabytes so if its copied it becomes expesnive and takes up 
//space and time, so use pass by reference 
