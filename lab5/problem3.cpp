#include <iostream>
using namespace std; 

int main(){
    int x,y; //declare two ints

    cout<<"Enter two numbers: "; 
    cin>> x >> y;

    if( x + y >= 100)
        cout<<"True";
    else
        cout<<"False";

    return 0; 
}