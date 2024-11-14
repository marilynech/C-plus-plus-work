#include <iostream>
using namespace std;

int main(){
    int n, sumDigits = 0; 

    cout<<"Enter a positive integer: ";
    cin>>n;

    while(n <= 0){
        cout<<"Invalid input! Try again: ";
        cin>>n; 
    }
    
    while(n > 0){
        if((n % 10) % 2 == 1){
            sumDigits += n % 10; 
        }
        n /= 10; 
    }

    cout<<"The sum of the odd digits in the number is "<<sumDigits<<".";

    return 0;
}