#include <iostream>
using namespace std; 

int unlucky(int x){
    if(x < 100)
        return x / 10 + x % 10 == 13; 
    return unlucky(x / 10);     
}

int main(){ 

  int x = 6789; 
  if (unlucky(x)) cout << x << " is Unlucky!\n"; 
  // prints 6789 is Unlucky!

  x = 6889; 
  if (unlucky(x)) cout << x << " is Unlucky!\n"; 
  // prints nothing.

  x = 6; 
  if (unlucky(x)) cout << x << " is Unlucky!\n"; 
  // prints nothing. 

  x = 49; 
  if (unlucky(x)) cout << x << " is Unlucky!\n"; 
  // prints 49 is Unlucky! 

  return 0; 

} 