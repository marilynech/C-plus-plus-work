#include <iostream>
#include <ctime>
#include <cmath>
using namespace std; 

int main(){
    srand(time(0)); 
    int num1, num2; 

    cout<<"Enter two positive integers with a difference of at least 10: ";
    cin>>num1>>num2; 

    while(num1 <= 0 || num2 <= 0 || abs(num1 - num2) < 10){
        cout<<"Invalid input! Try again: "; 
        cin>>num1>>num2; 
    }

    int min,max;
    //cout<<abs(-5)<<endl; 
    //get two numbers subtract them and find the abs value of the result >= 10 to nag user to give right values
    if (num1 < num2){
        min = num1;
        max = num2;
    }
    else{
        min = num2;
        max = num1;
    }
//6-1+1 = 6 
//6-2+1 = 5
    int randomNum = rand()% (max - min + 1) + min; // will give you what you need when you know the bounds general equation u can use 
//applies if minimum is not 0

    cout<<"Random integer between "<<min<<" and "<<max<<" is "<<randomNum<<"."<<endl; 

    return 0; 

}