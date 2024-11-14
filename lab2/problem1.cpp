#include <iostream>
using namespace std; 

int main(){
    int x , y; 
    cout<<"Please enter a value for x: "; 
    cin>> x;
    cout<<"Please enter a value for y: "; 
    cin>> y;

    int addition = x + y;
    int subtraction = x - y; 
    int multiplication = x * y; 
    double average = addition / 2.0; 
    int divistion = x % y;

    cout<<"The sum of "<<x<<" and " <<y<< " is "<<addition<<endl;
    cout<<y<<" subtracted from "<<x<<" is "<<subtraction<<endl; 
    cout<<"The product of "<<x<<" and "<<y<<" is "<<multiplication<<endl;
    cout<<"The average of "<<x<<" and "<<y<<" is "<<average<<endl; 
    cout<<"The remainder when "<<x<<" is divided by "<<y<<" is "<<divistion<< endl; 

    return 0; 
}
