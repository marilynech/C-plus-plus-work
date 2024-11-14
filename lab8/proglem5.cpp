#include <iostream>
using namespace std; 

int main(){
//start at 1 then go up by 2 while <=n outside loop 
//i * j outside loops updates i cout<<endl; 
//inside loop updates j print out i * j 
    int n; 
    cout<<"Enter an odd integer from 5 to 25: "; 
    cin>>n; 

    while(n < 5 || n > 25 || n % 2 == 0){
        cout<<"Invalid input! Enter an odd integer from 5 to 25: "; 
        cin>>n; 
    }

    for(int i = 1; i <= n; i += 2){
        for(int j = 1; j <= n; j +=2){
            cout<<i * j; 
        }
        cout<<endl; 
    }
    return 0; 
}