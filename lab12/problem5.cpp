//only print negative int in order
//part d use enchanced if neg print it 
// for e go backwards 

#include <iostream> 
using namespace std; 

int main(){
    int n; 
    int numbers[100]; 
    
    cout<<"Enter a postive integer (at most 100): ";
    cin>>n; 

    if(n < 1 || n > 100){
        cout<<"Invalid input."<<endl; 
        return 0;
    }

    cout<<"Enter "<<n<<" integers: ";
    for(int i = 0; i < n; i++){
        cin>>numbers[i]; 
    }

    cout<<"Negatives: ";
    for(int i = 0; i < n; i++){
        if(numbers[i] < 0){
            cout<<numbers[i]<<" ";
        }
    }
    cout<<endl; 

    cout<<"Positive integers in reverse order including 0: "; 
    for(int i = n -1; i >= 0; i--){
        if(numbers[i] >= 0){
            cout<<numbers[i]<<" ";
        }
    }

    cout<<endl; 

    return 0;
}