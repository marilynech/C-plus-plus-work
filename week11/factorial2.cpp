//n! = n*(n-1)*(n-2)..2*1
#include <iostream>
using namespace std; 

int factorial(int n);
int main(){
    cout<<factorial(4)<<endl; 
    return 0; 

}

int factorial(int n){
    int res; 
    if(n==1){
        return 1; 
    }
    else{
        res = factorial(n-1);
        res *= n; 
        return res; 
    }
}