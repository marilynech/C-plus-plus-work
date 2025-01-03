#include <iostream>
#include <cmath>
using namespace std; 

bool areVeryDifferent(int a, int b){
    return abs(a - b) > 10; 
}

int main(){ 

    int x = 4, y = 10, z = -4;

    if (areVeryDifferent(x, y)) 
        cout << "x and y are very different." << endl; 
    if (areVeryDifferent(x, z)) 
        cout << "x and z are very different." << endl; 
    if (areVeryDifferent(y, z)) 
        cout << "y and z are very different." << endl; 

    return 0; 

} 
//return type is a boolean expresssion will give tru or false value if diffference f
//greater than 10 return true otherwise return false
