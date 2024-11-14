#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
//all arrays start from zero bc of the index 
   // int arr[10]; 
    //int size = sizeof(arr) / sizeof(arr[0]); 
    //cout<< size;
    //stores numbers 1 through 10 start at0 
    //for(int i = 0; i < size; i++){
      //  cout<<arr[i]<<endl;
      //enchanced for loop

      //for(int i : arr)
        //cout<< i <<endl;  
    int size = 10;
    int arr[size];

    for(int i = 0; i < size; i++){
        cout<<"Enter 10 integers: "; 
        cin>>arr[i]; 
    } 

    for(int i : arr){
        cout<< i << "\t"; 
    }

    //add all nums in array and divide by 10 or the size 
    double sum = 0;
    for(int i : arr){
        sum += i; 
    }

    double average = sum / size; 
    cout<<"Average of the integers in array"<<average<<endl; 

    double sum = 0, count = 0; 
    for(int i : arr){
        if(i > average){
            sum+=i;
            count++;
        }
    }

    double b = sum / count; 
    cout<<b<<endl; 
}