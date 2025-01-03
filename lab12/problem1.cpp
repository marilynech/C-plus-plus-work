#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
//all arrays start from zero bc of the index 
//enchanced for loop
    //for(int i : arr)
    //cout<< i <<endl;  
    int size = 10;
    int arr[size];

    cout<<"Enter 10 integers: "<<endl; 
    
    for(int i = 0; i < size; i++){
        cin>>arr[i]; 
    } 

    //for(int i : arr){
       // cout<< i << " "; 
    //}
    //add all nums in array and divide by 10 or the size 
    double sum = 0;
    for(int i : arr){
        sum += i; 
    }

    double average = sum / size; 
    cout<<"Average of the integers in array: "<<average<<endl; 

    sum = 0; 
    int count = 0; 
    for(int i : arr){
        if(i >= average){
            sum+=i;
            count++;
        }
    }

    double b = (count > 0) ? (sum / count) : 0; 
    cout<<"Average of the integers greater than or equal to the overall average of "<<average<<
    " is: "<<b<<endl; 

    return 0; 
}