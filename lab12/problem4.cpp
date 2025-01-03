//loop to go through array and then loop that prints the stars
#include <iostream>
using namespace std; 

int main(){
    int n; 
    int rowLength[100]; 

    cout<<"How many rows (at most 100)? "; 
    cin>>n; 

    if(n < 1 || n > 100){
        cout<<"Invalid input. Program will terminate."<<endl; 
        return 0; 
    }

    cout<<"Enter "<< n <<" row lengths: "; 
    for(int i = 0; i < n; i++){
        cin>> rowLength[i]; 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < rowLength[i]; j++){
            cout<<"*"; 
        }
        cout<<endl; 
    }

    return 0; 
}