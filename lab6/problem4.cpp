#include <iostream>
using namespace std; 

int main(){
    int price = -1, sum = 0; 
    
    while(price != 0){
        cout<<"Enter the price of an item (enter 0 to stop): ";
        cin>>price; 

        if(price > 0){
            sum += price;
        }
    }

    cout<<"Your checkout total is $"<<sum<<". ";

    if(sum > 100){
        cout<<"That's expensive!"; 
    }

    cout<<endl; 
    return 0;
}