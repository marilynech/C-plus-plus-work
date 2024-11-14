#include <iostream>
using namespace std; 

int twoLeftDigitSum(int num){
    if(num < 10)
        return 0; 
    if(num < 100)
        return num / 10 + num % 10; 
    return twoLeftDigitSum(num / 10);
}