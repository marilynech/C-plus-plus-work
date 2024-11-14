#include <iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter a number between 1 and 100: ";
    cin>>n; 

    while(n <= 0 || n > 100){
        cout<<"Invalid input!"<<endl; 
        cout<<"Enter a number between 1 and 100: ";
        cin>>n; 
    }

    cout<<"The first 20 multiples of "<<n<<" are: ";

    for(int i = 1; i <= 20; i++){
        cout<<n * i<<" ";
    }
    cout<<endl; 

    return 0; 
}