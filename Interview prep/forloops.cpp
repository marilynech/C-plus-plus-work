#include <iostream>
using namespace std; 

int main(){

//print nums 1-5
   /* for(int i = 1; i <=5; i++){
        cout<< i << " "; 
    }*/
//output : 1 2 3 4 5 

//display a text 5 times
    for(int i = 1; i <=5; i++){
        cout<<"Hello World!"<<endl;
    }

//find the sum of the first n natural numbers positive integers such as 1,2,3,..n are known as natural numbers 

    int num, sum; 
    sum = 0; 

    cout<<"Enter a positive integer: ";
    cin>>num; 

    for(int i = 1; i <= num; ++i){
        sum += i; 
    }

    cout<<"Sum = "<<sum<<endl; 

//range based for loops: works with arrays and vectors 
//for(variable: collection){ }

int numArray[] = {1,2,3,4,5,6,7,8,9,10}; 

for(int n : numArray){
    cout<<n<< " "; 
}

//output: 1 2 3 4 5 6 7 8 9 10

//C++ infinite for loop 

for(int i = 1; i > 0; i++){
    //block of code
}
  return 0;
}