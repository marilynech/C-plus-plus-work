#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std; 

int main(){

    string item1, item2, item3; 
    double item1Price, item2Price, item3Price; 
    int item1Quantity, item2Quantity, item3Quantity; 
    double item1Amount, item2Amount, item3Amount; 

    cout<<"Please enter item1: "; 
    cin>>item1; 
    cout<<"Item1 Price? ";
    cin>>item1Price; 
    cout<<"Item1 quantity: ";
    cin>>item1Quantity; 

    item1Amount = item1Price * item1Quantity; 

    cout<<"Please enter item2: ";
    cin>>item2; 
    cout<<"Item2 price? ";
    cin>>item2Price; 
    cout<<"Item2 quantity: ";
    cin>>item2Quantity; 

    item2Amount = item2Price * item2Quantity; 

    cout<<"Please enter item3: "; 
    cin>>item3;
    cout<<"Item3 price? ";
    cin>>item3Price; 
    cout<<"Item3 quantity: ";
    cin>>item3Quantity; 

    item3Amount = item3Price * item3Quantity; 

    double subtotal = item1Amount + item2Amount + item3Amount; 
    double tax = (subtotal * 8.50) / 100;
    double total =  tax + subtotal; 

    //find subtotal by multiplying each items prices with its quantity and adding it up 3 times for each item
    //item name, item price, item quantity 3 cins then find subtotal 
    //then find tax  subtotal * .085 or subtotal * 8.5 / 100
    //then find the total by adding the tax rate with the subtotal 

    //print invoice 
    cout<<"\n+-----------------------------------------------------------+\n";
    cout<<"|                          Invoice                          |";
    cout<<"\n+-----------------------------------------------------------+\n";    
    cout<<"| Items           | Unit Price    |  Quantity  |    Amount  |\n"; 
    cout<<"+-----------------+---------------+------------+------------+"<<endl; 
    printf("| %-15s | $%-12.2f | %-10d | $%.2f      |\n", item1.c_str(), item1Price, item1Quantity, item1Amount);
    printf("| %-15s | $%-12.2f | %-10d | $%.2f      |\n", item2.c_str(), item2Price, item2Quantity, item2Amount); 
    printf("| %-15s | $%-12.2f | %-10d | $%.2f      |\n", item3.c_str(), item3Price, item3Quantity, item3Amount); 
    cout<<"+-----------------------------------------------------------+\n";
    printf("%-40s | ", "|Thank you for your business!");
    printf("%-10s $%.2f|\n", "Subtotal:", subtotal);
    printf("%-40s | ", "|Please come again.");
    printf("%-10s $%.2f |\n", "Tax: ", tax);
    printf("%-40s | ", "| ");
    printf("%-10s $%.2f|\n", "Total: ", total);
    cout<<"+-----------------------------------------------------------+";

    return 0; 

}
