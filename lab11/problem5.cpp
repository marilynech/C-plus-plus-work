#include <iostream>
using namespace std; 

int sumCubes(int n){
    if(n <= 0)
        return 0; 
    return n * n * n + sumCubes(n-1); 
}

int main(){ 

  cout << sumCubes(5) << endl; // prints 225 
  cout << sumCubes(8) << endl; // prints 1296

  return 0; 
} 