#include <iostream>
using namespace std; 

int main(){
    int threePointers;
    int twoPointers; 

    cout<<"How many 3-pointers? "; 
    cin>>threePointers; 
    cout<<"How many 2-pointers? "; 
    cin>>twoPointers; 

    int totalPointsScored = (threePointers * 3) + (twoPointers * 2); 
    cout<<"Total points scored: "<<totalPointsScored<<endl; 
    
    return 0;
}