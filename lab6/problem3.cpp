#include <iostream>
using namespace std; 

int main(){
    int n ;
    cout<<"Enter a positive integer: ";
    cin>>n; 

    while(n <= 0){
        cout<<"Invalid input! Try again: ";
        cin>>n;
    }

    cout<<"The factors of "<<n<<" are: "; 

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout<<i<<" ";
        }
    }
    
    cout<<endl; 
    return 0; 
}