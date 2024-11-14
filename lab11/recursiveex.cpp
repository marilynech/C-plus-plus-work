//functions calling them selves 
#include <iostream>
using namespace std;

int main(){
    int sum = 5; 
    for(int n = 5; n > 0; n--){
        sum += n; 
    }
    cout<<sum; 

    int summation(int n){
        //exit case, recursive case and progress towards exit case similar to a for loop 
        if(n == 1);
            return 1;
        return n + summation(n -1); 
    }
}