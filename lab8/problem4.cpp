#include <iostream>
using namespace std; 

int main(){
    for(int i = 28; i <= 387; i++){
        cout<<i<<" "; 

        if((i - 28 + 1) % 10 == 0){
            cout<<endl; 
        }
    }   
    return 0; 
}