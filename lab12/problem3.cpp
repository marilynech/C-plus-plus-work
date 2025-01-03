#include <iostream>
#include <string> 
using namespace std; 

int main(){
//use a random num n from user and thats the size of string array then run a loop from o to n-1 take that many
//words and store them in an array and go backwards you have to start at int i = n - 1 and end at >= 0 
//then do i-- 
    string data[100]; 
    int n;

    cout<<"How many words (between 1 and 100): "; 
    cin>>n; 

    if(n <= 0 || n > 100){
        cout<<"Invalid input."<<endl; 
        return 0; 
    }
    
    cout<<"Enter "<<n<<" word(s) below: "<<endl; 
    for(int i = 0; i < n; i++){
        cin>>data[i]; 
    }

    cout<<"I will now print your word(s) in reverse order: "<<endl; 
    for(int i = (n - 1); i >= 0; i--){
        cout<<data[i]; 
        if(i > 0) cout<<" "; 
    }

    cout<<endl;  

    return 0; 
}