#include <iostream>
using namespace std; 

int main(){

    int n; 
    cout<<"Enter an odd positive integer: ";
    cin>>n; 

    if(n % 2 == 0 || n <= 0) exit(0); 

    int middle = (n / 2); 

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(r == c && r == middle){
                cout<<"*";
            }
            else if(r == c){
                cout<<"+";
            }
            else if(r + c == n - 1){
                cout<<"x"; 
            }
            else{
                cout<<" "; 
            }
        }
        cout<<endl; 
    }

    return 0;
}