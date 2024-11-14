#include <iostream> 
using namespace std; 

int main(){
    int n;
    cout<<"Enter an odd positive integer n: ";
    cin>>n; 

    if(n % 2 == 0 || n <= 0) return 0; 

    int mid = n / 2;

    //n by n gride
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout<<" "; 
        }

        if(i < mid){
            cout<<"+";
        }
        else if(i == mid){
            cout<<"*";
        }
        else{
            cout<<"x";
        }
        cout<<endl; 
    }

    return 0;
}