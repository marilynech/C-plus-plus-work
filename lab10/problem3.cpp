#include <iostream>
using std::cout;
using std::endl; 

double sumRatios(int a, int b){
    double sum = 0; 
    while(a > 0){
        double digit = a % 10; 
        sum += digit / (b % 10);
    

        a /= 10;
        b /= 10;
    }
    return sum; 
}

int main(){
    sumRatios(132,568);
    sumRatios(123,456);
    sumRatios(12,15); 
}
//return the sum of their ratios 

//132,568 -> want to rturn 1/5+3/6+2/8
//123,456 -> 1/4+2/4+3/6 //return type is going to be a double 