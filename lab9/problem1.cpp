#include <iostream> 
#include <ctime>

using namespace std; 

int main(){
    srand(time(0));
    //double r = rand() % 6; //dice roll limit to 6 any num mod 6 = certain outputs 0,1,2,3,4,5 outputs 
    //adjust to make minimum 1 and maximum 6 
    int n = rand() % n + 1; 
    
    cout<<"Enter an integer greater than or equal to 10: "; 
    cin>>n; 
    
}