#include <iostream>
using namespace std; 

int main(){
    double grade, sum = 0; 
    int count = 0; 

    cout<<"Enter a numeric grade (enter a negative number to stop): ";
    cin>> grade; 

    while(grade >= 0){
        sum += grade; 
        count++; 

        cout<<"Enter a numeric grade (enter a negative number to stop): ";
        cin>>grade; 
    }

    if(count > 0){
        double average = sum / count;
        cout<<"The average grade is "<<average<<endl; 
    }
    else{
        cout<<"Please enter some grades to get average."<<endl; 
    }

    return 0;
}