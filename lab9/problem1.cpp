#include <iostream> 
#include <ctime>

using namespace std; 

int main(){
    srand(time(0));
    int n; 
    //double r = rand() % 6; //dice roll limit to 6 any num mod 6 = certain outputs 0,1,2,3,4,5 outputs 
    //adjust to make minimum 1 and maximum 6 
    cout<<"Enter an integer greater than or equal to 10: "; 
    cin>>n; 

    while(n < 10){
        cout<<"Invalid input! Try again: "; 
        cin>>n; 
    }

    int randomNum = rand() % n + 1; 
    
    cout<<"Random integer between 1 and "<<n<<" is "<<randomNum<<"."<<endl; 

    return 0; 
}