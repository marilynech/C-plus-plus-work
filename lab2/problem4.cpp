#include <iostream> 
using namespace std; 

int main(){
    int height; 
    string name; 

    cout<<"Enter your name: ";
    cin>>name; 

    cout<<"What is your height in inches? ";
    cin>> height;
    double convertedHeight = 2.54 * height; 
    cout<<"Hi "<<name<<".M You are " <<convertedHeight<<" centimeters tall.";

    return 0;
}