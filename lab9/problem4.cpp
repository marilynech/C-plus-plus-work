#include <iostream>
#include <ctime>
using namespace std; 

int main(){
    int count = 0; 
    int guess; 
    srand(time(0));

    int n = rand() % 100 + 1; 
    cout<<"Guess the integer I picked from the range 1 to 100: "; 
    cin>>guess; 
    count++; 

    while(guess != n){
        if(guess > n){
            cout<<"Too big."<<endl; 
        }
        else if(guess < n){
            cout<<"Too small."<<endl; 
        }
        cin>>guess; 
        count++; 
    }

    cout<<"Congratulations! You took "<<count<<" guesses. "<<endl; 

    return 0; 
}


//in loop count++