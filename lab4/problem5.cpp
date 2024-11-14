#include <iostream>
using namespace std;

int main(){

    int month; 
    cout<<"Enter a month (1 for January, 2 for February, etc): ";
    cin>>month; 

    //use switch for each month can be a case 
    switch(month){
        case 1:
        case 3:
        case 5: 
        case 7:
        case 8:
        case 10: 
        case 12: //months with 31 days
            cout<<"31 days"<<endl; 
            break;
        case 4:
        case 6:
        case 9:
        case 11: //month with 30 dyas
            cout<<"30 days"<<endl; 
            break;
        case 2: //FEB 
            cout<<"28 or 29 days"<<endl; 
            break;
        default:
        cout<<"Try again invalid month entered.";
        break; 
    }

    return 0; 
    
}