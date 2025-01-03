#include <iostream>
#include <cmath>
using namespace std; 

int numberOdd(int x, int y){
    int count = 0; 
    if(x % 2 != 0) count++;
    if(y % 2 != 0) count++; 
    return count; 
}

int closest(double x){
    return static_cast<int>(round(x));
}

int max(int a, int b, int c, int d){
    int largest = a; 
    if(b > largest) largest = b;
    if(c > largest) largest = c;
    if(d > largest) largest = d; 
    return largest; 
}

int firstDigit(int x){
    while(x > 9){
        x /= 10;
    } 
    return x; 
}

int main(){ 
  cout << numberOdd(0, 8) << endl;    //0 
  cout << numberOdd(7, 8) << endl;    //1 
  cout << numberOdd(7, 99) << endl;   //2 
  cout << closest(3.35) << endl;	   //3 
  cout << closest(3.75) << endl;	   //4 
  cout << max(3, 1, 5, 1) << endl;	   //5 
  cout << max(0, 1, 2, 6) << endl;    //6 
  cout << max(-1, 7, 4, 1) << endl;   //7 
  cout << max(11, 1, 4, 1) << endl;   //11 
  cout << firstDigit(19683) << endl;  //1 
  cout << firstDigit(27) << endl;     //2 

  return 0; 
} 
