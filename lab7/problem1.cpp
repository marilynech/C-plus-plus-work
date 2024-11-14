#include <iostream>
using namespace std; 

int main(){
    int n; 
    cout<<"Enter a positive integer: "; 
    cin>>n;

    while(n <= 0){
        cout<<"Bad input! Try again: "; 
        cin>>n; 
    }

    bool containsFive = false; 
    int temp = n;

    while(temp > 0){ //check to see if there is a 5
        if(temp % 10 == 5){
            containsFive = true;
            break; //breaks once 5 is detected so dont keep on looping
        }
        temp /= 10; 
    }

    if(containsFive)
        cout<<"The number contains the digit 5.";
    else
        cout<<"The number does not contain the digit 5.";

    return 0; 
}