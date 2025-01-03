#include <iostream>
#include <ctime>

using namespace std; 

int main (){
    srand(time(0)); //random nums 
    int heads = 0, tails = 0; //initialize values

    //10 times
    for(int i = 0; i < 10; i++){
        int r = rand() % 2; // gives us 0 or 1 
        if( r == 0 )
            heads++;
        else
            tails++; 
    }

    cout<<"Probability of heads given 10 tosses = "<<heads / 10.0 <<endl;
    cout<<"Probability of tails given 10 tosses = "<<tails / 10.0 <<endl; 

    //100 times
    heads = 0, tails = 0;
    for(int i = 0; i < 100; i++){
        int r = rand() % 2; // gives us 0 or 1 
        if( r == 0 )
            heads++;
        else
            tails++; 
    }

    cout<<"Probability of heads given 100 tosses = "<<heads / 100.0 <<endl;
    cout<<"Probability of tails given 100 tosses = "<<tails / 100.0 <<endl; 

    //1000 times 
    heads = 0, tails = 0;
    for(int i = 0; i < 1000; i++){
        int r = rand() % 2; // gives us 0 or 1 
        if( r == 0 )
            heads++;
        else
            tails++; 
    }

    cout<<"Probability of heads given 1000 tosses = "<<heads / 1000.0 <<endl;
    cout<<"Probability of tails given 1000 tosses = "<<tails / 1000.0 <<endl; 

    //100000
    heads = 0, tails = 0;
    for(int i = 0; i < 10000; i++){
        int r = rand() % 2; // gives us 0 or 1 
        if( r == 0 )
            heads++;
        else
            tails++; 
    }

    cout<<"Probability of heads given 10000 tosses = "<<heads / 10000.0 <<endl;
    cout<<"Probability of tails given 10000 tosses = "<<tails / 10000.0 <<endl; 


    return 0;

}

