#include <iostream>
using namespace std;

int main(){

    int num1, num2, num3;

    cout<<"Enter three numbers: "; 
    cin>>num1>>num2>>num3; 

    if(num1 < num2 && num2 < num3){
        cout<<"Increasing"<<endl;
    }
    else if(num1 > num2 && num2 > num3){
        cout<<"Decreasing"<<endl;
    }
    else{
        cout<<"Neither"<<endl; 
    }

    return 0;
}