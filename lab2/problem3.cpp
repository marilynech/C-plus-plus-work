#include <iostream>
using namespace std; 

int main(){
    int x; //intialize value first

    cout<<"Please enter a four digit number: "<<endl; 
    cin>>x; 
    //getting each digit 
    int onesPlace = x % 10; 
    int tenthsPlace = (x / 10) % 10; //deleting the last place then getting the num 
    int hundredthsPlace = (x / 100) % 10; 
    int thousandthsPlace = (x / 1000) % 10;

    //int digit1 = x % 10 -> x / 10 

    cout<<"Your number in reverse is: "<<onesPlace<<tenthsPlace<<hundredthsPlace<<thousandthsPlace<<endl; 

    return 0; 
    
}