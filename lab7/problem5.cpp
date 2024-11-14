#include <iostream>
using namespace std; 

int main(){
    cout<<"Enter a number between 10 and 20: ";
    int num; 
    cin>>num; 

    if(num > 20 || num < 10){
        cout<<"Program ending..."<<endl; 
        return 0; 
    }
    
    bool star = false; 
    while(num > 0){
        if (star){
            cout<<"*"; 
            star = false; 
        }
        else{
            cout<<"^";
            star = true;
        }
        num--;
    }
    return 0; 
}