#include <iostream>
using namespace std; 

int main(){
    int n; 
    int attempts = 0; 
    cout<<"Enter an integer between 1 and 20: "; 
    cin>>n; 

    while(n <= 0 || n > 20){
        attempts++;
        if(attempts >= 10){
            cout<<"Maximum attempts reached. Using 10 as the integer"<<endl; 
            n = 10; 
            break;
        }
        cout<<"Out of range. Enter and integer between 1 and 20: "; 
        cin>>n; 
        
    }
    
    int cube = n * n * n; 
    cout<<"The cube of your integer is "<<cube<<"."<<endl; 

    return 0;
}