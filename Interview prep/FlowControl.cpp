#include <iostream>
using namespace std; 

//program to print a pos number entered by the user if the user enters a negative number it is skipped 

int main(){
//C++ if statments 
    /*int number; 
    cout<<"Enter an integer: "; 
    cin>>number; 

    //checks if the num is positive pos
    if(number > 0){
        cout<<"You entered a positive integer "<<number<<endl; 
    }

    cout<<"This statement is executed always"; 

    return 0; */
    //user enters a number 5 the condition num > 0 is executed to true and the statment inside the body of if is executed
    //user enters -5 the condition is evalued to false and the statmenet inside the body of if is not executed 

//C++ if else statements 
//check whether an integer is pos or negative considers 0 as a positive num 

   /* int number;
    cout<<"Enter an integer: "; 
    cin>>number; 

    if(number >= 0 ){
        cout<<"You've enters a positive integer: "<<number<<endl; 
    }
    else{
        cout<<"You've entered a negative integer: "<<number<<endl; 
    }

    cout<<"This line is always printed."; 

    return 0; */

//C++ if else else if statement 
//check whether an integer is positive, negative, or zero 
/*
    int number; 
    cout<<"Enter an integer: "; 
    cin>>number; 

    if(number > 0){
        cout<<"You entered a positive integer: "<<number<<endl;
    }
    else if(number < 0){
        cout<<"You entered a negative number: "<<number<<endl; 
    }
    else{
        cout<<"You entered 0"<<endl; 
    }

    cout<<"This line is always printed. "; 

    return 0; 

    */

//C++ nested if else statements
//find if an integer is positive, negative or zero using nested if statments
    int num; 
    cout<<"Enter an integer: ";
    cin>>num; 

    //outer if condition 
    if(num != 0){
        //inner if condition
        if(num > 0){
            cout<<"The number is a positive number."<<endl; 
        }
        //inner else condition 
        else{
            cout<<"The number is negative."<<endl; 
        }
    }
    else{
        cout<<"The number is 0 and it is neither positive nor negative. "<<endl; 
    }

    cout<<"This line is always printed. "<<endl; 

    return 0; 
}