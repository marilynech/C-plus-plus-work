#include <iostream>
using namespace std; 

int main(){
    
    int categoryOfHurricane;
    int windSpeed; 

    cout<<"Enter a category of hurricane (1 through 5): ";
    cin>>categoryOfHurricane;

    if(categoryOfHurricane == 1){
        cout<<"The wind speed is 111-130 mph";
    }
    else if(categoryOfHurricane == 2){
        cout<<"The wind speed is 96 - 110 mph.";
    }
    else if(categoryOfHurricane == 3){
        cout<<"The wind speed is 111 - 130 mph.";
    }
    else if(categoryOfHurricane == 4){
        cout<<"The wind speed is 131 - 151 mph.";
    }
    else if(categoryOfHurricane == 5){
        cout<<"The wind speed exceeds 155 mph";
    }

    return 0; 
    
}