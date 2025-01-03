#include <iostream>
using namespace std; 

int thirdDigit(int num){
    if(num < 100)
        return 0; 
    if(num < 1000)
        return num % 10; 
    return thirdDigit(num / 10); 
}

int main(){ 

  cout << thirdDigit(347) << " "; 
  cout << thirdDigit(2048) << " "; 
  cout << thirdDigit(560125) << endl; 
  // This code should print: 
  // 7 4 0 
  return 0; 
} 