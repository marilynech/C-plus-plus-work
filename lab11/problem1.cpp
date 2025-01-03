//base case
//if num1 == 0 || num2 == 0 || num3 == 0)
#include <iostream>
using namespace std; 

int digitMatch(int a, int b, int c){
    if(a == 0 || b == 0 || c == 0){
        return 0;
    }

    int digit1 = a % 10;
    int digit2 = b % 10; 
    int digit3 = c % 10; 
    
    if(digit1 == digit2 && digit1 == digit3){
        return 1 + digitMatch(a / 10, b / 10, c / 10);
    }
    return digitMatch(a / 10, b / 10, c / 10); 
}

int main(){
    
  cout << digitMatch(168, 567, 767) << endl; // prints 1 
  cout << digitMatch(143, 243, 343) << endl; // prints 2 

  return 0; 

} 