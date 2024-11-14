#include <iostream>
#include <cstdio>
using namespace std; 

int main(){

    int items;
    double price, cost, discountAmount, totalAmount; 
    double discount = 0.0; 

    cout<<"How many items are bought? ";
    cin>>items;
    cout<<"Enter the price of the item: ";
    cin>>price;

    if(items < 1 || items > 200){
        cout<<"Invalid quantity entered! Terminating the program.."<<endl;
        return 0; 
    }  

    if(items == 200){
        discount = 50.0;
    }
    else if(items >= 100){
        discount = 40.0;
    }
    else if(items >= 50){
        discount = 30.0;
    }
    else if(items >= 20){
        discount = 20.0;
    }
    else if(items >= 10){
        discount = 10.0; 
    }
    else{
        discount = 0.0; 
    }
    
    cost = items * price; 
    discountAmount = cost * (discount / 100.0);
    totalAmount = cost - discountAmount; 

    //cout<<fixed<<setprecision(2);
    cout<<"+-------------------+---------------+\n";
    printf("| %-17s | %13d |\n", "Quantity", items);
    printf("| %-17s | $%12.2f |\n", "Price", price);
    printf("| %-17s | $%12.2f |\n", "Order Total", cost);
    printf("| %-17s | %12.0f%% |\n", "Discount", discount);
    printf("| %-17s | $%12.2f |\n", "Discount Amount", discountAmount);
    printf("| %-17s | $%12.2f |\n", "Amount Due", totalAmount);
    cout<<"+-------------------+---------------+\n";

return 0; 
}