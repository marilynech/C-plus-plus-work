//oddLessEven 
#include <iostream>
using namespace std; 

int oddLessEven(int n){
    while(n > 0){
        int digit = n % 10; 
        n /= 10; 
    }
}

//int total if even subtract if odd add to the total and then return 