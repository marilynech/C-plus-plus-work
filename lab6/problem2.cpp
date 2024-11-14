#include <iostream>
using namespace std; 

int main(){

    int n; 
    cout<<"Enter a positive integer: "; 
    cin>>n; 

    while(n <= 0){
        cout<<"Invalid input! Try again: "; 
        cin>>n; 
    }
    cout<<"Your number in binary in reverse order is: ";
    //convert num to binary in reverse order
    while(n > 0){
        cout<< n % 2;
        n = n / 2; 
    }

    cout<<endl; 

    return 0; 
    
}