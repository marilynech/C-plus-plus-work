#include <iostream>
using namespace std; 

int twoLeftDigitSum(int num){
    if(num < 10)
        return 0; 
    if(num < 100)
        return num / 10 + num % 10; 
    return twoLeftDigitSum(num / 10);
}

int main(){

  cout << twoLeftDigitSum(567982) << endl; // prints 11 
  cout << twoLeftDigitSum(107982) << endl; // prints 1
  cout << twoLeftDigitSum(7) << endl; // prints 7 

  return 0; 
} 