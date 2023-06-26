//check if all elements in array are even 
//areALlEven([4,6,2,0],4) true
//areAllEven([12,2,3,7],4) false
#include <iostream>
using namespace std; 

bool areAllEven(int arr[], int n);
int main(){
    int arr[4] = {2,20,46,14};
    if(areAllEven(arr,4)==true){
        cout<<"All are even"<<endl; 
    }
    else{
        cout<<"Not all are even"<<endl; 
    }
    return 0; 
}

bool areAllEven(int arr[], int n){
    bool res; 
    if(n == 1){
        return(arr[0]%2 == 0); //solve base case when theres a small input
    }
    else{
        res = areAllEven(arr, n -1);
        if (res == true){
            return(arr[n-1]%2 == 0); //check last element
        }
        else{
            return false; 
        }
    }
}