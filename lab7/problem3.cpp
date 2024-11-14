#include <iostream>
using namespace std; 

int main(){
    int n; 
    cout<<"Enter an integer greater than 100: "; 
    cin>>n; 

    while(n < 100){
        cout<<"Invalid input!"<<endl; 
        cout<<"Enter a number greater than 100: ";
        cin>>n; 
    }

    cout<<"\nNumber\tSquare\n";
    for(int i = 1; i * i < n; i++){
        cout<<i<<"\t"<<i * i<<endl; 
    }

    return 0; 
}