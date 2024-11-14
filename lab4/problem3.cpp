#include <iostream>
using namespace std;

int main(){

    double originalPrice, discountedPrice, discountPercentage; 
    cout<<"What is the item's original price? ";
    cin>>originalPrice;

    if(originalPrice <= 100){
        discountPercentage = 0.2;
    }
    else{
        discountPercentage = 0.4;
    }

    //calculate discount: 
    discountedPrice = originalPrice * (1- discountPercentage); //1-0.4 = 0.6 or 1-0.2 = 0.8 

    cout<<"The item qualifies for a "<<discountPercentage * 100<<"% discount."<<endl; 
    cout<<"The item's discounted price is $"<<discountedPrice<<". "; 

    return 0;
}