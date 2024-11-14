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
    return 0; 
}