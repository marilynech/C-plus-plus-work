#include <iostream>
using namespace std; 

int sumCubes(int n){
    if(n <= 0)
        return 0; 
    return n * n * n + sumCubes(n-1); 
}

int main(){
    cout<<sumCubes(5);
    cout<<sumCubes(8); 
}