#include <iostream>
using namespace std; 

int main(){

//for each number square it and check if the last two digits are odd 
    for(int i = 1; i <= 99; ++i){
        int sqaure = i * i; 
        if(sqaure % 2 != 0 && (sqaure/10) % 2 != 0){
            cout<<sqaure; 
            return 0; //solution was found here
    }
}

//testing only the first 99 numbers is sufficent because the last 2 digits of a square depends
//on the last 2 digits of the number being sqaured. 
    cout<<"there is no solution";
    return 0; 
}