#include <iostream>
using namespace std; 

int main(){
    int rolls; 
    cout<<"Enter the number of die rolls: "; 
    cin>>rolls; 

    if(rolls <= 0){
        cout<<"Not playing games."<<endl; 
        return 0; 
    }
    
    srand(time(0));
    
    int onesRolled = 0; //count for num of ones rolled
    for(int i = 1; i <= rolls; ++i){
        int rollValue = rand() % 6 + 1; //num between 1 and 6 
        cout<<"Roll "<<i<<": "<<rollValue<<endl;

        if(rollValue == 1){ //check if roll is one
            ++onesRolled;//onesRolled++ ? 
        }
    }

    cout<<"Total number of ones rolled "<<onesRolled<<"."<<endl; 

    return 0; 

}