#include <iostream>
using namespace std; 

int main(){

    double originalPrice, discountPrice, reducedPrice; 
    cout<<"What is the original price? ";
    cin>>originalPrice; 

    if(originalPrice >= 125) {
        discountPrice = originalPrice * 0.90; //discount 10%
        cout<<"The reduced price is $"<<discountPrice; 
    }
    else{
        cout<<"That does not qualify for a discount. The price is $"<<originalPrice; 
    }

    return 0; 

}