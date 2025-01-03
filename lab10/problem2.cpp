//oddLessEven 
#include <iostream>
using namespace std; 

int oddLessEven(int n){
    int total = 0; 

    while(n > 0){
        int digit = n % 10; 
        if(digit % 2 == 0){
            total -= digit; 
        }
        else{
            total += digit; 
        }
        n /= 10; 
    }
    return total;  
}

int main(){ 
  cout << oddLessEven(23) << endl; // prints 1 
  cout << oddLessEven(1234) << endl; // prints -2 
  cout << oddLessEven(777) << endl; // prints 21 

  return 0; 
} 

//int total if even subtract if odd add to the total and then return 